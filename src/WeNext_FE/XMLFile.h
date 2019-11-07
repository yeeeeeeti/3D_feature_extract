#include <iostream>
#include "tinyXML/tinyxml.h"
#include <string>
#include <map>
//#include <cctype>
using namespace std;

class XMLFile
{
public:
	XMLFile(const char *xmlFileName);
	~XMLFile();

public:
	void CreateXML();//创建XML文件
	void ReadXML();//读取XML文件完整内容
	void ReadDeclaration(string &version, string &encoding, string &standalone);//读取XML声明
	bool FindNode(TiXmlElement *pRoot, const string nodeName, TiXmlElement *&pNode);//根据节点名，判断节点是否存在
	bool GetNodeText(const string nodeName, const char *&text);//根据节点名，获取该节点文本
	bool GetNodeAttribute(const string nodeName, map<string, string> &mapAttribute);//获取根据节点名， 获取节点属性
	bool DeleteNode(const string nodeName);//根据节点名，删除节点
	bool modifyText(const string nodeName, const string text);//修改节点文本
	bool modifyAttribution(const string nodeName, map<string, string> &mapAttribute);//修改节点属性
	bool AddNode(const string nodeName, const char * newNodeName, const char *text);//添加节点
private:
	char *m_xmlFileName;
	TiXmlDocument *m_pDocument;
	TiXmlDeclaration *m_pDeclaration;
};