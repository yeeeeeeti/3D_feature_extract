
# pragma warning (disable:4819)

#include <iostream>

#include <asiAlgo_AAG.h>
#include <asiAlgo_FeatureAttrAngle.h>
#include <asiAlgo_STEP.h>
#include <asiAlgo_IGES.h>
#include <asiAlgo_Utils.h>

#include <BRepPrimAPI_MakeBox.hxx>
#include <Geom_Line.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_Hyperbola.hxx>
#include <Geom_Parabola.hxx>
#include <Geom_SequenceOfBSplineSurface.hxx>
#include <Geom_SequenceOfBSplineSurface.hxx>

#include <STEPControl_Reader.hxx> 
#include <IGESControl_Controller.hxx>
#include <TopoDS.hxx>


#include "EAAG_Adapter.h"
#include "dataFormat.h"


using std::string;

bool ClearEAAG(EAAG &anEAAG);
bool DumpEAAGInfo(const EAAG& anEAAG);
//bool Read(const TCollection_AsciiString& filename,
//	const bool                     doHealing,
//	TopoDS_Shape&                  result);

extern bool debug;


bool ClearEAAG(EAAG &anEAAG) {
	int nFaceCount = anEAAG.nDim;
	anEAAG.nDim = 0;
	uElemType **a = anEAAG.elem;
	// free all
	for (int i = 0; i < nFaceCount; i++)
		delete[] a[i];
	a = NULL;
	return true;
}

// print the AAG
bool DumpEAAGInfo(const EAAG& anEAAG) {
	int nFaceCount = anEAAG.nDim;
	uElemType **a = anEAAG.elem;
	for (int j = 0; j < nFaceCount; j++) {
		for (int k = 0; k < nFaceCount; k++)
		if (j == k)
			cout << a[j][k].A_ii << "\t";
		else
			cout << a[j][k].A_ij << "\t";
		cout << endl;
	}
	return true;
}

EAAG_Adapter::EAAG_Adapter(Handle(asiAlgo_AAG)& a_aag) : aag(a_aag) {

}

// 编码
EAAG EAAG_Adapter::convert() {
	EAAG result;
	// Get faces from AAG
	const TopTools_IndexedMapOfShape& Faces = aag->GetMapOfFaces(); 
	const TopTools_IndexedMapOfShape& Edges = aag->RequestMapOfEdges();
	const TColStd_PackedMapOfInteger& SelFaces = aag->GetSelectedFaces();
	const asiAlgo_AAG::t_adjacency&   Neighborhood = aag->GetNeighborhood();

	// malloc memory for the EAAG matrix and initilize
	int nFaceCount = Faces.Size();
	uElemType **a = new uElemType*[nFaceCount];
	for (int i = 0; i < nFaceCount; i++) {
		a[i] = new uElemType[nFaceCount];
	}
	for (int j = 0; j < nFaceCount; j++) {
		for (int k = 0; k < nFaceCount; k++) {
			a[j][k] = { eFace_Empty };
		}
	}

	// Add links for adjacency relations
	for (asiAlgo_AAG::t_adjacency::Iterator it(Neighborhood); it.More(); it.Next())	{
		const int       f_idx = it.Key();
		a[f_idx-1][f_idx-1].A_ii = faceToCode(TopoDS::Face(Faces(f_idx)));

		// Get face neighbors
		const TColStd_PackedMapOfInteger& neighbors = it.Value();

		// Add links for each neighbor
		for (TColStd_MapIteratorOfPackedMapOfInteger mit(neighbors); mit.More(); mit.Next()){
			const int       neighbor_f_idx = mit.Key();

			// Check angle
			asiAlgo_AAG::t_arc arc(f_idx, neighbor_f_idx);
			Handle(asiAlgo_FeatureAttrAngle) attr = Handle(asiAlgo_FeatureAttrAngle)::DownCast(aag->GetArcAttribute(arc));
			//
			if (!attr.IsNull()) {
				a[f_idx-1][neighbor_f_idx-1].A_ij = arcToCode(attr, Edges);
			}
		}
	}

	result.elem = a;
	result.nDim = nFaceCount;
	return result;
}

//------------------------------------------------------------
// defined in the file TopAbs_Orientation.hxx
//enum TopAbs_Orientation
//{
//	TopAbs_FORWARD,
//	TopAbs_REVERSED,
//	TopAbs_INTERNAL,
//	TopAbs_EXTERNAL
//};
//------------------------------------------------------------

eFaceType EAAG_Adapter::faceToCode(TopoDS_Face aFace)
{
	Handle(Geom_Surface) surf = BRep_Tool::Surface(aFace);
	if (surf.IsNull())
		return eFace_Empty;

	if (surf->IsInstance(STANDARD_TYPE(Geom_Plane))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_Plane;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_Plane;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}		
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_CylindricalSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_CylindricalSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_CylindricalSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_ConicalSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_ConicalSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_ConicalSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_SphericalSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_SphericalSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_SphericalSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_ToroidalSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_ToroidalSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_ToroidalSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_BezierSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_BezierSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_BezierSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_BSplineSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_BSplineSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_BSplineSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_SurfaceOfRevolution))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_SurfaceOfRevolution;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_SurfaceOfRevolution;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_SurfaceOfLinearExtrusion))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_SurfaceOfLinearExtrusion;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_SurfaceOfLinearExtrusion;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_OffsetSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_OffsetSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_OffsetSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_BoundedSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_BoundedSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_BoundedSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_ElementarySurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_ElementarySurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_ElementarySurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_HSequenceOfBSplineSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_HSequenceOfBSplineSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_HSequenceOfBSplineSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_OsculatingSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_OsculatingSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_OsculatingSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_RectangularTrimmedSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_RectangularTrimmedSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_RectangularTrimmedSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else if (surf->IsInstance(STANDARD_TYPE(Geom_SweptSurface))) {
		if (aFace.Orientation() == TopAbs_FORWARD)
			return eOut_Geom_SweptSurface;
		else if (aFace.Orientation() == TopAbs_REVERSED)
			return eIn_Geom_SweptSurface;
		else {
			cout << "表面内外错误" << endl;
			exit(0);
		}
	}
	else {
		return eFaceType_Undefined;
	}
}

/*
eCurveType EAAG_Adapter::attrToCode(Handle(asiAlgo_FeatureAttrAngle) attr) {
	eCurveType result = eCurveType_Undefined;
	TopTools_IndexedMapOfShape edges = attr->GetEdges();  // 原AS V0.2.6版本中的边存储结构。
	if (edges.IsEmpty())
		return result;

	// convert the edge to curve
	TopoDS_Shape firstShape = *(edges.cbegin()); // A single common edge is enough for analysis
	double f, l;
	Handle(Geom_Curve) cur = BRep_Tool::Curve(TopoDS::Edge(firstShape), f, l);
	if (cur.IsNull())
		return result;

	// analyse type of the curve
	if (cur->IsInstance(STANDARD_TYPE(Geom_Line))) 
		result = eConcave_Geom_Line;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_Circle))) 
		result = eConcave_Geom_Circle;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_BoundedCurve))) // 
		result = eConcave_Geom_BoundedCurve;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_BezierCurve))) // 
		result = eConcave_Geom_BezierCurve;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_BSplineCurve))) 
		result = eConcave_Geom_BSplineCurve;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_Conic)))  // 
		result = eConcave_Geom_Conic;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_Hyperbola)))  // , 
		result = eConcave_Geom_Hyperbola;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_Parabola)))  // , 
		result = eConcave_Geom_Parabola;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_OffsetCurve)))
		result = eConcave_Geom_OffsetCurve;
	else if (cur->IsInstance(STANDARD_TYPE(Geom_TrimmedCurve)))
		result = eConcave_Geom_TrimmedCurve;

	// judge convexity
	if (attr->GetAngle() == Angle_Convex && result != eCurveType_Undefined)
		result = (eCurveType)(result + 1);

	return result;
}
*/

eCurveType EAAG_Adapter::arcToCode(Handle(asiAlgo_FeatureAttrAngle) attr, const TopTools_IndexedMapOfShape& Edges) {
	eCurveType result = eCurveType_Undefined;
	enum asiAlgo_FeatureAngleType angleType = attr->GetAngle();

	//TopTools_IndexedMapOfShape edges = attr->GetEdges();  // 原AS V0.2.6版本中的边存储结构。
	const TColStd_PackedMapOfInteger &edges = attr->GetEdgeIndices(); // AS V0.3.0版本中的边存储结构， 2019.09.09，全新设计，区别于 V0.2.6 版本
	if (edges.IsEmpty())
		return result;
	TColStd_MapIteratorOfPackedMapOfInteger itr(edges);
	for (Standard_Integer j = 1; itr.More(); itr.Next(), j++){
		int aKey(itr.Key());
		double f, l;
		Handle(Geom_Curve) cur = BRep_Tool::Curve(TopoDS::Edge(Edges(aKey)), f, l);


		// analyse type of the curve
		switch (angleType)
		{
		case FeatureAngleType_Undefined:
			
			if (cur->IsInstance(STANDARD_TYPE(Geom_Line)))
				result = eUndefined_Geom_Line;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Circle)))
				result = eUndefined_Geom_Circle;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BoundedCurve)))
				result = eUndefined_Geom_BoundedCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BezierCurve)))
				result = eUndefined_Geom_BezierCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BSplineCurve)))
				result = eUndefined_Geom_BSplineCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Conic)))
				result = eUndefined_Geom_Conic;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Hyperbola)))
				result = eUndefined_Geom_Hyperbola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Parabola)))  // , 
				result = eUndefined_Geom_Parabola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_OffsetCurve)))
				result = eUndefined_Geom_OffsetCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_TrimmedCurve)))
				result = eUndefined_Geom_TrimmedCurve;
			break;
		case FeatureAngleType_Concave:
			
			if (cur->IsInstance(STANDARD_TYPE(Geom_Line)))
				result = eConcave_Geom_Line;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Circle)))
				result = eConcave_Geom_Circle;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BoundedCurve)))
				result = eConcave_Geom_BoundedCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BezierCurve)))
				result = eConcave_Geom_BezierCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BSplineCurve)))
				result = eConcave_Geom_BSplineCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Conic)))
				result = eConcave_Geom_Conic;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Hyperbola)))
				result = eConcave_Geom_Hyperbola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Parabola)))  // , 
				result = eConcave_Geom_Parabola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_OffsetCurve)))
				result = eConcave_Geom_OffsetCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_TrimmedCurve)))
				result = eConcave_Geom_TrimmedCurve;
			break;
		case FeatureAngleType_Convex:
			
			if (cur->IsInstance(STANDARD_TYPE(Geom_Line)))
				result = eConvex_Geom_Line;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Circle)))
				result = eConvex_Geom_Circle;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BoundedCurve)))
				result = eConvex_Geom_BoundedCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BezierCurve)))
				result = eConvex_Geom_BezierCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BSplineCurve)))
				result = eConvex_Geom_BSplineCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Conic)))
				result = eConvex_Geom_Conic;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Hyperbola)))
				result = eConvex_Geom_Hyperbola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Parabola)))  // , 
				result = eConvex_Geom_Parabola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_OffsetCurve)))
				result = eConvex_Geom_OffsetCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_TrimmedCurve)))
				result = eConvex_Geom_TrimmedCurve;
			break;
		case FeatureAngleType_Smooth:
			
			if (cur->IsInstance(STANDARD_TYPE(Geom_Line)))
				result = eSmooth_Geom_Line;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Circle)))
				result = eSmooth_Geom_Circle;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BoundedCurve)))
				result = eSmooth_Geom_BoundedCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BezierCurve)))
				result = eSmooth_Geom_BezierCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_BSplineCurve)))
				result = eSmooth_Geom_BSplineCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Conic)))
				result = eSmooth_Geom_Conic;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Hyperbola)))
				result = eSmooth_Geom_Hyperbola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_Parabola)))  // , 
				result = eSmooth_Geom_Parabola;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_OffsetCurve)))
				result = eSmooth_Geom_OffsetCurve;
			else if (cur->IsInstance(STANDARD_TYPE(Geom_TrimmedCurve)))
				result = eSmooth_Geom_TrimmedCurve;
			break;
		default:
			break;
		}
	}
	return result;
}
