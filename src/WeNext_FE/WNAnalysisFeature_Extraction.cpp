# pragma warning (disable:4819)

# pragma warning (disable:4267)

#include <iostream>
#include "dataFormat.h"
#include <vector>
#include <algorithm>

#include "EAAG_Adapter.h"
#include "WNAnalysisFeature.h"

using namespace::std;


bool CWNAnalysisFeature::ExtractionAllFeatures(const EAAG& rEAAG, FEATURELIST & rFeatureList)
{
	searchConvexFeature(rEAAG, rFeatureList);     //凸特征识别

	bool *rowMark = new bool[rEAAG.nDim+1];
	for (int i = 0; i < rEAAG.nDim; i++)
		rowMark[i] = false;

	ergodic_for_convexFace(rEAAG, rowMark);


	bool **concaveRec = new bool*[rEAAG.nDim+1];           //将所有的凹边连接标记
	for (int i = 0; i < rEAAG.nDim; i++){
		concaveRec[i] = new bool[rEAAG.nDim+1];
		for (int j = 0; j < rEAAG.nDim; j++){
			if (rEAAG.elem[i][j].A_ij != 00 && rEAAG.elem[i][j].A_ij % 10 == 0 && i != j)  //找到凹边
				concaveRec[i][j] = true;
			else
				concaveRec[i][j] = false;
		}
	}

	for (int i = 0; i < rEAAG.nDim; i++){
		if (!rowMark[i]){              //非纯凸行，必定存在凹边
			vector<vector<int>> FIRecList = mark_concaveEdge(rEAAG, i, concaveRec);   //从第i行寻起
			for (vector<int> aFIRec : FIRecList)
				rFeatureList.push_back(createFeaturePart(rEAAG, aFIRec, "未知凹特征"));

			for (int x = 0; x < rEAAG.nDim; x++){
				for (int y = 0; y < rEAAG.nDim; y++){
					if (rEAAG.elem[x][y].A_ij != 00 && rEAAG.elem[x][y].A_ij % 10 == 0 && x != y)  //找到凹边
						concaveRec[x][y] = true;
					else
						concaveRec[x][y] = false;
				}
			}
		}
	}
	
	delete(rowMark);
	delete(concaveRec);
	return rFeatureList.size()>0 ? true : false;
}

//-------------------------------------------------------------------------
// void searchConvexFeature(...)
// 需要根据新版本中的定义进行修改。
// Commented by szf 2019.07.24 .
//-------------------------------------------------------------------------
void CWNAnalysisFeature::searchConvexFeature(const EAAG rEAAG, FEATURELIST & rFeatureList)       //搜寻凸特征，目标[通孔]、[倒角]、[圆柱]、[圆锥]
{
	//由于凸边占大多数，故需要在全图内进行搜索
	for (int i = 0; i < rEAAG.nDim; i++){   //统计[内、外柱面]、[外锥面]特征
		int index = rEAAG.elem[i][i].A_ii; //筛选出[内柱面]、[外柱面]、[外锥面]
		if (index == 20 || index == 21 || index == 31) {  //[内柱面]编号20，[通孔]主要特征；[外柱面]编号21，[圆柱]主要特征；//[外锥面]编号31，[圆锥]、[倒角]主要特征
			vector<int> faceList;             // 组合与[内柱面]、[外柱面]、[内柱面]邻边为[凸圆弧]的面
			faceList.push_back(i);
			for (int j = 0; j < rEAAG.nDim; j++){
				if (j != i && rEAAG.elem[i][j].A_ij == 21)
					faceList.push_back(j);
			}

			if (faceList.size()>2)       //至少三个面构成凸特征
				rFeatureList.push_back(createFeaturePart(rEAAG, faceList, "未知凸特征"));
			faceList.clear();
		}
	}
}

// 用于纯凸边的面的标记
void CWNAnalysisFeature::ergodic_for_convexFace(const EAAG rEAAG, bool* mark)
{
	int n = rEAAG.nDim;
	vector<int> rec;
	for (int i = 0; i < n; i++){
		rec.clear();
		for (int j = 0; j < n; j++){
			if (rEAAG.elem[i][j].A_ii!=00 && i != j) { //有边
				if (rEAAG.elem[i][j].A_ii % 10 == 0) { //凹边，则清空
					rec.clear();
					break;
				}
				else                        //凸边存上
					rec.push_back(j);
			}
		}
		
		if (rec.size() > 0) {        //确定与该面相邻的纯是凸边
			mark[i] = true;
		}
	}
}

vector<vector<int>> CWNAnalysisFeature::mark_concaveEdge(const EAAG rEAAG, int index, bool **concaveRec)       //从第index行开始寻找首个凹边
{
	vector<vector<int>> FIRecList;

	int nextExit = false;    //标记是否还可以往下搜索
	for (int i=0; i < rEAAG.nDim; i++){
		if (concaveRec[index][i]){            //在凹边连接处换行进行查找
			nextExit = true;

			concaveRec[i][index] = false;
			concaveRec[index][i] = false;  //查询过的连接边标记为已查询过
			vector<vector<int>> subFIList = mark_concaveEdge(rEAAG, i, concaveRec);

			for (vector<int> subFI : subFIList)	{
				vector<int> aFIRec;
				aFIRec.push_back(index);
				aFIRec.insert(aFIRec.end(), subFI.begin(), subFI.end());

				sort(aFIRec.begin(), aFIRec.end());
				aFIRec.erase(unique(aFIRec.begin(), aFIRec.end()), aFIRec.end());      //去除重复的行号
				FIRecList.push_back(aFIRec);
			}
		}
	}

	if (!nextExit){                  //后方没有延伸，则返回本行的值
		vector<int> resFI;
		resFI.push_back(index);
		FIRecList.push_back(resFI);
	}

	return FIRecList;
}


FeaturePart CWNAnalysisFeature::createFeaturePart(const EAAG rEAAG, vector<int> rowList, const char* name)     //用于创建特征，在rEAAG中根据rowList选取顶点，组建特征矩阵
{
	sort(rowList.begin(), rowList.end());

	FeaturePart aFeature;
	int n = rowList.size();

	aFeature.nDim = n;

	strcpy_s(aFeature.szDes, name);

	aFeature.indexRec = new int[n];
	for (int i = 0; i < n; i++)
		aFeature.indexRec[i] = rowList[i];

	aFeature.elem = new uElemType*[n];
	for (int i = 0; i < n; i++)
		aFeature.elem[i] = new uElemType[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aFeature.elem[i][j].A_ii = rEAAG.elem[rowList[i]][rowList[j]].A_ii;
		}
	}
	return aFeature;
}


