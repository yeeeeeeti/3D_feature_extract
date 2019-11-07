//-----------------------------------------------------------------------------
// Created on: 09 March 2017
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

// Own include
#include <asiAlgo_PlateOnEdges.h>

// asiAlgo includes
#include <asiAlgo_Timer.h>

// OCCT includes
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <BRep_Tool.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepAlgo.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepLib.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <GeomPlate_HArray1OfHCurve.hxx>
#include <GeomPlate_MakeApprox.hxx>
#include <GeomPlate_PlateG0Criterion.hxx>
#include <ShapeExtend_WireData.hxx>
#include <ShapeFix_Shape.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <TColStd_MapIteratorOfPackedMapOfInteger.hxx>
#include <TopExp.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>

#undef COUT_DEBUG
#if defined COUT_DEBUG
  #pragma message("===== warning: COUT_DEBUG is enabled")
#endif

//-----------------------------------------------------------------------------

//! Constructs the tool.
//! \param aag      [in] Attributed Adjacency Graph (AAG).
//! \param progress [in] progress indicator.
//! \param plotter  [in] imperative plotter.
asiAlgo_PlateOnEdges::asiAlgo_PlateOnEdges(const Handle(asiAlgo_AAG)& aag,
                                           ActAPI_ProgressEntry       progress,
                                           ActAPI_PlotterEntry        plotter)
: ActAPI_IAlgorithm(progress, plotter), m_aag(aag), m_shape( aag->GetMasterCAD() )
{}

//-----------------------------------------------------------------------------

//! Constructs the tool.
//! \param shape    [in] working shape.
//! \param progress [in] progress indicator.
//! \param plotter  [in] imperative plotter.
asiAlgo_PlateOnEdges::asiAlgo_PlateOnEdges(const TopoDS_Shape&  shape,
                                           ActAPI_ProgressEntry progress,
                                           ActAPI_PlotterEntry  plotter)
: ActAPI_IAlgorithm(progress, plotter), m_shape(shape)
{}

//-----------------------------------------------------------------------------

//! Constructs TPS (Thin Plate Spline) approximation for the passed edges.
//! \param edgeIndices [in]  edges to build the approximation surface for.
//! \param continuity  [in]  desired order of continuity.
//! \param support     [out] support b-surface.
//! \param result      [out] reconstructed face.
//! \return true in case of success, false -- otherwise.
bool asiAlgo_PlateOnEdges::Build(const TColStd_PackedMapOfInteger& edgeIndices,
                                 const unsigned int                continuity,
                                 Handle(Geom_BSplineSurface)&      support,
                                 TopoDS_Face&                      result)
{
  /* =============================
   *  STAGE 1: build host surface
   * ============================= */

  if ( !this->BuildSurf(edgeIndices, continuity, support) )
    return false;

  /* ===============================
   *  STAGE 2: reconstruct topology
   * =============================== */

  TIMER_NEW
  TIMER_GO

  const int nbedges = edgeIndices.Extent();

  TopTools_Array1OfShape tab(1, nbedges);

  // Fill wire builder with edges. We use the original topology as-is. The
  // only post-processing stage which is necessary to apply is re-projection
  // of 3D-curves to the plate surface (in order to obtain p-curves)
  Handle(ShapeExtend_WireData) WD = new ShapeExtend_WireData;
  for ( TColStd_MapIteratorOfPackedMapOfInteger eit(edgeIndices); eit.More(); eit.Next() )
  {
    const int          eidx = eit.Key();
    const TopoDS_Edge& E    = TopoDS::Edge( m_aag->RequestMapOfEdges().FindKey(eidx) );

    WD->Add(E);
  }
  //
  TopoDS_Wire W = WD->WireAPIMake();
  //
  if ( W.IsNull() )
  {
    m_plotter.DRAW_SURFACE(support, Color_Red, "support");
    m_progress.SendLogMessage(LogErr(Normal) << "Wire reconstruction failed: null wire");
    return false;
  }

  // Build face
  BRepBuilderAPI_MakeFace MF(support, W, true);
  TopoDS_Face face = MF.Face();

  // Check orientation of the outer wire
  BRepTopAdaptor_FClass2d clas2d( face, Precision::Confusion() );
  if ( clas2d.PerformInfinitePoint() == TopAbs_IN )
  {
    W.Reverse();
    BRepBuilderAPI_MakeFace MF1(support, W, true);
    face = MF1.Face();
  }

  // Use shape healer to re-project 3D curves and obtain missing p-curves so
  ShapeFix_Shape ShapeHealer(face);
  try
  {
    ShapeHealer.Perform();
  }
  catch ( ... )
  {
    m_plotter.DRAW_SURFACE(support, Color_Red, "support");
    m_progress.SendLogMessage(LogErr(Normal) << "Face healing failed");
    return false;
  }
  face = TopoDS::Face( ShapeHealer.Shape() );

  // Check the result
  if ( !BRepAlgo::IsValid(face) )
  {
    m_plotter.DRAW_SURFACE(support, Color_Red, "support");
    m_progress.SendLogMessage(LogWarn(Normal) << "Face is not valid");
  }

  // Set result
  result = face;

  TIMER_FINISH
  TIMER_COUT_RESULT_MSG("Construct topology")

  return true;
}

//-----------------------------------------------------------------------------

bool asiAlgo_PlateOnEdges::BuildSurf(const TColStd_PackedMapOfInteger& edgeIndices,
                                     const unsigned int                continuity,
                                     Handle(Geom_BSplineSurface)&      support)
{
  std::vector<TopoDS_Edge> edges;
  //
  for ( TColStd_MapIteratorOfPackedMapOfInteger eit(edgeIndices); eit.More(); eit.Next() )
  {
    const int          eidx = eit.Key();
    const TopoDS_Edge& E    = TopoDS::Edge( m_aag->RequestMapOfEdges().FindKey(eidx) );
    //
    edges.push_back(E);
  }

  return this->BuildSurf(edges, continuity, support);
}

//-----------------------------------------------------------------------------

bool asiAlgo_PlateOnEdges::BuildSurf(const std::vector<TopoDS_Edge>& edges,
                                     const unsigned int              continuity,
                                     Handle(Geom_BSplineSurface)&    support)
{
  /* ==============================
   *  STAGE 1: prepare constraints
   * ============================== */

  const int nbedges = int( edges.size() );

  // Prepare working collection for support curves (used to create
  // pinpoint constraints)
  Handle(GeomPlate_HArray1OfHCurve)
    fronts = new GeomPlate_HArray1OfHCurve(1, nbedges);

  // Prepare working collection for smoothness values associated with
  // each support curve
  Handle(TColStd_HArray1OfInteger)
    tang = new TColStd_HArray1OfInteger(1, nbedges);

  // Prepare working collection for discretization numbers associated with
  // each support curve
  Handle(TColStd_HArray1OfInteger)
    nbPtsCur = new TColStd_HArray1OfInteger(1, nbedges);

  // Get model
  const TopoDS_Shape& model = m_shape;

  // Build edge-face map
  TopTools_IndexedDataMapOfShapeListOfShape M;
  TopExp::MapShapesAndAncestors(model, TopAbs_EDGE, TopAbs_FACE, M);

  // Loop over the edges to prepare constraints
  int i = 0;
  for ( int eidx = 0; eidx < nbedges; ++eidx )
  {
    i++;
    tang->SetValue(i, continuity);
    nbPtsCur->SetValue(i, 10); // Number of discretization points

    const TopoDS_Edge& E = TopoDS::Edge( edges[eidx] );
    const TopoDS_Face& F = TopoDS::Face( M.FindFromKey(E).First() );

    m_plotter.DRAW_SHAPE(E, Color_Red, 1.0, true, "asiAlgo_PlateOnEdges_E");

    // Get CONS for each edge and fill the constraint
    BRepAdaptor_Surface S(F);
    GeomAdaptor_Surface GAS = S.Surface();
    Handle(GeomAdaptor_HSurface) HGAS = new GeomAdaptor_HSurface(GAS);
    //
    Handle(BRepAdaptor_HCurve2d) C = new BRepAdaptor_HCurve2d();
    C->ChangeCurve2d().Initialize(E, F);
    //
    Adaptor3d_CurveOnSurface ConS(C, HGAS);
    Handle(Adaptor3d_HCurveOnSurface) HConS = new Adaptor3d_HCurveOnSurface(ConS);
    fronts->SetValue(i, HConS);
  }

  /* ======================
   *  STAGE 2: build plate
   * ====================== */

  TIMER_NEW
  TIMER_GO

  // Build plate
  GeomPlate_BuildPlateSurface BuildPlate(nbPtsCur, fronts, tang, 3);
  //
  try
  {
    BuildPlate.Perform();
  }
  catch ( ... )
  {
    m_progress.SendLogMessage(LogErr(Normal) << "Exception in OCCT plate surface builder");
    return false;
  }
  //
  if ( !BuildPlate.IsDone() )
  {
    m_progress.SendLogMessage(LogErr(Normal) << "Plating failed");
    return false;
  }
  Handle(GeomPlate_Surface) plate = BuildPlate.Surface();

  TIMER_FINISH
  TIMER_COUT_RESULT_MSG("Build plate")

  /* =======================================
   *  STAGE 3: approximate plate with NURBS
   * ======================================= */

  TIMER_RESET
  TIMER_GO

  GeomPlate_MakeApprox MKS(plate, Precision::Approximation(), 4, 7, 0.001, 1);
  support = MKS.Surface();

  TIMER_FINISH
  TIMER_COUT_RESULT_MSG("Approximate plate with B-surface")

  return true;
}