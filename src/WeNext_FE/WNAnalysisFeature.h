
#include <asiAlgo_IGES.h>
#include <asiAlgo_STEP.h>
#include <asiAlgo_Utils.h>
#include <ShapeFix_Shape.hxx>

#include <StlAPI.hxx>

#include "WNXML.h"

#define MAXNODES 200

class CWNAnalysisFeature {
public:
	CWNAnalysisFeature(std::string szObjectFN){
		szFNOrPath = szObjectFN;
		DBFeaturesList.clear();

		GenerateFeatureMatrixFromXMLFile();
	}

	// solution = 1：提取匹配方法，0：VF2匹配方法，（默认VF2方法识别)
	void Test(string filename, int solution, bool bDumpEEAG);

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			该接口在给定的扩展属性邻接图矩阵中查找与预定义的特征数据库相匹配的制造特征。
	// 参数说明：
	//			rEEAG : [I]，const 类型，本接口的输入参数。由 3.2 所示接口形成的扩展属性邻接图矩阵，作为本接口的输入。
	//			rFeatureList : [I]，const 类型，本接口的输入参数。与预定义特征数据库相匹配的所有特征对应的子矩阵列表。
	// 返回值：
	//			查找成功，则返回 true，否则 false。
	//////////////////////////////////////////////////////////////////////////
	bool FeatureMatchingFromDB(const EAAG & rEAAG, const FEATURELIST & rFeatureList, string& name);

private:
	std::string szFNOrPath; // 待分析的三维模型的文件名或路径名
	std::string szFN_AAG;
	std::string szFN_EAAG;

	int solution;  // 1：提取匹配方法，0：VF2匹配方法，（默认VF2方法识别)
	bool bDumpEEAG;

	FEATURELIST DBFeaturesList;	// 数据库中定义的不同类型的特征对应的矩阵特征

private:
	FEATURELIST& GetPreDefinedFeatureDB() { return DBFeaturesList; }
	void DumpEAAG(Standard_OStream &out, EAAG rEAAG);
	void print_FeatureList(FEATURELIST rFeatureList);

	void BatchTestFromDir(char *FileDir);
	void TestOneObject(std::string filename);

	bool Read3DFile(const TCollection_AsciiString& filename, const bool doHealing, TopoDS_Shape& result);

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			该接口获得所有预定义的几何制造特征和未定义的几何特征。
	// 参数说明：
	//			crShape : [I]，const 类型，本接口的输入参数。三维零件模型描述实例。
	//			rFeatureList : [O]，本接口的输出参数。与预定义特征数据库相匹配的所有特征对应的子矩阵列表。
	//			rUndefinedList : [O]，本接口的输出参数。与预定义特征数据库不相匹配的所有特征对应的子矩阵列表。
	// 返回值：
	//			查找成功，则返回 true，否则 false。
	//////////////////////////////////////////////////////////////////////////
	bool GetFeatureList(const SHAPE& crShape, FEATURELIST& rFeatureList, FEATURELIST &rUndefinedList);

	EAAG GenerateEAAG(const TopoDS_Shape &aShape);

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			该接口在给定的扩展属性邻接图矩阵中查找零件的几何制造特征。
	// 参数说明：
	//			rEEAG : [I]，const 类型，本接口的输入参数。由 3.2 所示接口形成的扩展属性邻接图矩阵，作为本接口的输入。
	//			rFeatureList : [O]，本接口的返回值。与预定义特征数据库相匹配的所有特征对应的子矩阵列表。
	// 返回值：
	//			查找成功，则返回 true，否则 false。
	//////////////////////////////////////////////////////////////////////////
	bool ExtractionAllFeatures(const EAAG& rEAAG, FEATURELIST & rFeatureList);

	void searchConvexFeature(const EAAG rEAAG, FEATURELIST & rFeatureList);         //识别凸特征

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			寻找凸面特征
	//////////////////////////////////////////////////////////////////////////
	void ergodic_for_convexFace(const EAAG rEAAG, bool* mark);

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			寻找首个未标记凹边
	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> mark_concaveEdge(const EAAG rEAAG, int index, bool **concaveRec);

	//////////////////////////////////////////////////////////////////////////
	// 功能说明：
	//			组建一个特征邻接矩阵
	//////////////////////////////////////////////////////////////////////////
	FeaturePart createFeaturePart(const EAAG rEAAG, vector<int> rowList, const char* name);

	FeaturePart package(int dim, char * name, int* matrix);

	bool GenerateFeatureMatrixFromXMLFile(); // 从指定的配置文件中读取特征数据库信息
	bool parse_feature(xmlDocPtr doc, xmlNodePtr cur);
	void PrintFeatureMatrix(int *matrix, int nDimSize, string szFeatureName);
	void DumpPreDefinedFeatures(FEATURELIST rFeatureList);

	//////////////////////////////////////////////////////////////////////////
	// Call the VFLib Graph Matching Library, version 2.0
	// Pasquale Foggia foggiapa@unina.it
	// March 2001
	// This VFLib graph matching library, developed at the Intelligent Systems and Artificial Vision Lab. 
	// (SIVALab)of the University of Naples ``Federico II''.
	//////////////////////////////////////////////////////////////////////////
	bool VF2_Matching(const EAAG rEAAG, const FeaturePart aFeature, vector<FeaturePart>& recList);
	void featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList);    //特征去重函数
	void DumpSearchedFeatures(FEATURELIST &rFeatureList);
	void DumpSearchedFeatures_V2(FEATURELIST &rFeatureList);

	// 递归遍历当前目录下的所有文件
	void getFiles(vector<string>& files, string path, int layer);
	void MakeLower(string &szSourc);
	bool row_matrixMatch(uElemType ** queryMatrix, uElemType ** dataMatrix, int dim, int* rowList); //矩阵行相似判断
	bool rowMatch(uElemType * queryRow, uElemType * dataRow, int dim);
	EAAG swapMatrix(EAAG rEAAG, int *rowList);
	bool matrixMatch(uElemType **dataMatrix, uElemType **queryMatrix, int m);
	void print_uElemTypeMatrix(uElemType **matrix, int m);
};


