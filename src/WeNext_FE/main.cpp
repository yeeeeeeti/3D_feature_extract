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

#include "dataFormat.h"

#include <StlAPI.hxx>
#include <assert.h>

#include "logger.cpp"

#include "WNAnalysisFeature.h"

using namespace std;

#ifdef TEST
void TestXML()
{
	CWNAnalysisFeature anal("test");

	int mytest = 0;
}
#endif

int main(int argc, char *argv[])
{
#ifdef TEST
	TestXML();
	return 0;
#endif

#ifndef _DEBUG
	bool bDumpEEAG = false;
#else
	bool bDumpEEAG = true;
#endif

	int solution = 0; //solution = 1����ȡƥ�䷽����0��VF2ƥ�䷽������Ĭ��VF2����ʶ��
	string filename;       //��άģ��·��

#ifdef _DEBUG
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
			bDumpEEAG = true;
		}
		CWNAnalysisFeature anal(filename);
		anal.Test(filename, solution, bDumpEEAG);
		
		
		system("pause");
	}
	else {
		cerr << "Useage:\n" << argv[0] << " FILEPATH [0|1]" << endl;
		
		exit(0);
	}

#else
		//////////////////////////////////////////////////////////////////////////
		// test
		solution = 0;
		//filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/TestData/STEP/1951211.STEP";
		filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/data/STEP/Feature/fe_DaoLeng_1.stp"; 
		//filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/data/STEP/01_38180166_2087010.STEP"; 
		//filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/data/STEP/daoleng2.STP"; 
		//filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/data/STEP/16_36635948_1950926.STEP";
		//filename = "D:/WeNext3D/AnalysisSitus-v0.3.0/win64/vc12/bind/TestData/STEP/test1.STEP";
		//////////////////////////////////////////////////////////////////////////
		CWNAnalysisFeature anal(filename);
		anal.Test(filename, solution, bDumpEEAG);

#endif


	system("pause");
	return 0;
}




