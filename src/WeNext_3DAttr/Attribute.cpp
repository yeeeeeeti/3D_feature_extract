#include <cstdlib>
#include <iostream>
#include <string>

#include <BRepGProp.hxx>
#include <BRepTools.hxx>
#include <GProp_GProps.hxx>
#include <STEPControl_Reader.hxx>

#include <asiAlgo_Utils.h>
#include <Bnd_Box.hxx>
#include <Bnd_OBB.hxx>
#include <IntTools_Context.hxx>
#include <TopoDS_Shape.hxx>

using namespace std;

void Log(char *buf);

void ShowAttributes(TopoDS_Shape shape, ostream &out) 
{ 
	char msg[1024];

	// calulate the global properties
	GProp_GProps System;
//	BRepGProp::VolumeProperties(shape, System);
	BRepGProp::VolumeProperties(shape, System, 1e-5);
//	Standard_EXPORT static Standard_Real VolumePropertiesGK(const TopoDS_Shape& S, GProp_GProps& VProps, const Standard_Real Eps = 0.001, 
//								const Standard_Boolean OnlyClosed = Standard_False, const Standard_Boolean IsUseSpan = Standard_False, 
//								const Standard_Boolean CGFlag = Standard_False, const Standard_Boolean IFlag = Standard_False, 
//								const Standard_Boolean SkipShared = Standard_False);
//	BRepGProp::VolumePropertiesGK(shape, System, 1e-5, false, true, true, true, true);
	Standard_Real volume = System.Mass();

	BRepGProp::SurfaceProperties(shape, System, 1e-5);
	Standard_Real surface = System.Mass();

	// dump the properties of the given shape
	sprintf_s(msg, "--[INFO]--  Geometric attributes:\tV(mm^3): %.3f\tS(mm^2): %.3f", 
				abs(volume), abs(surface));
	Log(msg);

	// 计算包围盒参数
	double xMin, yMin, zMin, xMax, yMax, zMax;
	if (asiAlgo_Utils::Bounds(shape, xMin, yMin, zMin, xMax, yMax, zMax)){
		sprintf_s(msg, "--[INFO]--  Size of bounding box:\tX: %.3f\tY: %.3f\tZ: %.3f", 
				abs(xMax - xMin), abs(yMax - yMin), abs(zMax - zMin));
		Log(msg);

/*
		IntTools_Context context;
		Bnd_OBB obb = context.OBB(shape, 1e-6);
		cout << ">> Size of OBB:\n"
			<< "\tXaxis: " << 2 * obb.XHSize() << "\n"
			<< "\tYaxis: " << 2 * obb.YHSize() << "\n"
			<< "\tZaxis: " << 2 * obb.ZHSize()
			<< endl;
*/
	}
	else {
		sprintf_s(msg, "Can't compute the bounding box.");
		Log(msg);
	}
}

