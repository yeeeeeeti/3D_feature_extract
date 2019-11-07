//-----------------------------------------------------------------------------
// Created on: 24 August 2017
//-----------------------------------------------------------------------------
// Copyright (c) 2017, Sergey Slyadnev
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of the copyright holder(s) nor the
//      names of all contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

// cmdEngine includes
#include <cmdEngine.h>

// asiUI includes
#include <asiUI_DialogGeomDef.h>

// asiEngine includes
#include <asiEngine_Part.h>

// asiTcl includes
#include <asiTcl_PluginMacro.h>

// asiAlgo includes
#include <asiAlgo_MeshOBB.h>
#include <asiAlgo_MeshOffset.h>
#include <asiAlgo_Utils.h>

#if defined USE_MOBIUS
  // Mobius includes
  #include <mobius/cascade_BSplineCurve.h>
  #include <mobius/geom_FairBCurve.h>
#endif

// OCCT includes
#include <BRep_Builder.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepOffset.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <BRepOffset_MakeSimpleOffset.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <Geom_Plane.hxx>
#include <gp_Pln.hxx>
#include <HLRBRep_Algo.hxx>
#include <HLRBRep_PolyAlgo.hxx>
#include <HLRBRep_PolyHLRToShape.hxx>
#include <Precision.hxx>
#include <TopoDS.hxx>

//-----------------------------------------------------------------------------

int ENGINE_OffsetShell(const Handle(asiTcl_Interp)& interp,
                       int                          argc,
                       const char**                 argv)
{
  if ( argc > 7 || argc < 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get part shape
  TopoDS_Shape
    partShape = Handle(asiEngine_Model)::DownCast( interp->GetModel() )->GetPartNode()->GetShape();

  // Get offset value
  const double offsetVal = atof(argv[1]);

  // Check whether topology of the result should be preserved
  bool isSimple = false, isSolid = false, isKeep = false;
  if ( argc > 2 )
  {
    for ( int k = 2; k < argc; ++k )
    {
      if ( !isSimple && interp->IsKeyword(argv[k], "simple") )
        isSimple = true;

      if ( !isSolid && interp->IsKeyword(argv[k], "solid") )
        isSolid = true;

      if ( !isKeep && interp->IsKeyword(argv[k], "keep") )
        isKeep = true;
    }
  }

  // Take tolerance for suppressing singularities
  double toler = 0.0;
  TCollection_AsciiString tolerStr;
  //
  if ( interp->GetKeyValue(argc, argv, "toler", tolerStr) )
  {
    toler = tolerStr.RealValue();

    interp->GetProgress().SendLogMessage(LogInfo(Normal) << "Passed tolerance value %1."
                                                         << toler);
  }

  // Make offset
  TopoDS_Shape offsetShape;
  if ( isSimple )
  {
    // Initialize
    BRepOffset_MakeSimpleOffset mkOffset;
    mkOffset.Initialize(partShape, offsetVal);
    mkOffset.SetBuildSolidFlag(isSolid);
    //
    if ( toler )
      mkOffset.SetTolerance(toler);

    // Perform
    mkOffset.Perform();
    // 
    if ( !mkOffset.IsDone() )
    {
      interp->GetProgress().SendLogMessage(LogErr(Normal) << "Simple offset not done.");
      return TCL_OK;
    }
    offsetShape = mkOffset.GetResultShape();
  }
  else
  {
    BRepOffset_MakeOffset mkOffset;
    mkOffset.Initialize(partShape, offsetVal, 1.0e-3, BRepOffset_Skin, true, false, GeomAbs_Arc, isSolid);
    //
    if ( isSolid )
      mkOffset.MakeThickSolid();
    else
      mkOffset.MakeOffsetShape();
    //
    if ( !mkOffset.IsDone() )
    {
      interp->GetProgress().SendLogMessage(LogErr(Normal) << "Offset not done.");
      return TCL_OK;
    }
    offsetShape = mkOffset.Shape();
  }

  TopoDS_Shape resultShape;

  // If this flag is enabled, the initial geometry is not substituted
  if ( isKeep )
  {
    TopoDS_Compound resComp;
    BRep_Builder().MakeCompound(resComp);
    //
    BRep_Builder().Add(resComp, partShape);
    BRep_Builder().Add(resComp, offsetShape);
    //
    resultShape = resComp;
  }
  else
    resultShape = offsetShape;

  // Modify Data Model
  cmdEngine::model->OpenCommand();
  {
    asiEngine_Part(cmdEngine::model).Update(resultShape);
  }
  cmdEngine::model->CommitCommand();

  // Update UI
  if ( cmdEngine::cf && cmdEngine::cf->ViewerPart )
    cmdEngine::cf->ViewerPart->PrsMgr()->Actualize( cmdEngine::model->GetPartNode() );

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_OffsetTess(const Handle(asiTcl_Interp)& interp,
                      int                          argc,
                      const char**                 argv)
{
  if ( argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get mesh.
  Handle(asiData_TessNode) tessNode = cmdEngine::model->GetTessellationNode();
  //
  if ( tessNode.IsNull() || !tessNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Tessellation Node is null or inconsistent.");
    return TCL_ERROR;
  }
  //
  Handle(ActData_Mesh) mesh = tessNode->GetMesh();

  // Get offset value.
  const double offsetVal = atof(argv[1]);

  // Perform mesh offset.
  asiAlgo_MeshOffset meshOffset( mesh, interp->GetProgress(), interp->GetPlotter() );
  meshOffset.Perform(offsetVal);

  // Update Data Model.
  cmdEngine::model->OpenCommand(); // tx start
  {
    tessNode->SetMesh( meshOffset.GetResult() );
  }
  cmdEngine::model->CommitCommand(); // tx commit

  // Update UI.
  cmdEngine::cf->ViewerPart->PrsMgr()->Actualize(tessNode.get(), false, false);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeEdge(const Handle(asiTcl_Interp)& interp,
                    int                          argc,
                    const char**                 argv)
{
  if ( argc != 3 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Curve Node.
  Handle(asiData_IVCurveNode)
    node = Handle(asiData_IVCurveNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  if ( node.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find a Curve object with name %1." << argv[2]);
    return TCL_OK;
  }

  // Get geometry of a curve.
  double f, l;
  Handle(Geom_Curve) curve = node->GetCurve(f, l);
  //
  if ( curve.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Curve in question is null.");
    return TCL_OK;
  }

  // Make edge.
  TopoDS_Edge E = BRepBuilderAPI_MakeEdge(curve);

  // Draw in IV.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], E, Color_Red, 1.0, true);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeFace(const Handle(asiTcl_Interp)& interp,
                    int                          argc,
                    const char**                 argv)
{
  if ( argc != 3 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Surface Node.
  Handle(asiData_IVSurfaceNode)
    node = Handle(asiData_IVSurfaceNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  if ( node.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find a Surface object with name %1." << argv[2]);
    return TCL_OK;
  }

  // Get geometry of a surface.
  Handle(Geom_Surface) surface = node->GetSurface();
  //
  if ( surface.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Surface in question is null.");
    return TCL_OK;
  }

  // Make face.
  TopoDS_Face F = BRepBuilderAPI_MakeFace( surface, Precision::Confusion() );

  // Draw in IV.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], F, Color_White, 1.0, false);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeShell(const Handle(asiTcl_Interp)& interp,
                     int                          argc,
                     const char**                 argv)
{
  if ( argc < 3 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  TopoDS_Shell result;
  BRep_Builder BB;
  BB.MakeShell(result);

  // Add faces to the resulting shell.
  for ( int k = 2; k < argc; ++k )
  {
    // Get Topology Item Node.
    Handle(asiData_IVTopoItemNode)
      node = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[k]) );
    //
    if ( node.IsNull() )
    {
      interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find object with name %1." << argv[k]);
      return TCL_OK;
    }

    // Get item shape.
    TopoDS_Shape itemShape = node->GetShape();
    //
    if ( itemShape.ShapeType() != TopAbs_FACE )
    {
      interp->GetProgress().SendLogMessage(LogWarn(Normal) << "Object %1 is not face. Skipped." << argv[k]);
      continue;
    }
    //
    TopoDS_Face itemFace = TopoDS::Face(itemShape);

    // Add face to the shell being constructed.
    BB.Add(result, itemFace);
  }

  // Draw in IV.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], result, Color_White, 1.0, false);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeCompound(const Handle(asiTcl_Interp)& interp,
                        int                          argc,
                        const char**                 argv)
{
  if ( argc < 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  TopoDS_Compound result;
  BRep_Builder BB;
  BB.MakeCompound(result);

  // Add shapes to the resulting compound.
  for ( int k = 2; k < argc; ++k )
  {
    // Get Topology Item Node.
    Handle(asiData_IVTopoItemNode)
      node = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[k]) );
    //
    if ( node.IsNull() )
    {
      interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find object with name %1." << argv[k]);
      return TCL_OK;
    }

    // Get item shape.
    TopoDS_Shape itemShape = node->GetShape();

    // Add face to the shell being constructed.
    BB.Add(result, itemShape);
  }

  // Draw in IV.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], result, Color_White, 1.0, false);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_AddSubShape(const Handle(asiTcl_Interp)& interp,
                       int                          argc,
                       const char**                 argv)
{
  if ( argc != 3 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get parent item Node.
  Handle(asiData_IVTopoItemNode)
    parentNode = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[1]) );
  //
  if ( parentNode.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find object with name %1." << argv[1]);
    return TCL_OK;
  }

  // Get child item Node.
  Handle(asiData_IVTopoItemNode)
    childNode = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  if ( childNode.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find object with name %1." << argv[2]);
    return TCL_OK;
  }

  // Get parent shape.
  TopoDS_Shape parentShape = parentNode->GetShape();

  // Get child shape.
  TopoDS_Shape childShape = childNode->GetShape();

  // Add sub-shape.
  BRep_Builder().Add(parentShape, childShape);

  // Draw in IV.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], parentShape, Color_White, 1.0, false);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeCurve(const Handle(asiTcl_Interp)& interp,
                    int                          argc,
                    const char**                 argv)
{
  if ( argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Part Node to access the selected edge.
  Handle(asiData_PartNode) partNode = cmdEngine::model->GetPartNode();
  //
  if ( partNode.IsNull() || !partNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Part Node is null or ill-defined.");
    return TCL_OK;
  }
  //
  const TopTools_IndexedMapOfShape&
    subShapes = partNode->GetAAG()->RequestMapOfSubShapes();

  // Curve Node is expected.
  Handle(asiData_CurveNode) curveNode = partNode->GetCurveRepresentation();
  //
  if ( curveNode.IsNull() || !curveNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Curve Node is null or ill-defined.");
    return TCL_OK;
  }

  // Get ID of the selected edge.
  const int edgeIdx = curveNode->GetSelectedEdge();
  //
  if ( edgeIdx <= 0 )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Please, select edge first.");
    return TCL_OK;
  }

  // Get host curve of the selected edge.
  const TopoDS_Shape& edgeShape = subShapes(edgeIdx);
  //
  if ( edgeShape.ShapeType() != TopAbs_EDGE )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Unexpected topological type of the selected edge.");
    return TCL_OK;
  }
  //
  double f, l;
  Handle(Geom_Curve) curve = BRep_Tool::Curve( TopoDS::Edge(edgeShape), f, l );

  // Set result.
  interp->GetPlotter().REDRAW_CURVE(argv[1], curve, Color_White);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeSurf(const Handle(asiTcl_Interp)& interp,
                    int                          argc,
                    const char**                 argv)
{
  if ( argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Part Node to access the selected face.
  Handle(asiData_PartNode) partNode = cmdEngine::model->GetPartNode();
  //
  if ( partNode.IsNull() || !partNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Part Node is null or ill-defined.");
    return TCL_OK;
  }
  //
  const TopTools_IndexedMapOfShape&
    subShapes = partNode->GetAAG()->RequestMapOfSubShapes();

  // Surface Node is expected.
  Handle(asiData_SurfNode) surfNode = partNode->GetSurfaceRepresentation();
  //
  if ( surfNode.IsNull() || !surfNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Surface Node is null or ill-defined.");
    return TCL_OK;
  }

  // Get ID of the selected face.
  const int faceIdx = surfNode->GetSelectedFace();
  //
  if ( faceIdx <= 0 )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Please, select face first.");
    return TCL_OK;
  }

  // Get host surface of the selected face.
  const TopoDS_Shape& faceShape = subShapes(faceIdx);
  //
  if ( faceShape.ShapeType() != TopAbs_FACE )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Unexpected topological type of the selected face.");
    return TCL_OK;
  }
  //
  Handle(Geom_Surface) surf = BRep_Tool::Surface( TopoDS::Face(faceShape) );

  // Set result.
  interp->GetPlotter().REDRAW_SURFACE(argv[1], surf, Color_White);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_InterpolatePoints(const Handle(asiTcl_Interp)& interp,
                             int                          argc,
                             const char**                 argv)
{
  if ( argc != 4 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Points Node.
  Handle(asiData_IVPointSetNode)
    pointsNode = Handle(asiData_IVPointSetNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  if ( pointsNode.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find Points Node with name %1." << argv[2]);
    return TCL_OK;
  }

  // Get degree.
  const int degree = atoi(argv[3]);

  // Get Cartesian points to interpolate.
  Handle(asiAlgo_BaseCloud<double>) ptsCloud = pointsNode->GetPoints();

  // Interpolate.
  Handle(Geom_BSplineCurve) interpolant;
  //
  if ( !asiAlgo_Utils::InterpolatePoints(ptsCloud, degree, interpolant) )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Interpolation failed.");
    return TCL_OK;
  }

  // Set result.
  interp->GetPlotter().REDRAW_CURVE(argv[1], interpolant, Color_Red);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_BOPCut(const Handle(asiTcl_Interp)& interp,
                  int                          argc,
                  const char**                 argv)
{
  if ( argc != 4 && argc != 5 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get topological items which are the operands.
  Handle(asiData_IVTopoItemNode)
    topoItem1 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  Handle(asiData_IVTopoItemNode)
    topoItem2 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[3]) );
  //
  if ( topoItem1.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[2]);
    return TCL_OK;
  }
  //
  if ( topoItem2.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[3]);
    return TCL_OK;
  }

  // Read fuzzy value.
  double fuzz = 0.0;
  if ( argc == 5 )
    fuzz = atof(argv[4]);

  // Cut.
  TopoDS_Shape
    result = asiAlgo_Utils::BooleanCut( topoItem1->GetShape(),
                                        topoItem2->GetShape(), fuzz );
  //
  interp->GetPlotter().REDRAW_SHAPE(argv[1], result);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_BOPFuse(const Handle(asiTcl_Interp)& interp,
                   int                          argc,
                   const char**                 argv)
{
  if ( argc != 4 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get topological items which are the operands.
  Handle(asiData_IVTopoItemNode)
    topoItem1 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  Handle(asiData_IVTopoItemNode)
    topoItem2 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[3]) );
  //
  if ( topoItem1.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[2]);
    return TCL_OK;
  }
  //
  if ( topoItem2.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[3]);
    return TCL_OK;
  }

  // Put all arguments to the list.
  TopTools_ListOfShape arguments;
  arguments.Append( topoItem1->GetShape() );
  arguments.Append( topoItem2->GetShape() );

  // Fuse.
  TopoDS_Shape fused = asiAlgo_Utils::BooleanFuse(arguments);
  //
  interp->GetPlotter().REDRAW_SHAPE(argv[1], fused);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_FuseGen(const Handle(asiTcl_Interp)& interp,
                   int                          argc,
                   const char**                 argv)
{
  if ( argc != 4 && argc != 5 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get topological items which are the operands.
  Handle(asiData_IVTopoItemNode)
    topoItem1 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[2]) );
  //
  Handle(asiData_IVTopoItemNode)
    topoItem2 = Handle(asiData_IVTopoItemNode)::DownCast( cmdEngine::model->FindNodeByName(argv[3]) );
  //
  if ( topoItem1.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[2]);
    return TCL_OK;
  }
  //
  if ( topoItem2.IsNull() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Cannot find topological object with name %1." << argv[3]);
    return TCL_OK;
  }

  // Fuzzy value.
  const double fuzz = (argc == 5 ? Atof(argv[4]) : 0.0);

  // Put all arguments to the list.
  TopTools_ListOfShape arguments;
  arguments.Append( topoItem1->GetShape() );
  arguments.Append( topoItem2->GetShape() );

  // Fuse.
  TopoDS_Shape fused = asiAlgo_Utils::BooleanGeneralFuse(arguments, fuzz);
  //
  interp->GetPlotter().REDRAW_SHAPE(argv[1], fused);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_DefineGeom(const Handle(asiTcl_Interp)& interp,
                      int                          argc,
                      const char**                 argv)
{
  if ( argc != 1 && argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  if ( !cmdEngine::cf )
    return TCL_OK;

  asiUI_DialogGeomDef* pDlg = new asiUI_DialogGeomDef( cmdEngine::model,
                                                       interp->GetProgress(),
                                                       interp->GetPlotter() );

  // Populate with data.
  if ( argc == 2 )
  {
    Handle(ActAPI_INode) node = cmdEngine::model->FindNodeByName(argv[1]);
    //
    if ( !node.IsNull() && node->IsWellFormed() )
      pDlg->Initialize(node);
  }

  pDlg->show();

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeBox(const Handle(asiTcl_Interp)& interp,
                   int                          argc,
                   const char**                 argv)
{
  if ( argc != 2 && argc != 8 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Init position.
  gp_Pnt pos;
  //
  if ( argc >= 5 )
  {
    pos.SetX( atof(argv[2]) );
    pos.SetY( atof(argv[3]) );
    pos.SetZ( atof(argv[4]) );
  }

  // Init dimensions.
  double dX = 1.0, dY = 1.0, dZ = 1.0;
  //
  if ( argc >= 8 )
  {
    dX = atof(argv[5]);
    dY = atof(argv[6]);
    dZ = atof(argv[7]);
  }

  // Create box.
  TopoDS_Shape box = BRepPrimAPI_MakeBox( pos, pos.XYZ() + gp_XYZ(dX, dY, dZ) );
  interp->GetPlotter().REDRAW_SHAPE(argv[1], box);
  interp->GetProgress().SendLogMessage(LogInfo(Normal) << "Box created.");

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_HLR(const Handle(asiTcl_Interp)& interp,
               int                          argc,
               const char**                 argv)
{
  if ( argc != 8 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  /* =============
   *  Preparation
   * ============= */

  // Get Part Node to access the selected face.
  Handle(asiData_PartNode) partNode = cmdEngine::model->GetPartNode();
  //
  if ( partNode.IsNull() || !partNode->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Part Node is null or ill-defined.");
    return TCL_OK;
  }
  //
  TopoDS_Shape partShape = partNode->GetShape();

  // Get bounding box diagonal to trim projection plane for nice visualization.
  double xmin, ymin, zmin, xmax, ymax, zmax;
  asiAlgo_Utils::Bounds(partShape, xmin, ymin, zmin, xmax, ymax, zmax);
  //
  const double diag = gp_Pnt(xmax, ymax, zmax).Distance( gp_Pnt(xmin, ymin, zmin) );

  // Read position of the projection plane.
  gp_Pnt pos;
  //
  pos.SetX( atof(argv[2]) );
  pos.SetY( atof(argv[3]) );
  pos.SetZ( atof(argv[4]) );

  // Read orientation of projection plane.
  const double dX = atof(argv[5]);
  const double dY = atof(argv[6]);
  const double dZ = atof(argv[7]);

  // Prepare projection plane and its transformation.
  gp_Ax2 axes( pos, gp_Dir(dX, dY, dZ) );
  gp_Pln projPlane(axes);
  interp->GetPlotter().REDRAW_SURFACE("projPlane", new Geom_Plane(projPlane), diag, diag, Color_Blue, 0.1);
  //
  gp_Trsf T;
  T.SetTransformation(axes);
  T.Invert();

  /* =======================
   *  Perform HLR algorithm
   * ======================= */

  // Prepare projector.
  HLRAlgo_Projector projector(axes);

  // Prepare polygonal HLR algorithm which is known to be more reliable than
  // the "curved" version of HLR.
  Handle(HLRBRep_PolyAlgo) polyAlgo = new HLRBRep_PolyAlgo;
  // 
  polyAlgo->Projector(projector);
  polyAlgo->Load(partShape);
  polyAlgo->Update();

  // Create topological entities.
  HLRBRep_PolyHLRToShape HLRToShape;
  HLRToShape.Update(polyAlgo);

  /* ==========
   *  Finalize
   * ========== */

  // Prepare one compound shape to store HLR results.
  TopoDS_Compound hlrShape;
  BRep_Builder().MakeCompound(hlrShape);

  // Add visible edges.
  TopoDS_Shape vcompound = HLRToShape.VCompound();
  if ( !vcompound.IsNull() )
    BRep_Builder().Add(hlrShape, vcompound);
  //
  vcompound = HLRToShape.OutLineVCompound();
  if ( !vcompound.IsNull() )
    BRep_Builder().Add(hlrShape, vcompound);

  // Draw the result.
  interp->GetPlotter().REDRAW_SHAPE(argv[1], hlrShape.Moved(T), Color_Red);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_MakeFillet(const Handle(asiTcl_Interp)& interp,
                      int                          argc,
                      const char**                 argv)
{
  if ( argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  Handle(asiEngine_Model)
    M = Handle(asiEngine_Model)::DownCast( interp->GetModel() );

  // Get radius.
  const double R = atof(argv[1]);

  // Get part.
  Handle(asiData_PartNode) partNode = M->GetPartNode();
  TopoDS_Shape             partSh   = partNode->GetShape();

  // Attempt to get the highlighted sub-shapes.
  TColStd_PackedMapOfInteger edgeIds;
  //
  if ( cmdEngine::cf && cmdEngine::cf->ViewerPart )
  {
    asiEngine_Part PartAPI( M,
                            cmdEngine::cf->ViewerPart->PrsMgr(),
                            interp->GetProgress(),
                            interp->GetPlotter() );
    //
    PartAPI.GetHighlightedEdges(edgeIds);
  }

  // Initialize blending operator.
  BRepFilletAPI_MakeFillet mkFillet(partSh);
  //
  for ( TColStd_MapIteratorOfPackedMapOfInteger eit(edgeIds); eit.More(); eit.Next() )
  {
    const int edgeId = eit.Key();

    // Get edge to blend.
    const TopoDS_Edge&
      edge = TopoDS::Edge( partNode->GetAAG()->RequestMapOfEdges()(edgeId) );

    // Add edge to the blending operator.
    mkFillet.Add(R, edge);
  }

  // Perform blending.
  mkFillet.Build();
  //
  if ( !mkFillet.IsDone() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Blending not done.");
    return TCL_OK;
  }

  // Get result and update part.
  cmdEngine::model->OpenCommand();
  {
    asiEngine_Part(cmdEngine::model).Update( mkFillet.Shape() );
  }
  cmdEngine::model->CommitCommand();

  // Update UI
  if ( cmdEngine::cf && cmdEngine::cf->ViewerPart )
    cmdEngine::cf->ViewerPart->PrsMgr()->Actualize(partNode);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

int ENGINE_BuildTriangulationOBB(const Handle(asiTcl_Interp)& interp,
                                 int                          argc,
                                 const char**                 argv)
{
  if ( argc != 2 )
  {
    return interp->ErrorOnWrongArgs(argv[0]);
  }

  // Get Triangulaion.
  Handle(asiData_TriangulationNode) tris_n = cmdEngine::model->GetTriangulationNode();
  //
  if ( tris_n.IsNull() || !tris_n->IsWellFormed() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Triangulation is null.");
    return TCL_ERROR;
  }
  //
  Handle(Poly_Triangulation) triangulation = tris_n->GetTriangulation();

  // Build OBB.
  asiAlgo_MeshOBB mkOBB(triangulation);
  //
  if ( !mkOBB.Perform() )
  {
    interp->GetProgress().SendLogMessage(LogErr(Normal) << "Operation failed.");
    return TCL_ERROR;
  }

  // Get result as a solid.
  TopoDS_Solid obb = mkOBB.GetResultBox();
  //
  interp->GetPlotter().REDRAW_SHAPE(argv[1], obb, Color_Yellow, 1.0, true);

  return TCL_OK;
}

//-----------------------------------------------------------------------------

void cmdEngine::Commands_Modeling(const Handle(asiTcl_Interp)&      interp,
                                  const Handle(Standard_Transient)& data)
{
  cmdEngine_NotUsed(data);
  //
  static const char* group = "cmdEngine";

  //-------------------------------------------------------------------------//
  interp->AddCommand("offset-shell",
    //
    "offset-shell offset [-simple] [-solid] [-keep] [-toler <val>]\n"
    "\t Offsets part (it should be a topological shell) on the given offset\n"
    "\t value. Offsetting is performed in the direction of face normals. If the\n"
    "\t option '-simple' is passed, this operation will attempt to preserve\n"
    "\t the topology of the base shell. If the option '-solid' is passed, this\n"
    "\t operation will build a solid instead of an offset shell. If the option\n"
    "\t '-keep' is passed, the original part is not substituted with the offset\n"
    "\t shape, and the offset is added to the part. If the option '-toler' is\n"
    "\t passed and '-simple' key is used, an optional tolerance for suppressing\n"
    "\t singularities on triangular surface patches is used.",
    //
    __FILE__, group, ENGINE_OffsetShell);

  //-------------------------------------------------------------------------//
  interp->AddCommand("offset-tess",
    //
    "offset-tess offset\n"
    "\t Offsets mesh nodes in directions of their norms.",
    //
    __FILE__, group, ENGINE_OffsetTess);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-edge",
    //
    "make-edge result curveName\n"
    "\t Creates edge from a curve. The <curveName> variable should exist\n"
    "\t as a Curve object in the scene graph of imperative plotter.",
    //
    __FILE__, group, ENGINE_MakeEdge);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-face",
    //
    "make-face result surfaceName\n"
    "\t Creates face from a surface. The <surfaceName> variable should exist\n"
    "\t as a Surface object in the scene graph of imperative plotter.",
    //
    __FILE__, group, ENGINE_MakeFace);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-shell",
    //
    "make-shell result face1 [face2 [...]]\n"
    "\t Creates shell from the passed faces.",
    //
    __FILE__, group, ENGINE_MakeShell);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-compound",
    //
    "make-compound result [shape1 [shape2 [...]]]\n"
    "\t Creates compound from the passed shapes.",
    //
    __FILE__, group, ENGINE_MakeCompound);

  //-------------------------------------------------------------------------//
  interp->AddCommand("add-subshape",
    //
    "add-subshape parent child\n"
    "\t Adds <child> to <parent>.",
    //
    __FILE__, group, ENGINE_AddSubShape);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-curve",
    //
    "make-curve curveName\n"
    "\t Creates a curve from the selected edge.",
    //
    __FILE__, group, ENGINE_MakeCurve);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-surf",
    //
    "make-surf surfName\n"
    "\t Creates a surface from the selected face.",
    //
    __FILE__, group, ENGINE_MakeSurf);

  //-------------------------------------------------------------------------//
  interp->AddCommand("interpolate-points",
    //
    "interpolate-points curveName pointsName deg\n"
    "\t Creates a curve from the passed point series by interpolation.",
    //
    __FILE__, group, ENGINE_InterpolatePoints);

  //-------------------------------------------------------------------------//
  interp->AddCommand("bop-cut",
    //
    "bop-cut result op1 op2 [fuzz]\n"
    "\t Cuts <op2> from <op1> using Boolean Cut operation.",
    //
    __FILE__, group, ENGINE_BOPCut);

  //-------------------------------------------------------------------------//
  interp->AddCommand("bop-fuse",
    //
    "bop-fuse result op1 op2\n"
    "\t Fuses the passed two operands using Boolean Fuse operation.",
    //
    __FILE__, group, ENGINE_BOPFuse);

  //-------------------------------------------------------------------------//
  interp->AddCommand("fuse-gen",
    //
    "fuse-gen result op1 op2 [fuzz]\n"
    "\t Fuses the passed two operands using Boolean General Fuse operation.\n"
    "\t It is possible to affect the fusion tolerance with <fuzz> argument.",
    //
    __FILE__, group, ENGINE_FuseGen);

  //-------------------------------------------------------------------------//
  interp->AddCommand("define-geom",
    //
    "define-geom [name]\n"
    "\t Opens geometry definition dialog.",
    //
    __FILE__, group, ENGINE_DefineGeom);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-box",
    //
    "make-box name [posX posY posZ dX dY dZ]\n"
    "\t Creates axis-aligned box solid with min corner at <posX, posY, posZ>\n"
    "\t and dimensions <dX>, <dY>, <dZ>.",
    //
    __FILE__, group, ENGINE_MakeBox);

  //-------------------------------------------------------------------------//
  interp->AddCommand("hlr",
    //
    "hlr res posX posY posZ nX nY nZ\n"
    "\t Performs HLR algorithm using <posX, posY, posZ> as a location of a\n"
    "\t projection plane with <nX, nY, nZ> as its normal direction.",
    //
    __FILE__, group, ENGINE_HLR);

  //-------------------------------------------------------------------------//
  interp->AddCommand("make-fillet",
    //
    "make-fillet radius\n"
    "\t Blends the selected edges with the given radius.",
    //
    __FILE__, group, ENGINE_MakeFillet);

  //-------------------------------------------------------------------------//
  interp->AddCommand("build-triangulation-obb",
    //
    "build-triangulation-obb res\n"
    "\t Builds oriented bounding box (OBB) for triangulation.",
    //
    __FILE__, group, ENGINE_BuildTriangulationOBB);
}