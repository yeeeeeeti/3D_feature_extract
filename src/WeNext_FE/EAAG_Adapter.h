#include <asiAlgo_AAG.h>
#include "dataFormat.h"

class asiAlgo_FeatureAttrAngle;

using namespace std;

class EAAG_Adapter{
public:
	EAAG_Adapter(Handle(asiAlgo_AAG)& a_aag);
	EAAG convert();

private:
	eFaceType faceToCode(TopoDS_Face aFace);
	//eCurveType attrToCode(Handle(asiAlgo_FeatureAttrAngle) attr);
	eCurveType arcToCode(Handle(asiAlgo_FeatureAttrAngle) attr, const TopTools_IndexedMapOfShape& Edges);
	Handle(asiAlgo_AAG) aag;
};

