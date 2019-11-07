#define WNT
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopExp_Explorer.hxx>
#include <TopExp.hxx>
#include <TopoDS.hxx>
#include <TopTools.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_CString.hxx>
#include <BOPTools_AlgoTools3D.hxx>
#include <BOPTools_AlgoTools2D.hxx>
#include <STEPControl_Reader.hxx> 
#include <TopAbs.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_BSplineCurve.hxx>

#include <Geom_Plane.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include "EAAG.h"

#pragma comment(lib, "TKernel.lib")
#pragma comment(lib, "TKMath.lib")
#pragma comment(lib, "TKBRep.lib")
#pragma comment(lib, "TKTopAlgo.lib")
#pragma comment(lib, "TKPrim.lib")
#pragma comment(lib, "TKBO.lib")
#pragma comment(lib, "TKXSBase.lib")
#pragma comment(lib, "TKSTEP.lib")
#pragma comment(lib, "TKG3d.lib")

bool debug = true;
int main() {
	// this is the target shape
	TopoDS_Shape aBox = BRepPrimAPI_MakeBox(100, 150, 200);
	//TopoDS_Shape aBox = ReadStep("C:\\Users\\siyuan\\Desktop\\occt\\part2.STEP");

	EAAG anEAAG;
	// create the EAAG
	GenerateEAAGFromShape(anEAAG, aBox);
	// print the graph
	DumpEAAGInfo(anEAAG);
	// free
	ClearEAAG(anEAAG);
	return 0;
}

TopoDS_Shape ReadStep(Standard_CString str) {
	STEPControl_Reader reader;
	reader.ReadFile(str);

	// Loads file MyFile.stp 
	Standard_Integer NbRoots = reader.NbRootsForTransfer();

	// gets the number of transferable roots 
	if (debug)
		cout << "Number of roots in STEP file : " << NbRoots << endl;

	Standard_Integer NbTrans = reader.TransferRoots();
	// translates all transferable roots, and returns the number of    //successful translations 
	if (debug) {
		cout << "STEP roots transferred : " << NbTrans << endl;
		cout << "Number of resulting shapes is : " << reader.NbShapes() << endl;
	}

	TopoDS_Shape result = reader.OneShape();
	// obtain the results of translation in one OCCT shape 
	return result;
}

bool GenerateEAAGFromShape(EAAG& rEAAG, const TopoDS_Shape& crShape)
{
	// get the number of the faces and store them
	Standard_Integer nFaceCount = 0;
	TopTools_SequenceOfShape faceList;
	for (TopExp_Explorer faceExp(crShape, TopAbs_FACE); faceExp.More(); faceExp.Next())
	{
		TopoDS_Face aFace = TopoDS::Face(faceExp.Current());
		faceList.Append(aFace);
		nFaceCount++;
	}
	if (debug)
		std::cout << "The shape has " << nFaceCount << " faces." << std::endl;

	// malloc memory for the EAAG matrix and initilize
	uElemType **a = new uElemType*[nFaceCount];
	for (int i = 0; i < nFaceCount; i++) {
		a[i] = new uElemType[nFaceCount];
	}
	for (int j = 0; j < nFaceCount; j++)
		for (int k = 0; k < nFaceCount; k++)
			a[j][k] = {eEmpty};

	// map a shape with an integer(face number)... there shouldn't be more than one
	TopTools_DataMapOfShapeInteger theMap;
	int facei = 1;
	for (TopExp_Explorer faceExp(crShape, TopAbs_FACE); faceExp.More(); faceExp.Next(), facei++)
	{
		TopoDS_Face aFace = TopoDS::Face(faceExp.Current());
		Handle(Geom_Surface) aSurface = BRep_Tool::Surface(aFace);
		if (debug) {
			cout << "explorering the " << facei << "th face. " << "type: ";
			cout << aSurface->DynamicType() << endl;
		}
		if (aSurface->DynamicType() == STANDARD_TYPE(Geom_Plane)) {
			a[facei - 1][facei - 1].A_ii = eOut_Plane;
		}
		else if (aSurface->DynamicType() == STANDARD_TYPE(Geom_CylindricalSurface)) {
			a[facei - 1][facei - 1].A_ii = eOut_Surface_Cylinder;
		}
		else if (aSurface->DynamicType() == STANDARD_TYPE(Geom_ConicalSurface)) {
			a[facei - 1][facei - 1].A_ii = eOut_Surface_Cone;
		}
		else if (aSurface->DynamicType() == STANDARD_TYPE(Geom_SphericalSurface)) {
			a[facei - 1][facei - 1].A_ii = eOut_Surface_Sphere;
		}

		// explore the edges
		int edgei = 1;
		for (TopExp_Explorer edgeExp(aFace, TopAbs_EDGE); edgeExp.More(); edgeExp.Next(), edgei++)
		{
			TopoDS_Edge anEdge = TopoDS::Edge(edgeExp.Current());
			Standard_Real first, last;
			Handle(Geom_Curve) aCurve = BRep_Tool::Curve(anEdge, first, last);
			if (debug) {
				cout << "in the " << edgei << "th edge. " << "type: ";
				cout << aCurve->DynamicType() << endl;
			}

			Standard_Integer *p = theMap.ChangeSeek(anEdge);
			if (p == NULL) {
				theMap.Bind(anEdge, facei);
			}
			else { // find the adj face
				int num = *p;
				if (aCurve->DynamicType() == STANDARD_TYPE(Geom_Line)) {
					a[num - 1][facei - 1].A_ij = a[facei - 1][num - 1].A_ij = eConcave_Line;
				}
				else if (aCurve->DynamicType() == STANDARD_TYPE(Geom_Circle)) {
					a[num - 1][facei - 1].A_ij = a[facei - 1][num - 1].A_ij = eConcave_Circle;
				}
				else if (aCurve->DynamicType() == STANDARD_TYPE(Geom_Ellipse)) {
					a[num - 1][facei - 1].A_ij = a[facei - 1][num - 1].A_ij = eConcave_Ellipse;
				}
				else if (aCurve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve)) {
					a[num - 1][facei - 1].A_ij = a[facei - 1][num - 1].A_ij = eConcave_BSpline;
				}

				gp_Dir aDir, bDir;
				gp_Vec aVec;
				const TopoDS_Face bFace = TopoDS::Face(faceList.ChangeValue(num));
				BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(anEdge, aFace, aDir);
				if (debug) {
					cout << "    face " << facei;
					cout << " " << TopAbs::ShapeOrientationToString(aFace.Orientation()) << endl;
				}

				BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(anEdge, bFace, bDir);
				if (debug) {
					cout << "    face " << num;
					cout << " " << TopAbs::ShapeOrientationToString(bFace.Orientation()) << endl;
				}
				aDir.Cross(bDir);

				BOPTools_AlgoTools2D::EdgeTangent(anEdge, 0, aVec);
				gp_Dir eDir(aVec);

				Standard_Boolean convex = eDir.IsEqual(aDir, 0.01);
				if (debug)
					cout << "    convex: " << convex << endl;
				if (convex)
					a[num - 1][facei - 1].A_ij = a[facei - 1][num - 1].A_ij = (eCurveType)(a[facei - 1][num - 1].A_ij + 1);
			}
		}
	}
	rEAAG.elem = a;
	rEAAG.nDim = nFaceCount;
	return true;
}

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
	for (int j = 0; j < nFaceCount; j++)
	{
		for (int k = 0; k < nFaceCount; k++)
			if (j == k)
				cout << a[j][k].A_ii << "\t";
			else
				cout << a[j][k].A_ij << "\t";
		cout << endl;
	}
	return true;
}
