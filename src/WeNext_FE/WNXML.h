# pragma warning (disable:4819)
# pragma warning (disable:4018)

#pragma once
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <stack>
using namespace std;

typedef  xmlNode  Node;
typedef xmlNodePtr   NodePtr;
typedef xmlAttr  Attribute;
typedef xmlAttrPtr   AttrPtr;


class CWNXML
{
	char * _fileName;
	xmlDocPtr  _xPtrDoc ;
	xmlNodePtr _root;
	stack<NodePtr> _read;
public:
	CWNXML(void);
	CWNXML(const char * fileName);
	~CWNXML(void);
	void  creatRoot (const char * size);       //创建根节点
	NodePtr  getRoot () ;     //返回根节点
	NodePtr  createNode (const char *context);    //创建节点
	void addNode (NodePtr  parentNode , const char *context);  //添加节点 
	bool deleteNode ( NodePtr parent , const char * context);     //删除节点
	bool modifyNode (const char * findContext ,const char * modify);    //修改节点
	NodePtr findNode (const char * context);   //寻找节点
	void addAttibute (NodePtr nodePtr , const char * name , const char * value);   //添加属性
	void modifyAttibute (const NodePtr node , const char * findname , const char * modifyValue); //修改节点属性
	xmlChar * getAttribute ( const NodePtr node , const char * name);   //获取节点的属性
	bool deleteAttibute (NodePtr nodePtr , const char * name);   //删除节点的属性
	bool saveXML (const char * fileName);   //保存文件
	NodePtr  findNode (const NodePtr parent ,const char * findContent);   //在含子节点的节点中寻找子节点
	void getTree (const NodePtr root);       //辅助函数（获得含子节点的节点的栈）
	
private:
	void setRoot ( );  
	NodePtr  getNode (const NodePtr parent , const int & index);    //在含子节点的节点寻找第N个节点
	bool isSameNode (const NodePtr node1 , const NodePtr node2);    //利用节点的名称比较两个节点
	bool CompareName (const NodePtr node , const char * name);  //比较节点名称
	bool hasChild (const NodePtr node);   //判断是否有子节点
	bool hasAttribute (const NodePtr node);   //判断是否有属性
};

