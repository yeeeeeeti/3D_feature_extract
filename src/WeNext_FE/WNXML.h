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
	void  creatRoot (const char * size);       //�������ڵ�
	NodePtr  getRoot () ;     //���ظ��ڵ�
	NodePtr  createNode (const char *context);    //�����ڵ�
	void addNode (NodePtr  parentNode , const char *context);  //��ӽڵ� 
	bool deleteNode ( NodePtr parent , const char * context);     //ɾ���ڵ�
	bool modifyNode (const char * findContext ,const char * modify);    //�޸Ľڵ�
	NodePtr findNode (const char * context);   //Ѱ�ҽڵ�
	void addAttibute (NodePtr nodePtr , const char * name , const char * value);   //�������
	void modifyAttibute (const NodePtr node , const char * findname , const char * modifyValue); //�޸Ľڵ�����
	xmlChar * getAttribute ( const NodePtr node , const char * name);   //��ȡ�ڵ������
	bool deleteAttibute (NodePtr nodePtr , const char * name);   //ɾ���ڵ������
	bool saveXML (const char * fileName);   //�����ļ�
	NodePtr  findNode (const NodePtr parent ,const char * findContent);   //�ں��ӽڵ�Ľڵ���Ѱ���ӽڵ�
	void getTree (const NodePtr root);       //������������ú��ӽڵ�Ľڵ��ջ��
	
private:
	void setRoot ( );  
	NodePtr  getNode (const NodePtr parent , const int & index);    //�ں��ӽڵ�Ľڵ�Ѱ�ҵ�N���ڵ�
	bool isSameNode (const NodePtr node1 , const NodePtr node2);    //���ýڵ�����ƱȽ������ڵ�
	bool CompareName (const NodePtr node , const char * name);  //�ȽϽڵ�����
	bool hasChild (const NodePtr node);   //�ж��Ƿ����ӽڵ�
	bool hasAttribute (const NodePtr node);   //�ж��Ƿ�������
};

