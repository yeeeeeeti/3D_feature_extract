
#include "WNAnalysisFeature_IncSetup.h"

extern std::string wstring2utf8string(const std::wstring& str);

void CWNAnalysisFeature::DumpEAAG(Standard_OStream &out, EAAG rEAAG)
{
	out << rEAAG.nDim << endl;
	out << szFNOrPath.c_str() << endl;
	for (int i = 0; i < rEAAG.nDim; i++) {
		out << setw(5) << i+1;
	}
	out << endl;

	for (int i = 0; i < rEAAG.nDim; i++) {
		for (int j = 0; j < rEAAG.nDim; j++) {
			out << setw(5) << rEAAG.elem[i][j].A_ii;
		}
		out << endl;
	}
}

void CWNAnalysisFeature::print_FeatureList(FEATURELIST rFeatureList)
{
	for (FeaturePart aFeature : rFeatureList){
		cout << "面-索引编号： ";
		for (int i = 0; i < aFeature.nDim; i++)
			cout << aFeature.indexRec[i] << " ";
		cout << endl;
		for (int i = 0; i < aFeature.nDim; i++){
			for (int j = 0; j < aFeature.nDim; j++){
				printf("%d\t", aFeature.elem[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void CWNAnalysisFeature::DumpPreDefinedFeatures(FEATURELIST rFeatureList)
{
	cout << "===== Dump Predefined Features =====\n";
	for (FeaturePart aFeature : rFeatureList){
		cout << "\t****** 【" << aFeature.szDes << "】 ******" << endl;
		for (int i = 0; i < aFeature.nDim; i++){
			printf("\t");
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
	cout << "===== ~Dump Predefined Features =====\n";
}

void CWNAnalysisFeature::PrintFeatureMatrix(int *matrix, int nDimSize, string szFeatureName)
{
	printf("\t---- Feature Matrix【%s】----\n", szFeatureName.c_str());
	for (int i = 0; i < nDimSize; i++) {
		printf("\t\t");
		for (int j = 0; j < nDimSize; j++){
			printf("%d\t", matrix[i*nDimSize + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void CWNAnalysisFeature::print_uElemTypeMatrix(uElemType **matrix, int m)
{
	for (int i = 0; i < m; i++)	{
		for (int j = 0; j < m; j++)		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void CWNAnalysisFeature::DumpSearchedFeatures(FEATURELIST &rFeatureList)
{
	char msg[4096];

	int i = 1;

	FEATURELIST DFList = GetPreDefinedFeatureDB(); // 与预定义特征库进行比较。
	for (FeaturePart dF : DFList){
		string infoList = "";
		int iParts = 0, iPartsAll = 0;
		for (FeaturePart a : rFeatureList){
			if (strcmp(a.szDes, dF.szDes) == 0){
				infoList += "[";
				for (int j = 0; j < a.nDim; j++)
					infoList = infoList + to_string(a.indexRec[j] + 1) + (j<a.nDim ? "-" : "");
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
		else
		{
			sprintf_s(msg, "--------------------------------------------------------------");
			Log(msg);
			sprintf_s(msg, "No.%02d [%s(%d)]: %s", i++, dF.szDes, iPartsAll, infoList.c_str());
			Log(msg);
		}
	}

}

void CWNAnalysisFeature::DumpSearchedFeatures_V2(FEATURELIST &rFeatureList)
{
	char msg[1024];

	int i = 1;

	FEATURELIST DFList = GetPreDefinedFeatureDB(); // 与预定义特征库进行比较。
	for (FeaturePart dF : DFList){
		string infoList = "";
		int iParts = 0, iPartsAll = 0;
		bool bExist = false;
		for (FeaturePart a : rFeatureList){
			if (strcmp(a.szDes, dF.szDes) == 0){
				bExist = true;
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
				if (infoList.length() > 0) {
					sprintf_s(msg, "No.%02d [%s(%d--%d)]: %s", i, dF.szDes, (iPartsAll - 1) / 5 * 5 + 1, iPartsAll, infoList.c_str());
					Log(msg);
					infoList = "";
				}
			}
		}
		if (infoList == "")
			;
		else
		{
			sprintf_s(msg, "No.%02d [%s(%d--%d)]: %s", i, dF.szDes, (iPartsAll-1) / 5 * 5 + 1, iPartsAll, infoList.c_str());
			Log(msg);
		}
		if (bExist)
			i++;
	}

}
