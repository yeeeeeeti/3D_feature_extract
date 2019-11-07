# pragma warning (disable:4819)

# pragma warning (disable:4267)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <asiAlgo_IGES.h>
#include <asiAlgo_STEP.h>
#include <asiAlgo_Utils.h>
#include <ShapeFix_Shape.hxx>

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

#include <StlAPI.hxx>

#include "src/argraph.h"
#include "src/argedit.h"
#include "src/match.h"
#include "src/vf_sub_state.h"
#include "src/vf2_sub_state.h"

#include "EAAG_Adapter.h"
#include "dataFormat.h"

#include "logger.cpp"
#include "WNAnalysisFeature.h"

#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <functional>


using namespace std;
