
#include "WNAnalysisFeature_IncSetup.h"



bool CWNAnalysisFeature::FeatureMatchingFromDB(const EAAG & rEAAG, const FEATURELIST & rFeatureList, string& name)
{
	int m = rEAAG.nDim;
	bool find_featureMatch = false;
	for (FeaturePart aFeature : rFeatureList) {     //维度、行相似筛选 + 交换配准
		if ((aFeature.nDim == m)) {
			int *rowList = new int[m];
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

bool CWNAnalysisFeature::row_matrixMatch(uElemType ** queryMatrix, uElemType ** dataMatrix, int dim, int* rowList) //矩阵行相似判断
{
	for (int i = 0; i < dim; i++)       //标记dataMatrix中可以用来匹配的行，并记录匹配的位置
		rowList[i] = -1;

	for (int i = 0; i < dim; i++) {
		int find_rowMatch = -1;
		for (int j = 0; j < dim; j++) {
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
	bool *rowlist = new bool[dim + 1];      //标记dataRow中可以用来匹配的数字
	for (int i = 0; i < dim; i++)
		rowlist[i] = true;

	for (int i = 0; i < dim; i++) {
		int find_rowMatch = -1;
		for (int j = 0; j < dim; j++) {
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

	EAAG copyEAAG;                                  //复制一个矩阵，用于交换
	copyEAAG.nDim = dim;
	copyEAAG.elem = new uElemType*[dim ];
	for (int i = 0; i < dim; i++)
		copyEAAG.elem[i] = new uElemType[dim];

	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			copyEAAG.elem[i][j].A_ii = rEAAG.elem[i][j].A_ii;
		}
	}


	for (int i = 0; i < dim; i++) {    //从dataMatrix的角度，逐行校准
		if (rowList[i] != i) {
			for (int j = 0; j < dim; j++){ //行调换
				temp = copyEAAG.elem[i][j].A_ii;
				copyEAAG.elem[i][j].A_ii = copyEAAG.elem[rowList[i]][j].A_ii;
				copyEAAG.elem[rowList[i]][j].A_ii = (eFaceType)temp;
			}
			for (int j = 0; j < dim; j++){ //列调换
				temp = copyEAAG.elem[j][i].A_ii;
				copyEAAG.elem[j][i].A_ii = copyEAAG.elem[j][rowList[i]].A_ii;
				copyEAAG.elem[j][rowList[i]].A_ii = (eFaceType)temp;
			}

			for (int j = 0; j < dim; j++){  //调整调换后的rowList相似对应关系
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
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			if (dataMatrix[i][j].A_ii != queryMatrix[i][j].A_ii)
				return false;
		}
	}
	return true;
}


class Comparator : public AttrComparator
{
public:
	Comparator()
	{	}

	virtual bool compatible(void *pa, void *pb) {       //匹配：边和面代表的数值相等
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

bool my_visitor(int n, node_id ni1[], node_id ni2[], void *usr_data)          //匹配结果保存函数，match内部用
{
	vector<matchPair> *f = (vector<matchPair> *)usr_data;

	// Prints the matched pairs on the file
	int i;
	for (i = 0; i < n; i++)	{
		matchPair aMatchPair;
		aMatchPair.n1 = ni1[i];
		aMatchPair.n2 = ni2[i];
		//aMatchPair.n1 = ni1[i] + 1; // mod by szf 2019.09.07
		//aMatchPair.n2 = ni2[i] + 1;
		(*f).push_back(aMatchPair);
	}
	// Return false to search for the next matching

#ifdef _DEBUG
	FILE * file = fopen("output.txt", "w");
	int ii;
	for (ii = 0; ii < n; ii++)
		fprintf(file, "(%hd, %hd) ", ni1[ii], ni2[ii]);
	fprintf(file, "\n");
	fclose(file);
#endif
	return false;
}

int judgeContain(FeaturePart F1, FeaturePart F2)            //是否存在特征包含现象,若否返回-1；若前者包含后者，返回0；若后者包含前者，返回1。
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

	for (int i = 0; i < aFeature.nDim; i++) {     //将EAAG与特征图转换为ARG图形式
		ed1.InsertNode(&aFeature.elem[i][i]);
		for (int j = 0; j < aFeature.nDim; j++){
			ed1.InsertEdge(i, j, &aFeature.elem[i][j]);
		}
	}

	for (int i = 0; i < rEAAG.nDim; i++) {
		ed2.InsertNode(&rEAAG.elem[i][i]);
		for (int j = 0; j < rEAAG.nDim; j++) {
			if (i != j)
				ed2.InsertEdge(i, j, &rEAAG.elem[i][j]);
		}
	}


	ARGraph<int, int> g1(&ed1);
	ARGraph<int, int> g2(&ed2);

	// Install the attribute comparator
	// This needs to be done only on graph g1.
	g1.SetNodeComparator(new Comparator());             //设计边和面匹配比较方法
	g1.SetEdgeComparator(new Comparator());

	VF2SubState s0(&g1, &g2); 
//	VFSubState s0(&g1, &g2);// 2019.09.08

	vector<matchPair> rec;
	if (!match(&s0, my_visitor, &rec))              //不存在能够匹配上的特征子图
		return false;
	else{                                            //存在
		int n = rec.size() / aFeature.nDim;         //匹配上的特征子图数目
		for (int i = 0; i < n; i++) {                //对每一个匹配上的特征子图，构建特征结构，为下一步特征去重做准备
			vector<int> rowList;
			for (int j = 0; j < aFeature.nDim; j++){
				rowList.push_back(rec[i*aFeature.nDim + j].n2);
				//cout << rec[i*aFeature.nDim+j].n1 << "match" << rec[i*aFeature.nDim+j].n2 << endl;
			}

			FeaturePart aFeaturePart = createFeaturePart(rEAAG, rowList, aFeature.szDes);

			recList.push_back(aFeaturePart);

			rowList.clear();
		}
	}
	return true;
}


void CWNAnalysisFeature::featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList)           //用于最后的特征去重
{
	int i = 0;

	while (!recList.empty()){                            //特征去重
		FeaturePart headFeature = recList[0];

		int store = true;
		vector<FeaturePart>::iterator it = recList.begin();
		it++;      //越过第一个

		int j = 0;
		while (it != recList.end())
		{
			int res = judgeContain(headFeature, (*it));  //是否存在特征包含现象,若否返回-1；若前者包含后者，返回0；若后者包含前者，返回1。

			if (res == 1){
				store = false;
				recList.erase(recList.begin());       //删掉初始，重新开始
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
void featureDisRepetition(vector<FeaturePart> recList, FEATURELIST & rFeatureList)           //用于最后的特征去重
{
while (!recList.empty())                            //特征去重
{
FeaturePart headFeature = recList[0];

int store = true;
vector<FeaturePart>::iterator it = recList.begin();

for (int i = 1; i < recList.size(); i++)
{
it++;  //越过第一个
int res = judgeContain(headFeature, (*it));     //是否存在特征包含现象,若否返回-1；若前者包含后者，返回0；若后者包含前者，返回1。

if (res == 1)
{
store = false;
recList.erase(recList.begin());       //删掉初始，重新开始
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
