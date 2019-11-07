#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <iostream>
#include <list>
#include <TopoDS_Shape.hxx>

using namespace std;

typedef TopoDS_Shape SHAPE;

//-------------------------------------------
// OCCT 关于 Surface 类型的定义
// GeomAbs_SurfaceType.hxx
//
//enum GeomAbs_SurfaceType
//{
//	GeomAbs_Plane,
//	GeomAbs_Cylinder,
//	GeomAbs_Cone,
//	GeomAbs_Sphere,
//	GeomAbs_Torus,
//	GeomAbs_BezierSurface,
//	GeomAbs_BSplineSurface,
//	GeomAbs_SurfaceOfRevolution,
//	GeomAbs_SurfaceOfExtrusion,
//	GeomAbs_OffsetSurface,
//	GeomAbs_OtherSurface
//};

typedef enum _eFaceType {
	// 面类型定义
	eFace_Empty = 0,
	
	eIn_Geom_Plane = 10,
	eOut_Geom_Plane = 11,
	
	eIn_Geom_CylindricalSurface = 20,
	eOut_Geom_CylindricalSurface = 21,
	
	eIn_Geom_ConicalSurface = 30,
	eOut_Geom_ConicalSurface = 31,
	
	eIn_Geom_SphericalSurface = 40,
	eOut_Geom_SphericalSurface = 41,
	
	eIn_Geom_BezierSurface = 50, 
	eOut_Geom_BezierSurface = 51, 
	
	eIn_Geom_BSplineSurface = 60, 
	eOut_Geom_BSplineSurface = 61, 
	
	eIn_Geom_BoundedSurface = 70, 
	eOut_Geom_BoundedSurface = 71, 
	
	eIn_Geom_ElementarySurface = 80,
	eOut_Geom_ElementarySurface  = 81,
	
	eIn_Geom_OffsetSurface = 90,
	eOut_Geom_OffsetSurface = 91,
	
	eIn_Geom_OsculatingSurface = 100,
	eOut_Geom_OsculatingSurface  = 101,
	
	eIn_Geom_SweptSurface = 110,
	eOut_Geom_SweptSurface = 111,
	
	eIn_Geom_ToroidalSurface = 120,  
	eOut_Geom_ToroidalSurface = 121, 

	eIn_Geom_HSequenceOfBSplineSurface = 130,
	eOut_Geom_HSequenceOfBSplineSurface  = 131,
	
	eIn_Geom_RectangularTrimmedSurface = 140,
	eOut_Geom_RectangularTrimmedSurface  = 141,
	
	eIn_Geom_SequenceOfBSplineSurface = 150,
	eOut_Geom_SequenceOfBSplineSurface  = 151,
	
	eIn_Geom_SurfaceOfLinearExtrusion = 160,
	eOut_Geom_SurfaceOfLinearExtrusion = 161,
	
	eIn_Geom_SurfaceOfRevolution = 170,  
	eOut_Geom_SurfaceOfRevolution = 171, 
	
	eFaceType_Undefined = 999
}eFaceType;

//-------------------------------------------
// OCCT 关于 Curve 类型的定义
// GeomAbs_CurveType.hxx
//
//enum GeomAbs_CurveType
//{
//	GeomAbs_Line,
//	GeomAbs_Circle,
//	GeomAbs_Ellipse,
//	GeomAbs_Hyperbola,
//	GeomAbs_Parabola,
//	GeomAbs_BezierCurve,
//	GeomAbs_BSplineCurve,
//	GeomAbs_OffsetCurve,
//	GeomAbs_OtherCurve
//};

//! Type of angle. Numerical values associated with the items are taken
//! from fundamental paper of Joshi "Graph-based heuristics for recognition
//! of machined features from a 3D solid model", 1988.
//		enum asiAlgo_FeatureAngleType
//		{
//			FeatureAngleType_Undefined = -1,
//			FeatureAngleType_Concave = 0,
//			FeatureAngleType_Convex = 1,
//			FeatureAngleType_Smooth = 2
//		};

// 面与面交线的类型定义
typedef enum _eCurveType {
	
	eCurve_Empty = 0,
	
	eConcave_Geom_Line = 10,
	eConvex_Geom_Line = 11,
	eSmooth_Geom_Line = 12,
	eUndefined_Geom_Line = 13,

	eConcave_Geom_Circle = 20,
	eConvex_Geom_Circle = 21,
	eSmooth_Geom_Circle = 22,
	eUndefined_Geom_Circle = 23,

	eConcave_Geom_Ellipse = 30,
	eConvex_Geom_Ellipse = 31,
	eSmooth_Geom_Ellipse = 32,
	eUndefined_Geom_Ellipse = 33,

	eConcave_Geom_BezierCurve= 40,
	eConvex_Geom_BezierCurve = 41,
	eSmooth_Geom_BezierCurve = 42,
	eUndefined_Geom_BezierCurve = 43,

	eConcave_Geom_BoundedCurve = 50,
	eConvex_Geom_BoundedCurve = 51,
	eSmooth_Geom_BoundedCurve = 52,
	eUndefined_Geom_BoundedCurve = 53,

	eConcave_Geom_BSplineCurve = 60,
	eConvex_Geom_BSplineCurve = 61,
	eSmooth_Geom_BSplineCurve = 62,
	eUndefined_Geom_BSplineCurve = 63,

	eConcave_Geom_Conic= 70,
	eConvex_Geom_Conic = 71,
	eSmooth_Geom_Conic = 72,
	eUndefined_Geom_Conic = 73,

	eConcave_Geom_Hyperbola = 80,
	eConvex_Geom_Hyperbola = 81,
	eSmooth_Geom_Hyperbola = 82,
	eUndefined_Geom_Hyperbola = 83,

	eConcave_Geom_OffsetCurve = 90,
	eConvex_Geom_OffsetCurve = 91,
	eSmooth_Geom_OffsetCurve = 92,
	eUndefined_Geom_OffsetCurve = 93,

	eConcave_Geom_Parabola = 100,
	eConvex_Geom_Parabola = 101,
	eSmooth_Geom_Parabola = 102,
	eUndefined_Geom_Parabola = 103,

	eConcave_Geom_TrimmedCurve = 110,
	eConvex_Geom_TrimmedCurve = 111,
	eSmooth_Geom_TrimmedCurve = 112,
	eUndefined_Geom_TrimmedCurve = 113,

	eCurveType_Undefined = 999
}eCurveType;

// 扩展属性邻接矩阵中元素的类型
typedef union _uElemType {
	
	enum _eFaceType A_ii;
	enum _eCurveType A_ij;
} uElemType;

typedef unsigned char BYTE;
typedef struct _AAG {
	// 三维零件模型的属性邻接图矩阵结构描述
	int nDim;  // 矩阵维数
	BYTE** elem; // 二维数组，用于存储属性邻接图矩阵
} AAG;
typedef struct _EAAG {
	// 三维零件模型的扩展属性邻接图矩阵结构描述
	int nDim;  // 矩阵维数
	uElemType ** elem; // 二维数组，用于存储扩展属性邻接图矩阵
}EAAG;

typedef struct _FeaturePart {
	// 三维零件模型的扩展属性邻接图矩阵结构描述
	int nDim;  // 矩阵维数
	char szDes[128]; // 特征描述
	int* indexRec;   // 面索引记录
	uElemType ** elem; // 二维数组，用于存储扩展属性邻接图矩阵
}FeaturePart;
typedef std::list<struct _FeaturePart> FEATURELIST;

#endif