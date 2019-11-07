#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>//errno()的头文件
#include<string.h>//strerror()函数的头文件

using namespace std;

/// 按照指定格式从文本中读取多行数据
void readFile(const char *szDataFN, int **nMat, int nNum){
    FILE *fp1 = NULL;
    int i = 0, j = 0;
    fp1 = fopen(szDataFN, "r");

    int nFaceCount = 0;
    fscanf(fp1, "%d", &nFaceCount);  /// 面的个数
    char sz3DModelFN[1024];
    fscanf(fp1, "%s", sz3DModelFN); /// 对应的三维模型文件名
    int nFaceIdx = 0;
    for(i = 0; i < nNum; i++){  /// 面的编号
        fscanf(fp1,"%05d", &nFaceIdx);
    }

    for(i = 0; i < nNum; i++){
        for(j = 0; j < nNum; j++){
            fscanf(fp1,"%05d", &nMat[i][j]);
        }
    }
    fclose(fp1);
}

void DumpMatrix(int **mat, int nDim)
{
    int i = 0, j = 0;
	for (i = 0; i < nDim; i++) {
		for (j = 0; j < nDim; j++) {
			cout << setw(5) << mat[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
    int **EEAGMat = NULL;

	/// 解析命令行参数
	if (argc >= 2)	{
		/// 从参数中获取文件名
        string filename;       /// 数据文件所在路径和文件名
		filename = argv[1];
		//filename = "D:\\WeNext3D\\AnalysisSitus-v0.2.6\\src\\WeNext_FE\\EAAG.dat";

        FILE *fp1 = NULL;
        fp1 = fopen(filename.c_str(), "r");
        if(NULL == fp1){
            printf("File %s can't open!\n", filename.c_str());

            int errNum = 0;
            errNum = errno;
            printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));

/// test errno and strerror function
//for(tmp=0;tmp<=256;tmp++)
//{
//    printf("errno:%2d\t%s\n",tmp,strerror(tmp));
//}
/// ~test errno and strerror function

///            常见的errno错误码有以下这些：
///            #define EPERM 1 /* Operation not permitted */ 
///　　        #define ENOENT 2 /* No such file or directory */
///　　        #define ESRCH 3 /* No such process */
///        　　#define EIO 5 /* I/O error */
///        　　#define ENXIO 6 /* No such device or address */
///        　　#define E2BIG 7 /* Argument list too long */
///        　　#define ENOEXEC 8 /* Exec format error */
///        　　#define EBADF 9 /* Bad file number */
///        　　#define ECHILD 10 /* No child processes */

            system("pause");
            exit(1);
        }

        int nFaceCount = 0;
        fscanf(fp1, "%d", &nFaceCount);
        fclose(fp1);

		/// 从参数中获取面所在索引序号
		if (argc >= 3){
            int i = 0;
            int nColIdxCount = argc - 2;
            int *nColInfo = new int(nColIdxCount);
            for(i = 0; i < nColIdxCount; i++){
                nColInfo[i] = atoi(argv[i+2]);
            }

            /// 生成二维EEAG数组。
            EEAGMat = new int*[nFaceCount];    /// int*[nFaceCount]表示一个有 nFaceCount 个元素的指针数组
            for(i = 0; i < nFaceCount; i++)
                EEAGMat[i] = new int[nFaceCount];

            readFile(filename.c_str(), EEAGMat, nFaceCount);    /// 读取数据文件到一个矩阵中。

            /// 根据输入参数，提取子矩阵，并输出到控制台中，用于自动生成特征矩阵。
            /// 实际使用时，可以由用户在3D显示软件中找到特征所在多个面索引编号，将其作为这里的输入。用空格分开。
            int **subMat = NULL;
            /// 生成二维EEAG数组。
            subMat = new int*[nColIdxCount];    /// int*[nFaceCount]表示一个有 nFaceCount 个元素的指针数组
            for(i = 0; i < nColIdxCount; i++)
                subMat[i] = new int[nColIdxCount];
            for(i = 0; i < nColIdxCount; i++) {
                for(int j = 0; j < nColIdxCount; j++) {
                    subMat[i][j] = EEAGMat[nColInfo[i]-1][nColInfo[j]-1];
                }
            }

            cout << "------------------------------------------------\n";
            cout << "The column index is:\n";
            for(i = 0; i < nColIdxCount; i++){
                cout << setw(5) << nColInfo[i];
            }
            cout << endl;
            cout << "------------------------------------------------\n";

            DumpMatrix(subMat, nColIdxCount);
		}
	}
    return 0;
}
