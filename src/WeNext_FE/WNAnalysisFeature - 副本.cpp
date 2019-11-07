
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

#define MAXNODES 200


// string�ı��뷽ʽΪutf8������ã�
std::string wstring2utf8string(const std::wstring& str)
{
	static std::wstring_convert<std::codecvt_utf8<wchar_t> > strCnv;
	return strCnv.to_bytes(str);
}

std::wstring utf8string2wstring(const std::string& str)
{
	static std::wstring_convert< std::codecvt_utf8<wchar_t> > strCnv;
	return strCnv.from_bytes(str);
}

// string�ı��뷽ʽΪ��utf8����������뷽ʽ���ɲ��ã�
std::string wstring2string(const std::wstring& str, const std::string& locale)
{
	typedef std::codecvt_byname<wchar_t, char, std::mbstate_t> F;
	static std::wstring_convert<F> strCnv(new F(locale));

	return strCnv.to_bytes(str);
}

std::wstring string2wstring(const std::string& str, const std::string& locale)
{
	typedef std::codecvt_byname<wchar_t, char, std::mbstate_t> F;
	static std::wstring_convert<F> strCnv(new F(locale));

	return strCnv.from_bytes(str);
}

// string�ı��뷽ʽΪutf8������ã�
std::string UTF8ToGBK(const std::string& str)
{
	std::wstring wtxt = utf8string2wstring(str);    // ��utf-8��stringת��Ϊwstring
	std::string txt_gbk = wstring2string(wtxt, "Chinese");// �ٽ�wstringת��Ϊgbk��string
	return txt_gbk;
}

// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

bool CWNAnalysisFeature::Read3DFile(const TCollection_AsciiString& filename, const bool doHealing, TopoDS_Shape& result)
{
	bool ret = false;
	char msg[1024];

	// get the file extended name
	TCollection_AsciiString szFN = filename;
	szFN.LowerCase();

	// call asitus function to read file
	if (szFN.EndsWith("stp") || szFN.EndsWith("step")) {
		ret = asiAlgo_STEP::Read(filename, doHealing, result);
	}
	else if (szFN.EndsWith("igs") || szFN.EndsWith("iges")) {
		ret = asiAlgo_IGES::Read(filename, doHealing, result);
	}
	else if (szFN.EndsWith("stl")) {
		ret = StlAPI::Read(result, filename.ToCString());
	}
	else{
		// ��ָ����ʽ��
		return false;
	}

	// Sew part
	TopoDS_Shape sewnPart;
	const double toler = 1e-5;
	// Perform sewing
	sprintf_s(msg, "--[INFO]--  Sewing tolerance = %f", toler);
	Log(msg);


	//	asiAlgo_EXPORT bool CheckShape(const TopoDS_Shape&  shape, ActAPI_ProgressEntry Journal);
	//	ActAPI_ProgressEntry Journal;
	//	bool bCheck = asiAlgo_Utils::CheckShape(result, Journal);
	//

	if (!asiAlgo_Utils::Sew(result, toler, sewnPart)){
		sprintf_s(msg, "----[ERROR]----  sewing failed");
		Log(msg);
		return false;
	}
	result = sewnPart;

	/*
	Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
	sfs->Init(sewnPart);
	sfs->SetPrecision(toler);
	sfs->SetMaxTolerance(1e-2);
	sfs->SetMinTolerance(1e-5);
	sfs->FixWireTool()->FixRemovePCurveMode() = 1;
	sfs->FixWireTool()->FixSmallMode() = 0;
	sfs->FixSolidTool();
	sfs->Perform();
	result = sfs->Shape();
	*/
	return ret;
}

void CWNAnalysisFeature::BatchTestFromDir(char *FileDir)
{
	vector<string> vecFNs;
	getFiles(vecFNs, FileDir, 0);

	for (int i = 0; i < vecFNs.size(); i++)	{
		TestOneObject(vecFNs[i]);
	}
	return;
}

// solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��)
void CWNAnalysisFeature::TestOneObject(string filename)
{
	char msg[10000];
	sprintf_s(msg, "File : %s", filename.c_str());
	Log(msg);

	TopoDS_Shape model;

	clock_t start, finish;
	double  duration;

	start = clock();

	// ��ȡ�ͽ���ģ������
	if (!Read3DFile(filename.c_str(), false, model)){
		sprintf_s(msg, "Invalid model document : %s", filename.c_str());
		Log(msg);
		exit(0);
	}

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	sprintf_s(msg, "--[INFO]--  Read 3D Object From File: %.3f (s)", duration);
	Log(msg);

	if (solution != 1 && solution != 0)	{
		sprintf_s(msg, "Illegal solution parameter : %s", solution);
		Log(msg);
		exit(0);
	}

	// ������ȡ
	start = clock();

	FEATURELIST rFeatureList;
	FEATURELIST rUndefinedList;

	GetFeatureList(model, rFeatureList, rUndefinedList);

	//************************************************************
	string szInfo = solution ? "By EAAGExtraction " : "By VF2 ";// 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��
	//	sprintf_s(msg, "--[INFO]--  Features count %d (%s)  (Face indexing from 0)", rFeatureList.size(), szInfo.c_str());//��ӡƥ�䵽���������
	sprintf_s(msg, "--[INFO]--  Features count %d (%s)", rFeatureList.size(), szInfo.c_str());//��ӡƥ�䵽���������
	Log(msg);

	int i = 1;
	FEATURELIST DFList = GetPreDefinedFeatureDB(); // ��Ԥ������������бȽϡ�
	for (FeaturePart dF : DFList){
		string infoList = "";
		int iParts = 0, iPartsAll = 0;
		for (FeaturePart a : rFeatureList){
			if (strcmp(a.szDes, dF.szDes) == 0){
				infoList += "[";
				for (int j = 0; j < a.nDim; j++)
					infoList = infoList + to_string(a.indexRec[j]) + (j<a.nDim ? "-" : "");
				if (infoList.rfind("-") == infoList.length() - 1)
					infoList = infoList.substr(0, infoList.length() - 1);
				infoList += "]";

				iParts++;
				iPartsAll++;
			}
			if (iParts % 5 == 0) {
				iParts = 0;
				if (infoList.length() > 0)
					infoList += "\n\t\t";
			}
		}
		if (infoList == "")
			;
		else {
			sprintf_s(msg, "No.%02d [%s(%d)]: %s", i++, dF.szDes, iPartsAll, infoList.c_str());
			Log(msg);
		}
	}

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	sprintf_s(msg, "--[INFO]--  Compute 3D Object Features: %.3f (s)", duration);
	Log(msg);

	// ������ȡ
	// ......
}

// solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��)
void CWNAnalysisFeature::Test(string filename,int nSolution,bool dumpEEAG)
{
	szFNOrPath = filename;
	solution = nSolution;
	bDumpEEAG = dumpEEAG;

	// �ļ�Ŀ¼�����ѯ���е��ļ���
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	char szPath[1024];

	_splitpath(filename.c_str(), drive, dir, fname, ext);
	if (strlen(ext) > 0) {
		TestOneObject(filename);
	}
	else{
		sprintf_s(szPath, "%s%s", drive, dir);
		//_makepath(szPath, drive, dir, "*", ext);

		BatchTestFromDir(szPath);
	}
}

void CWNAnalysisFeature::MakeLower(string &szSourc)
{
	for (int j = 0; j < szSourc.size(); j++)
	if (islower(szSourc[j]))//�������±�Ϊj���ַ�ΪСд��ĸ 
		szSourc[j] = toupper(szSourc[j]);
}

// �ݹ������ǰĿ¼�µ������ļ�
void CWNAnalysisFeature::getFiles(vector<string>& files, string path, int layer)
{
	struct _finddata_t   filefind;
	string  curr = path;
	if (curr.rfind("\\") == curr.length() - 1)
		curr += "*.*";
	else
		curr += "\\*.*";

	int   done = 0;
	intptr_t handle;
	if ((handle = _findfirst(curr.c_str(), &filefind)) == -1)
		return;

	while (!(done = _findnext(handle, &filefind))){
		if (!strcmp(filefind.name, ".."))
			continue;

		if ((_A_SUBDIR == filefind.attrib))	{
			if (path.rfind("\\") == path.length() - 1)
				curr = path + filefind.name;
			else
				curr = path + "\\" + filefind.name;;
			getFiles(files, curr, layer + 1);
		}
		else{
			if (path.rfind("\\") == path.length() - 1)
				curr = path + filefind.name;
			else
				curr = path + "\\" + filefind.name;;
			files.push_back(curr);
		}
	}
	_findclose(handle);
}

// ���� Analysis Situs �����ͺͽӿڣ��Զ����ɱ���Ŀ�е� EEAG ���ݽṹ��
EAAG CWNAnalysisFeature::GenerateEAAG(TopoDS_Shape aShape)
{
	// create aag using the asi funcion
	Handle(asiAlgo_AAG) aag = new asiAlgo_AAG(aShape);
	//aag->Dump(std::cout);

	// create the EAAG
	EAAG_Adapter adapter(aag);
	//	if (bDumpEEAG)
	//		DumpEAAGInfo(adapter.convert());

	return adapter.convert();
}

// ���ڸ�������άģ�� crShape������Ԥ�����������ݿ⣬��ѯ��ģ���е��������������浽rFeatureList�У�����δ������������򱣴���rUndefinedList�С�
bool  CWNAnalysisFeature::GetFeatureList(const SHAPE& crShape, FEATURELIST& rFeatureList, FEATURELIST &rUndefinedList)
{
	EAAG rEAAG;
	FEATURELIST candidateFeatureList;

	//getData(rEAAG);
	rEAAG = GenerateEAAG(crShape); // ���� EAAG��

	if (bDumpEEAG)
		print_EAAG(rEAAG);

	vector<FeaturePart> recList;
	FEATURELIST dataFeatureList = GetPreDefinedFeatureDB(); //��ȡԤ����������dataFeatureList

	//solution = 1���㷨A��ȡƥ�䷽����0��VF2ƥ�䷽��
	if (solution == 1){
		ExtractionAllFeatures(rEAAG, candidateFeatureList);            //��ȡ��ѡ����candidateFeatureList

		//print_FeatureList(candidateFeatureList);

		for (FeaturePart aFeature : candidateFeatureList){                //��һƥ��
			string name("δ֪");
			EAAG EAAG_toMatch;
			EAAG_toMatch.nDim = aFeature.nDim;
			EAAG_toMatch.elem = aFeature.elem;

			if (FeatureMatchingFromDB(EAAG_toMatch, dataFeatureList, name)) {            //ƥ���ϵļ�¼
				//cout << "find a Feature matches " << name << endl;
				int i;
				for (i = 0; i < name.length(); i++)
					aFeature.szDes[i] = name[i];
				aFeature.szDes[i] = '\0';
				recList.push_back(aFeature);
			}
			else                                                                       //ƥ�䲻�ϵķŵ�δʶ�����
				rUndefinedList.push_back(aFeature);
		}
	}
	else if (solution == 0) {                          //vf2����ƥ��
		string name("δ֪");                       //EAAG��������ƥ��
		EAAG EAAG_toMatch;
		EAAG_toMatch.nDim = rEAAG.nDim;
		EAAG_toMatch.elem = rEAAG.elem;
		if (FeatureMatchingFromDB(EAAG_toMatch, dataFeatureList, name)){
			FeaturePart aFeature;
			aFeature.nDim = rEAAG.nDim;
			aFeature.elem = rEAAG.elem;
			int i;
			for (i = 0; i <= name.length(); i++)
				aFeature.szDes[i] = name[i];
			aFeature.szDes[i] = '\0';
			aFeature.indexRec = new int[rEAAG.nDim + 1];
			for (int i = 1; i <= rEAAG.nDim; i++)
				aFeature.indexRec[i] = i;
			recList.push_back(aFeature);
		}

		for (FeaturePart aFeature : dataFeatureList)      //������VF2ƥ��
			VF2_Matching(rEAAG, aFeature, recList);
	}

	featureDisRepetition(recList, rFeatureList);  //����ȥ��
	//for (FeaturePart aF : recList)                //��ȥ�أ�����ƥ����
	//rFeatureList.push_back(aF);

	return true;
}

void CWNAnalysisFeature::print_EAAG(EAAG rEAAG)
{
	for (int i = 1; i <= rEAAG.nDim; i++) {
		for (int j = 1; j <= rEAAG.nDim; j++) {
			cout << setw(5) << rEAAG.elem[i][j].A_ii;
		}
		cout << endl;
	}
}

void CWNAnalysisFeature::print_FeatureList(FEATURELIST rFeatureList)
{
	for (FeaturePart aFeature : rFeatureList){
		cout << "��-������ţ� ";
		for (int i = 1; i <= aFeature.nDim; i++)
			cout << aFeature.indexRec[i] << " ";
		cout << endl;
		for (int i = 1; i <= aFeature.nDim; i++){
			for (int j = 1; j <= aFeature.nDim; j++){
				printf("%d\t", aFeature.elem[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

bool CWNAnalysisFeature::GenerateFeatureMatrix()
{
	return true;
/*
	//------------------------------------------------------
	int matrix1_1[][3] = { { 11, 10, 10 },
	{ 10, 11, 0 },
	{ 10, 0, 11 } };
	DBFeaturesList.push_back(package(3, "ͨ��1", (int*)matrix1_1));
	int matrix1_2[][3] = { { 10, 10, 0 },
	{ 10, 10, 10 },
	{ 0, 10, 10 } };
	DBFeaturesList.push_back(package(3, "ͨ��2", (int*)matrix1_2));

	//------------------------------------------------------
	int matrix2[][4] = { { 11, 10, 10, 10 }, { 10, 11, 0, 10 }, { 10, 0, 11, 10 }, { 10, 10, 10, 11 } };
	DBFeaturesList.push_back(package(4, "ä��", (int*)matrix2));

	//------------------------------------------------------
	int matrix3[][2] = { { 11, 10 }, { 10, 11 } };
	DBFeaturesList.push_back(package(2, "̨��", (int*)matrix3));

	//------------------------------------------------------
	int matrix4[][3] = { { 11, 10, 10 }, { 10, 11, 10 }, { 10, 10, 11 } };
	DBFeaturesList.push_back(package(3, "ą̈��", (int*)matrix4));

	//------------------------------------------------------
	int matrix5_1[][3] = { { 20, 21, 21 },
	{ 21, 11, 0 },
	{ 21, 0, 11 } };
	DBFeaturesList.push_back(package(3, "ͨ��1", (int*)matrix5_1));
	int matrix5_2[][3] = { { 11, 21, 0 },
	{ 21, 20, 0 },
	{ 0, 0, 21 } };
	DBFeaturesList.push_back(package(3, "ͨ��2", (int*)matrix5_2));
	//	int matrix5_3[][2] = {	{ 11, 0 },
	//							{  0, 21 } };
	//	DBFeaturesList.push_back(package(2, "ͨ��3", (int*)matrix5_2));

	//------------------------------------------------------
	int matrix6_1[][2] = { { 11, 20 },
	{ 20, 20 } };
	DBFeaturesList.push_back(package(2, "ä��1", (int*)matrix6_1));

	//------------------------------------------------------
	int matrix7_1[][2] = { { 20, 20 },
	{ 20, 30 } };
	DBFeaturesList.push_back(package(2, "ä׶��1", (int*)matrix7_1));
	int matrix7_2[][4] = { { 20, 20, 0, 10 },
	{ 20, 30, 10, 0 },
	{ 0, 10, 30, 20 },
	{ 10, 0, 20, 20 } };
	DBFeaturesList.push_back(package(4, "ä׶��2", (int*)matrix7_2));

	//------------------------------------------------------
	int matrix8[][5] = { { 11, 10, 10, 20, 20 }, { 10, 11, 0, 10, 10 }, { 10, 0, 11, 10, 10 }, { 20, 10, 10, 20, 0 }, { 20, 10, 10, 0, 20 } };
	DBFeaturesList.push_back(package(5, "����", (int*)matrix8));

	//------------------------------------------------------
	int matrix9[][5] = { { 11, 10, 10, 10, 10 }, { 10, 11, 10, 0, 10 }, { 10, 10, 11, 10, 0 }, { 10, 0, 10, 11, 10 }, { 10, 10, 0, 10, 11 } };
	DBFeaturesList.push_back(package(5, "��ǻ", (int*)matrix9));

	//------------------------------------------------------
	int matrix10_1[][3] = { { 11, 21, 0 },
	{ 21, 31, 21 },
	{ 0, 21, 21 } };
	DBFeaturesList.push_back(package(3, "����1", (int*)matrix10_1));
	int matrix10_2[][4] = { { 20, 20, 0, 0 },
	{ 20, 120, 20, 0 },
	{ 0, 20, 40, 20 },
	{ 0, 0, 20, 40 } };
	DBFeaturesList.push_back(package(4, "����2", (int*)matrix10_2));
	int matrix10_3[][4] = { { 21, 21, 0, 0 },
	{ 21, 121, 21, 0 },
	{ 0, 21, 41, 21 },
	{ 0, 0, 21, 41 } };
	DBFeaturesList.push_back(package(4, "����3", (int*)matrix10_3));

	//------------------------------------------------------
	int matrix11_1[][3] = { { 11, 21, 0 },
	{ 21, 21, 21 },
	{ 0, 21, 11 } };
	DBFeaturesList.push_back(package(3, "Բ����1", (int*)matrix11_1));
	int matrix11_2[][3] = { { 21, 21, 0 },
	{ 21, 11, 0 },
	{ 0, 0, 21 } };
	DBFeaturesList.push_back(package(3, "Բ����2", (int*)matrix11_2));

	//------------------------------------------------------
	int matrix12[][3] = { { 11, 21, 0 }, { 21, 31, 21 }, { 0, 21, 11 } };
	DBFeaturesList.push_back(package(3, "Բ׶��", (int*)matrix12));

	return true
*/
}

bool CWNAnalysisFeature::GenerateFeatureMatrixFromXMLFile()
{
#ifdef _DEBUG
	char xmlFN[] = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/FeatureDB.xml";
#else
	char xmlFN[] = "FeatureDB.xml";
#endif
	xmlDocPtr doc;   // xml�����ĵ������νṹ
	xmlNodePtr cur;  // xml�ڵ�
	xmlChar *id_feature;     // feature id

	// ��ȡ���νṹ
	doc = xmlParseFile(xmlFN);
	if (doc == NULL) {
		fprintf(stderr, "Failed to parse xml file:%s\n", xmlFN);
		return false;
	}

	// ��ȡ���ڵ�
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr, "Root is empty.\n");
		return false;
	}

	if ((xmlStrcmp(cur->name, (const xmlChar *)"WNFeature"))) {
		fprintf(stderr, "The root is not WNFeature.\n");
		return false;
	}

	// ����������ڵ��ÿһ���ӽڵ�
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"Feature"))) {
			xmlChar propName[] = "id";
			id_feature = xmlGetProp(cur, propName);
#ifdef _DEBUG
			printf("��id��:%s\t", id_feature);
#endif
			parse_feature(doc, cur);
		}
		cur = cur->next;
	}
	xmlFreeDoc(doc);

	//------------------------------------------------------
#ifdef _DEBUG
	DumpPreDefinedFeatures(DBFeaturesList);
#endif

	return true;
}

void CWNAnalysisFeature::DumpPreDefinedFeatures(FEATURELIST rFeatureList)
{
	cout << "======= Dump Predefined Features =======\n";
	for (FeaturePart aFeature : rFeatureList){
		cout << aFeature.szDes << endl;
		for (int i = 0; i < aFeature.nDim; i++){
			for (int j = 0; j < aFeature.nDim; j++){
				if (i == j)
					printf("%d\t", (eFaceType)(int)(aFeature.elem[i][j].A_ii));
				else
					printf("%d\t", (eCurveType)(int)(aFeature.elem[i][j].A_ij));
			}
			printf("\n");
		}
		printf("\n");
	}

}

void CWNAnalysisFeature::PrintFeatureMatrix(int *matrix, int nDimSize)
{
	printf("======= Dump Feature Matrix =======\n");
	for (int i = 0; i < nDimSize; i++) {
		printf("\t\t");
		for (int j = 0; j < nDimSize; j++){
			printf("%d\t", matrix[i*nDimSize+j]);
		}
		printf("\n");
	}
	printf("\n");
}

// ����ÿһ���������壬��ȡ��name��dim��row info�������浽һ����ά�����С�
bool CWNAnalysisFeature::parse_feature(xmlDocPtr doc, xmlNodePtr cur)
{
	int nDimSize = 0;
	assert(doc || cur);
	xmlChar *key;
	std::string szFeatureDes;

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		// ��ȡname
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"Name"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			szFeatureDes = UTF8ToGBK(((char*)key));
#ifdef _DEBUG
			printf("��Name��: %s\t", szFeatureDes.c_str());
#endif
			xmlFree(key);
		}
		// ��ȡdim
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"nDim"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
#ifdef _DEBUG
			printf("��nDim��: %s\t", key);
#endif
			nDimSize = atol((char*)key);
			xmlFree(key);
		}
		// ��ȡ������Ϣ
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"Matrix"))) {
			int *matrix = NULL;
			matrix = (int *)malloc(sizeof(int)*nDimSize*nDimSize);
			xmlNodePtr curNode;  // xml�ڵ�
			xmlChar *id_row;     // matrix row id
			xmlChar *key_row;
			curNode = cur->xmlChildrenNode;
			while (curNode != NULL) {
				if ((!xmlStrcmp(curNode->name, (const xmlChar *)"Row")))
				{
					id_row = xmlGetProp(curNode, (const xmlChar *)"id");
#ifdef _DEBUG
					//printf("[%s]: ", id_row);
#endif
					key_row = xmlNodeListGetString(doc, curNode->xmlChildrenNode, 1);
#ifdef _DEBUG
					//printf("%s\t", key_row);
#endif

					//ѭ������Ҫ��ֵ��ַ���s1��ÿ��ѭ�����±�0���ո�ǰһ��λ�õ������ַ�����������
					//ת�������ּӵ������У���ɾ��s1���Ѿ�����������ַ�������һ���ո�
					string s1 = (char*)(key_row);  //Ҫ��ֵ��ַ���
					vector<int> res;
					int jCol = 0;
					while (!s1.empty()){
						if (s1.find(" ") == string::npos){ //���û�пո��ˣ���ֻʣ�����һ�������ַ���ת��Ϊ���ּ������鲢����ַ�����ʹѭ������
							matrix[(atoi((char*)id_row) - 1)*nDimSize+jCol] = stoi(s1);
							jCol++;
							s1.clear();
							break;
						}
						string s_temp = s1.substr(0, s1.find(" "));
						matrix[(atoi((char*)id_row) - 1)*nDimSize + jCol] = stoi(s_temp);
						jCol++;

						s1.erase(0, s1.find(" ") + 1); //Ҫɾ���ո�����Ҫs.find(" ") + 1
					}

					xmlFree(key_row);
				}
				curNode = curNode->next;
			}

			DBFeaturesList.push_back(package(nDimSize, (char*)(szFeatureDes.c_str()), matrix));
#ifdef _DEBUG
			printf("\n");
			PrintFeatureMatrix(matrix, nDimSize);
#endif
		}
		cur = cur->next;
	}
	return 0;
}

//FeaturePart CWNAnalysisFeature::package(int dim, char * name, int* matrix)
FeaturePart CWNAnalysisFeature::package(int dim, char * name, int* matrix)
{
	FeaturePart aFeature;

	aFeature.nDim = dim;
	strcpy_s(aFeature.szDes, name);
	aFeature.indexRec = NULL;
	aFeature.elem = new uElemType*[dim];
	for (int i = 0; i < dim; i++)
		aFeature.elem[i] = new uElemType[dim];

	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (i == j) {
				aFeature.elem[i][j].A_ii = (eFaceType)matrix[i*dim+j];
#ifdef _DEBUG
				printf("%d\t", aFeature.elem[i][j].A_ii);
#endif
			}else{
				aFeature.elem[i][j].A_ij = (eCurveType)matrix[i*dim + j];
#ifdef _DEBUG
				printf("%d\t", aFeature.elem[i][j].A_ij);
#endif
			}
		}
		printf("\n");
	}
	return aFeature;
}


bool CWNAnalysisFeature::FeatureMatchingFromDB(const EAAG & rEAAG, const FEATURELIST & rFeatureList, string& name)
{
	int m = rEAAG.nDim;
	bool find_featureMatch = false;
	for (FeaturePart aFeature : rFeatureList) {     //ά�ȡ�������ɸѡ + ������׼
		if ((aFeature.nDim == m)) {
			int *rowList = new int[m + 1];
			if (row_matrixMatch(rEAAG.elem, aFeature.elem, m, rowList)) {
				EAAG swappedGraph = swapMatrix(rEAAG, rowList);

				if (matrixMatch(aFeature.elem, swappedGraph.elem, m)) {
					find_featureMatch = true;
					name = aFeature.szDes;
					break;
				}
			}
			delete(rowList);
		}
	}

	return find_featureMatch;
}

bool CWNAnalysisFeature::row_matrixMatch(uElemType ** queryMatrix, uElemType ** dataMatrix, int dim, int* rowList) //�����������ж�
{
	for (int i = 1; i <= dim; i++)       //���dataMatrix�п�������ƥ����У�����¼ƥ���λ��
		rowList[i] = -1;

	for (int i = 1; i <= dim; i++) {
		int find_rowMatch = -1;
		for (int j = 1; j <= dim; j++) {
			if (rowList[j] == -1 && rowMatch(queryMatrix[i], dataMatrix[j], dim)){
				find_rowMatch = j;
				break;
			}
		}
		if (find_rowMatch == -1)
			return false;
		else
			rowList[find_rowMatch] = i;
	}
	return true;
}

bool CWNAnalysisFeature::rowMatch(uElemType * queryRow, uElemType * dataRow, int dim)
{
	bool *rowlist = new bool[dim + 1];      //���dataRow�п�������ƥ�������
	for (int i = 1; i <= dim; i++)
		rowlist[i] = true;

	for (int i = 1; i <= dim; i++) {
		int find_rowMatch = -1;
		for (int j = 1; j <= dim; j++) {
			if (rowlist[j] && queryRow[i].A_ii == dataRow[j].A_ii){
				find_rowMatch = j;
				break;
			}
		}
		if (find_rowMatch == -1) {
			delete(rowlist);
			return false;
		}
		else
			rowlist[find_rowMatch] = false;
	}
	delete(rowlist);
	return true;
}

EAAG CWNAnalysisFeature::swapMatrix(EAAG rEAAG, int *rowList)
{
	int dim = rEAAG.nDim;
	int temp;

	EAAG copyEAAG;                                  //����һ���������ڽ���
	copyEAAG.nDim = dim;
	copyEAAG.elem = new uElemType*[dim + 1];
	for (int i = 1; i <= dim; i++)
		copyEAAG.elem[i] = new uElemType[dim + 1];
	for (int i = 1; i <= dim; i++)
	for (int j = 1; j <= dim; j++)
		copyEAAG.elem[i][j].A_ii = rEAAG.elem[i][j].A_ii;


	for (int i = 1; i <= dim; i++) {    //��dataMatrix�ĽǶȣ�����У׼
		if (rowList[i] != i) {
			for (int j = 1; j <= dim; j++){ //�е���
				temp = copyEAAG.elem[i][j].A_ii;
				copyEAAG.elem[i][j].A_ii = copyEAAG.elem[rowList[i]][j].A_ii;
				copyEAAG.elem[rowList[i]][j].A_ii = (eFaceType)temp;
			}
			for (int j = 1; j <= dim; j++){ //�е���
				temp = copyEAAG.elem[j][i].A_ii;
				copyEAAG.elem[j][i].A_ii = copyEAAG.elem[j][rowList[i]].A_ii;
				copyEAAG.elem[j][rowList[i]].A_ii = (eFaceType)temp;
			}

			for (int j = 1; j <= dim; j++){  //�����������rowList���ƶ�Ӧ��ϵ
				if (rowList[j] == i){
					rowList[j] = rowList[i];
					rowList[i] = i;
					break;
				}
			}
		}
	}
	//print_uElemTypeMatrix(copyEAAG.elem, copyEAAG.nDim);
	return copyEAAG;
}

bool CWNAnalysisFeature::matrixMatch(uElemType **dataMatrix, uElemType **queryMatrix, int m)
{
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= m; j++){
			if (dataMatrix[i][j].A_ii != queryMatrix[i][j].A_ii)
				return false;
		}
	}
	return true;
}

void CWNAnalysisFeature::print_uElemTypeMatrix(uElemType **matrix, int m)
{
	for (int i = 1; i <= m; i++)	{
		for (int j = 1; j <= m; j++)		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

class Comparator : public AttrComparator
{
public:
	Comparator()
	{	}

	virtual bool compatible(void *pa, void *pb) {       //ƥ�䣺�ߺ���������ֵ���
		int *a = (int *)pa;
		int *b = (int *)pb;
		return *a == *b;
	}
};

struct matchPair
{
	node_id n1;
	node_id n2;
};

bool my_visitor(int n, node_id ni1[], node_id ni2[], void *usr_data)          //ƥ�������溯����match�ڲ���
{
	vector<matchPair> *f = (vector<matchPair> *)usr_data;

	// Prints the matched pairs on the file
	int i;
	for (i = 0; i < n; i++)	{
		matchPair aMatchPair;
		aMatchPair.n1 = ni1[i];
		aMatchPair.n2 = ni2[i];
		(*f).push_back(aMatchPair);
	}
	// Return false to search for the next matching
	return false;
}

int judgeContain(FeaturePart F1, FeaturePart F2)            //�Ƿ����������������,���񷵻�-1����ǰ�߰������ߣ�����0�������߰���ǰ�ߣ�����1��
{
	if (F1.nDim < F2.nDim)	{
		for (int i = 0; i < F1.nDim; i++){
			bool exist = false;
			for (int j = 0; j < F2.nDim; j++){
				if (F2.indexRec[j] == F1.indexRec[i]){
					exist = true;
					break;
				}
			}
			if (!exist)
				return -1;
		}
		return 1;
	}
	else{
		for (int i = 0; i < F2.nDim; i++){
			bool exist = false;
			for (int j = 0; j < F1.nDim; j++){
				if (F1.indexRec[j] == F2.indexRec[i]){
					exist = true;
					break;
				}
			}
			if (!exist)
				return -1;
		}
		return 0;
	}

	return -1;
}

bool CWNAnalysisFeature::VF2_Matching(const EAAG rEAAG, const FeaturePart aFeature, vector<FeaturePart>& recList)
{
	ARGEdit ed1, ed2;

	for (int i = 1; i <= aFeature.nDim; i++) {     //��EAAG������ͼת��ΪARGͼ��ʽ
		ed1.InsertNode(&aFeature.elem[i][i]);
		for (int j = 1; j <= aFeature.nDim; j++){
			ed1.InsertEdge(i, j, &aFeature.elem[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= rEAAG.nDim; i++) {
		ed2.InsertNode(&rEAAG.elem[i][i]);
		for (int j = 1; j <= rEAAG.nDim; j++) {
			if (i != j)
				ed2.InsertEdge(i, j, &rEAAG.elem[i][j]);
		}
	}


	ARGraph<int, int> g1(&ed1);
	ARGraph<int, int> g2(&ed2);

	// Install the attribute comparator
	// This needs to be done only on graph g1.
	g1.SetNodeComparator(new Comparator());             //��Ʊߺ���ƥ��ȽϷ���
	g1.SetEdgeComparator(new Comparator());

	VF2SubState s0(&g1, &g2);

	vector<matchPair> rec;
	if (!match(&s0, my_visitor, &rec))              //�������ܹ�ƥ���ϵ�������ͼ
		return false;
	else{                                            //����
		int n = rec.size() / aFeature.nDim;         //ƥ���ϵ�������ͼ��Ŀ
		for (int i = 1; i <= n; i++) {                //��ÿһ��ƥ���ϵ�������ͼ�����������ṹ��Ϊ��һ������ȥ����׼��
			vector<int> rowList;
			for (int j = 1; j <= aFeature.nDim; j++){
				rowList.push_back(rec[(i - 1)*aFeature.nDim + (j - 1)].n2);
				//cout << rec[i*aFeature.nDim+j].n1 << "match" << rec[i*aFeature.nDim+j].n2 << endl;
			}

			FeaturePart aFeaturePart = createFeaturePart(rEAAG, rowList, aFeature.szDes);

			recList.push_back(aFeaturePart);

			rowList.clear();
		}
	}
	return true;
}


void CWNAnalysisFeature::featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList)           //������������ȥ��
{
	int i = 0;

	while (!recList.empty()){                            //����ȥ��
		FeaturePart headFeature = recList[0];

		int store = true;
		vector<FeaturePart>::iterator it = recList.begin();
		it++;      //Խ����һ��

		int j = 0;
		while (it != recList.end())
		{
			int res = judgeContain(headFeature, (*it));  //�Ƿ����������������,���񷵻�-1����ǰ�߰������ߣ�����0�������߰���ǰ�ߣ�����1��

			if (res == 1){
				store = false;
				recList.erase(recList.begin());       //ɾ����ʼ�����¿�ʼ
				break;
			}
			else if (res == 0)
				it = recList.erase(it);
			else
				it++;
		}

		if (store){
			rFeatureList.push_back(headFeature);
			recList.erase(recList.begin());
		}
	}
}


/*
void featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList)           //������������ȥ��
{
	while (!recList.empty())                            //����ȥ��
	{
	FeaturePart headFeature = recList[0];

	int store = true;
	vector<FeaturePart>::iterator it = recList.begin();

	for (int i = 1; i < recList.size(); i++)
	{
	it++;  //Խ����һ��
	int res = judgeContain(headFeature, (*it));     //�Ƿ����������������,���񷵻�-1����ǰ�߰������ߣ�����0�������߰���ǰ�ߣ�����1��

	if (res == 1)
	{
	store = false;
	recList.erase(recList.begin());       //ɾ����ʼ�����¿�ʼ
	break;
	}
	else if (res == 0)
	{
	recList.erase(it);
	i--;
	it--;
	}
	}

	if (store)
	{
	rFeatureList.push_back(headFeature);
	recList.erase(recList.begin());
	}

	}
}*/
