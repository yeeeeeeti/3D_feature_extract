
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

	// solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��)
	void Test(string filename, int solution, bool bDumpEEAG);

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			�ýӿ��ڸ�������չ�����ڽ�ͼ�����в�����Ԥ������������ݿ���ƥ�������������
	// ����˵����
	//			rEEAG : [I]��const ���ͣ����ӿڵ������������ 3.2 ��ʾ�ӿ��γɵ���չ�����ڽ�ͼ������Ϊ���ӿڵ����롣
	//			rFeatureList : [I]��const ���ͣ����ӿڵ������������Ԥ�����������ݿ���ƥ�������������Ӧ���Ӿ����б�
	// ����ֵ��
	//			���ҳɹ����򷵻� true������ false��
	//////////////////////////////////////////////////////////////////////////
	bool FeatureMatchingFromDB(const EAAG & rEAAG, const FEATURELIST & rFeatureList, string& name);

private:
	std::string szFNOrPath; // ����������άģ�͵��ļ�����·����
	std::string szFN_AAG;
	std::string szFN_EAAG;

	int solution;  // 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��)
	bool bDumpEEAG;

	FEATURELIST DBFeaturesList;	// ���ݿ��ж���Ĳ�ͬ���͵�������Ӧ�ľ�������

private:
	FEATURELIST& GetPreDefinedFeatureDB() { return DBFeaturesList; }
	void DumpEAAG(Standard_OStream &out, EAAG rEAAG);
	void print_FeatureList(FEATURELIST rFeatureList);

	void BatchTestFromDir(char *FileDir);
	void TestOneObject(std::string filename);

	bool Read3DFile(const TCollection_AsciiString& filename, const bool doHealing, TopoDS_Shape& result);

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			�ýӿڻ������Ԥ����ļ�������������δ����ļ���������
	// ����˵����
	//			crShape : [I]��const ���ͣ����ӿڵ������������ά���ģ������ʵ����
	//			rFeatureList : [O]�����ӿڵ������������Ԥ�����������ݿ���ƥ�������������Ӧ���Ӿ����б�
	//			rUndefinedList : [O]�����ӿڵ������������Ԥ�����������ݿⲻ��ƥ�������������Ӧ���Ӿ����б�
	// ����ֵ��
	//			���ҳɹ����򷵻� true������ false��
	//////////////////////////////////////////////////////////////////////////
	bool GetFeatureList(const SHAPE& crShape, FEATURELIST& rFeatureList, FEATURELIST &rUndefinedList);

	EAAG GenerateEAAG(const TopoDS_Shape &aShape);

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			�ýӿ��ڸ�������չ�����ڽ�ͼ�����в�������ļ�������������
	// ����˵����
	//			rEEAG : [I]��const ���ͣ����ӿڵ������������ 3.2 ��ʾ�ӿ��γɵ���չ�����ڽ�ͼ������Ϊ���ӿڵ����롣
	//			rFeatureList : [O]�����ӿڵķ���ֵ����Ԥ�����������ݿ���ƥ�������������Ӧ���Ӿ����б�
	// ����ֵ��
	//			���ҳɹ����򷵻� true������ false��
	//////////////////////////////////////////////////////////////////////////
	bool ExtractionAllFeatures(const EAAG& rEAAG, FEATURELIST & rFeatureList);

	void searchConvexFeature(const EAAG rEAAG, FEATURELIST & rFeatureList);         //ʶ��͹����

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			Ѱ��͹������
	//////////////////////////////////////////////////////////////////////////
	void ergodic_for_convexFace(const EAAG rEAAG, bool* mark);

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			Ѱ���׸�δ��ǰ���
	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> mark_concaveEdge(const EAAG rEAAG, int index, bool **concaveRec);

	//////////////////////////////////////////////////////////////////////////
	// ����˵����
	//			�齨һ�������ڽӾ���
	//////////////////////////////////////////////////////////////////////////
	FeaturePart createFeaturePart(const EAAG rEAAG, vector<int> rowList, const char* name);

	FeaturePart package(int dim, char * name, int* matrix);

	bool GenerateFeatureMatrixFromXMLFile(); // ��ָ���������ļ��ж�ȡ�������ݿ���Ϣ
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
	void featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList);    //����ȥ�غ���
	void DumpSearchedFeatures(FEATURELIST &rFeatureList);
	void DumpSearchedFeatures_V2(FEATURELIST &rFeatureList);

	// �ݹ������ǰĿ¼�µ������ļ�
	void getFiles(vector<string>& files, string path, int layer);
	void MakeLower(string &szSourc);
	bool row_matrixMatch(uElemType ** queryMatrix, uElemType ** dataMatrix, int dim, int* rowList); //�����������ж�
	bool rowMatch(uElemType * queryRow, uElemType * dataRow, int dim);
	EAAG swapMatrix(EAAG rEAAG, int *rowList);
	bool matrixMatch(uElemType **dataMatrix, uElemType **queryMatrix, int m);
	void print_uElemTypeMatrix(uElemType **matrix, int m);
};


