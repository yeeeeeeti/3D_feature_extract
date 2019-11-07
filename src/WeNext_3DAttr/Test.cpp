#include <iostream>

// OpenCascade Library.
#define WNT
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>

#pragma comment(lib, "TKernel.lib")
#pragma comment(lib, "TKMath.lib")
#pragma comment(lib, "TKBRep.lib")
#pragma comment(lib, "TKPrim.lib")
#pragma comment(lib, "TKTopAlgo.lib")

/**
* @breif Dump orientation types.
*        Orientation definitaion:
*        enum TopAbs_Orientation {

*            TopAbs_FORWARD,

*            TopAbs_REVERSED,

*            TopAbs_INTERNAL,

*            TopAbs_EXTERNAL

*        };
*/
std::string dumpOrientation(const TopAbs_Orientation& orient)
{
	std::string strType;

	switch (orient)
	{
	case TopAbs_FORWARD:
		strType = "TopAbs_FORWARD";
		break;

	case TopAbs_REVERSED:
		strType = "TopAbs_REVERSED";
		break;

	case TopAbs_INTERNAL:
		strType = "TopAbs_INTERNAL";
		break;

	case TopAbs_EXTERNAL:
		strType = "TopAbs_EXTERNAL";
		break;
	}

	return strType;
}

/**
* @breif Dump edge information.
*/
void processEdge(const TopoDS_Edge& edge, const TopoDS_Face& face)
{
	Standard_Real dTolerance = BRep_Tool::Tolerance(edge);

	Standard_Boolean bIsGeometric = BRep_Tool::IsGeometric(edge);
	Standard_Boolean bIsSameParameter = BRep_Tool::SameParameter(edge);
	Standard_Boolean bIsSameRange = BRep_Tool::SameRange(edge);
	Standard_Boolean bIsDegenerated = BRep_Tool::Degenerated(edge);
	Standard_Boolean bIsClosed = BRep_Tool::IsClosed(edge, face);

	TopAbs_Orientation nOrientation = edge.Orientation();

	// Dump edge info.
	std::cout << "====== Edge Info =======" << std::endl;
	std::cout << "Tolerance: " << dTolerance << std::endl;
	std::cout << "Orientation: " << dumpOrientation(nOrientation) << std::endl;
	std::cout << "Geometric: " << (bIsGeometric ? "True" : "False") << std::endl;
	std::cout << "Same Parameter: " << (bIsSameParameter ? "True" : "False") << std::endl;
	std::cout << "Same Range: " << (bIsSameRange ? "True" : "False") << std::endl;
	std::cout << "Degenerated edge: " << (bIsDegenerated ? "True" : "False") << std::endl;
	std::cout << "Seam edge: " << (bIsClosed ? "True" : "False") << std::endl;

	// Dump vertex of the edge.
	for (TopExp_Explorer vertexItr(edge, TopAbs_VERTEX);
		vertexItr.More();
		vertexItr.Next())
	{
		const TopoDS_Vertex& aVertex = TopoDS::Vertex(vertexItr.Current());
		gp_Pnt pnt = BRep_Tool::Pnt(aVertex);

		std::cout << "Vertex: (" << pnt.X() << ", " << pnt.Y() << ", " << pnt.Z() << ")" << std::endl;
	}
}

int main(void)
{
	Standard_Integer nSphereFaceCount = 0;
	Standard_Integer nSphereEdgeCount = 0;

	TopoDS_Shape sphere = BRepPrimAPI_MakeSphere(1.0);

	for (TopExp_Explorer faceItr(sphere, TopAbs_FACE);
		faceItr.More();
		faceItr.Next())
	{
		const TopoDS_Face& aFace = TopoDS::Face(faceItr.Current());

		++nSphereFaceCount;

		for (TopExp_Explorer edgeItr(aFace, TopAbs_EDGE);
			edgeItr.More();
			edgeItr.Next())
		{
			const TopoDS_Edge& aEdge = TopoDS::Edge(edgeItr.Current());

			processEdge(aEdge, aFace);

			++nSphereEdgeCount;
		}
	}

	std::cout << "Sphere face count: " << nSphereFaceCount << std::endl;
	std::cout << "Sphere edge count: " << nSphereEdgeCount << std::endl;

	return 0;
}