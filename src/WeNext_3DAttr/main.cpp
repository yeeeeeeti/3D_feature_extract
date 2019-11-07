# pragma warning (disable:4819)

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

#include <asiAlgo_IGES.h>
#include <asiAlgo_STEP.h>
#include <asiAlgo_Utils.h>
#include <ShapeFix_Shape.hxx>

#include <StlAPI.hxx>

using namespace std;

#include "logger.cpp"

bool debug = false;
void ShowAttributes(TopoDS_Shape shape, ostream &out); //�������ͱ����
bool Read3DFile(const TCollection_AsciiString& filename, const bool doHealing, TopoDS_Shape& result, int solution); // ��ȡģ���ļ�

void TestOneObject(string filename, int solution);
void BatchTestFromDir(char *szPath, int solution);

int main(int argc, char *argv[])
{
	int solution = 0; //solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��
	string filename;       //��άģ��·��

	// ���������в���
	if (argc >= 2)	{
		// �Ӳ����л�ȡ�ļ���
		filename = argv[1];

		// �Ӳ����л�ȡ����
		if (argc >= 3)
			solution = atoi(argv[2]);

		if (solution != 1 && solution != 0)	{
			cerr << "Illegal solution parameter :" << argv[2] << endl;
			exit(0);
		}

		// ����ģʽ
		if (argc == 4) {
			//cout << "***** DEBUG MODE *****" << endl;
			debug = true;
		}
		TestOneObject(filename, solution);
	} else {
		cerr << "Useage:\n" << argv[0] << " FILEPATH [0|1]" << endl;
		exit(0);
	}

	system("pause");
	return 0;
}


bool Read3DFile(const TCollection_AsciiString& filename,
				const bool						doHealing,
				TopoDS_Shape&					result,
				int								solution
				)
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
		// �ļ�Ŀ¼�����ѯ���е��ļ���
		char drive[_MAX_DRIVE];
		char dir[_MAX_DIR];
		char fname[_MAX_FNAME];
		char ext[_MAX_EXT];
		char szPath[1024];

		_splitpath(filename.ToCString(), drive, dir, fname, ext);
		if (strlen(ext) > 0)
			return false;

		sprintf_s(szPath, "%s%s", drive, dir);
		//_makepath(szPath, drive, dir, "*", ext);

		BatchTestFromDir(szPath, solution);
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

void TestOneObject(string filename,
					int solution  //solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��
					)
{
	char msg[1024];
	sprintf_s(msg, "File : %s", filename.c_str());
	Log(msg);

	TopoDS_Shape model;

	clock_t start, finish;
	double  duration;

	start = clock();

	// ��ȡ�ͽ���ģ������
	if (!Read3DFile(filename.c_str(), false, model, solution)){
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

	// ��������ͱ��������Χ��
	start = clock();

	ShowAttributes(model, cout);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	sprintf_s(msg, "--[INFO]--  Compute 3D Object attribution: %.3f (s)", duration);
	Log(msg);

	// ������ȡ
	// ......
}

