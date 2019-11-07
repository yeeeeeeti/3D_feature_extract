
#include "WNAnalysisFeature_IncSetup.h"


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
		//ret = asiAlgo_STEP::Read(filename, doHealing, result);
		ActAPI_ProgressEntry progress;
		asiAlgo_STEP stp(progress);
		ret = stp.Read(filename, doHealing, result);
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

	szFNOrPath = filename;

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR*2];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	char szPath[1024];
	_splitpath(filename.c_str(), drive, dir, fname, ext);
	sprintf_s(szPath, "%s%s%s_AAG.dat", drive, dir, fname);
	szFN_AAG = szPath;
	sprintf_s(szPath, "%s%s%s_EAAG.dat", drive, dir, fname);
	szFN_EAAG = szPath;

	TopoDS_Shape model;

	clock_t start, finish;
	double  duration;

	start = clock();

	// ��ȡ�ͽ���ģ������
	if (!Read3DFile(filename.c_str(), true, model)){
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

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	//************************************************************
	string szInfo = solution ? "By EAAGExtraction " : "By VF2 ";// 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��
	//	sprintf_s(msg, "--[INFO]--  Features count %d (%s)  (Face indexing from 0)", rFeatureList.size(), szInfo.c_str());//��ӡƥ�䵽���������
	sprintf_s(msg, "--[INFO]--  Features count %d (%s)", rFeatureList.size(), szInfo.c_str());//��ӡƥ�䵽���������
	Log(msg);

	sprintf_s(msg, "--[INFO]--  Compute 3D Object Features: %.3f (s)", duration);
	Log(msg);

	DumpSearchedFeatures_V2(rFeatureList); // ��ʽ����ʱ����ע�͵���

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
		sprintf_s(szPath, "%s%s%s", drive, dir, fname);
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
EAAG CWNAnalysisFeature::GenerateEAAG(const TopoDS_Shape &aShape)
{
	// create aag using the asi funcion
	Handle(asiAlgo_AAG) aag = new asiAlgo_AAG(aShape);// , false, 1.e-4, asiAlgo_AAG::CachedMap_All);
#ifdef _DEBUG
	//aag->Dump(std::cout);

//	fstream  afile;
//	afile.open(szFN_AAG.c_str(), ios::out | ios::in);
	
	//������д���ļ�
	if (bDumpEEAG){
		ofstream  afile(szFN_AAG.c_str());
		aag->Dump(afile);
		afile.close();
	}
	
#endif
	
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







	if (bDumpEEAG) {
		ofstream  afile(szFN_EAAG.c_str());
		if (afile) {
			//������д���ļ�
			DumpEAAG(afile, rEAAG);
			afile.close();
		}
	}

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
			for (int i = 0; i < rEAAG.nDim; i++)
				aFeature.indexRec[i] = i+1;
			recList.push_back(aFeature);
		}

		for (FeaturePart aFeature : dataFeatureList){      //������VF2ƥ��
			//vector<FeaturePart> recList1;
			VF2_Matching(rEAAG, aFeature, recList);
			/*
			 for (int i = 0; i < recList1.size(); i++) {
				 FeaturePart feature = recList1[i];
				 recList.push_back(feature);
			}*/
		}
	}

	featureDisRepetition(recList, rFeatureList);  //����ȥ��

	//for (FeaturePart aF : recList)                //��ȥ�أ�����ƥ����
	//rFeatureList.push_back(aF);

	return true;
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

	char msg[1024];
	// ��ȡ���νṹ
	doc = xmlParseFile(xmlFN);
	if (doc == NULL) {
		sprintf_s(msg, "--[INFO]--  Failed to parse xml file : %s\n", xmlFN);
		Log(msg);
		return false;
	}

	// ��ȡ���ڵ�
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		sprintf_s(msg, "--[INFO]--  Root is empty.\n");
		Log(msg);
		return false;
	}

	if ((xmlStrcmp(cur->name, (const xmlChar *)"WNFeature"))) {
		sprintf_s(msg, "--[INFO]--  The root is not WNFeature.\n");
		Log(msg);
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
			printf("Name: %s ;  ", szFeatureDes.c_str());
#endif
			xmlFree(key);
		}
		// ��ȡdim
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"nDim"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
#ifdef _DEBUG
			printf("Dim = %s\n", key);
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
					istringstream line(s1);
					string tmp;
					while (line >> tmp){
						matrix[(atoi((char*)id_row) - 1)*nDimSize + jCol] = stoi(tmp);
						jCol++;
					}
					//while (!s1.empty()){
					//	if (s1.find(" ") == string::npos){ //���û�пո��ˣ���ֻʣ�����һ�������ַ���ת��Ϊ���ּ������鲢����ַ�����ʹѭ������
					//		matrix[(atoi((char*)id_row) - 1)*nDimSize+jCol] = stoi(s1);
					//		jCol++;
					//		s1.clear();
					//		break;
					//	}
					//	string s_temp = s1.substr(0, s1.find(" "));
					//	matrix[(atoi((char*)id_row) - 1)*nDimSize + jCol] = stoi(s_temp);
					//	jCol++;

					//	s1.erase(0, s1.find(" ") + 1); //Ҫɾ���ո�����Ҫs.find(" ") + 1
					//}

					xmlFree(key_row);
				}
				curNode = curNode->next;
			}

			DBFeaturesList.push_back(package(nDimSize, (char*)(szFeatureDes.c_str()), matrix));
#ifdef _DEBUG
			PrintFeatureMatrix(matrix, nDimSize, szFeatureDes);
#endif
		}
		cur = cur->next;
	}
	return 0;
}

// FeaturePart CWNAnalysisFeature::package(int dim, char * name, int* matrix)
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
//				printf("%d\t", aFeature.elem[i][j].A_ii);
#endif
			}else{
				aFeature.elem[i][j].A_ij = (eCurveType)matrix[i*dim + j];
#ifdef _DEBUG
//				printf("%d\t", aFeature.elem[i][j].A_ij);
#endif
			}
		}
#ifdef _DEBUG
//		printf("\n");
#endif
	}
	return aFeature;
}



