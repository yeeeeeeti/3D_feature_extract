#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <io.h>

#include <string>
#include <vector>

using namespace std;

extern void TestOneObject(string filename, int solution);

void MakeLower(string &szSourc)
{
	for (int j = 0; j < szSourc.size(); j++)
		if (islower(szSourc[j]))//单词中下标为j的字符为小写字母 
			szSourc[j] = toupper(szSourc[j]);
}

void getFiles(vector<string>& files, string path, int layer)//递归遍历当前目录下的所有文件
{
	struct _finddata_t   filefind;
	string  curr = path;
	if (curr.rfind("\\") == curr.length()-1)
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
			if (path.rfind("\\") == path.length()-1)
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

void BatchTestFromDir(char *FileDir, int solution)
{
	vector<string> vecFNs;
	getFiles(vecFNs, FileDir, 0);

	for (int i = 0; i < vecFNs.size(); i++)	{
		TestOneObject(vecFNs[i], solution);
	}
	return;
}

