#include "WNXML.h"

#include < assert.h>

CWNXML::CWNXML(void)
{
	_fileName = NULL;
	_xPtrDoc = xmlNewDoc(BAD_CAST"1.0");
	_root =xmlNewNode(NULL , NULL);
}

CWNXML :: CWNXML(const char * fileName)
{
	assert (fileName != NULL);
	_fileName = new char[sizeof (fileName)];
	memset (_fileName , 0 , sizeof (fileName));
	strcpy(_fileName , fileName);
//	_xPtrDoc = xmlReadFile(_fileName,"UTF-8" , XML_PARSE_RECOVER);
	_xPtrDoc = xmlParseFile(_fileName);
	if (NULL != _xPtrDoc )
		_root =xmlDocGetRootElement(_xPtrDoc);
}


CWNXML::~CWNXML(void)
{
	if (! _xPtrDoc )
	{
		xmlFreeDoc(_xPtrDoc);
	}
	if (!_root)
	{
		//if (xmlhas)
		xmlFreeNode(_root);
	}
}

void CWNXML :: creatRoot (const char * content)
{
	_root = createNode (content);
	setRoot ();
	//std::cout<<_root->name<<std::endl;
}

NodePtr CWNXML:: getRoot () 
{
	return _root ;
}

NodePtr  CWNXML:: createNode (const char *context)
{
	return xmlNewNode(NULL ,BAD_CAST  context );
}


bool CWNXML:: hasChild(const NodePtr node)
{
	if (xmlChildElementCount(node))
		return true;
	return false;
}

void CWNXML :: addNode (NodePtr  parentNode , const char *context)
{
	NodePtr nodeptr = createNode(context);
	xmlAddChild(parentNode , nodeptr);
}


void CWNXML :: setRoot ()
{
	assert (_xPtrDoc != NULL);
	xmlDocSetRootElement(_xPtrDoc , _root);
}





NodePtr CWNXML :: getNode (const NodePtr parent , const int & index)
{
	assert (parent!=NULL);
	NodePtr _result = NULL;
	unsigned long num = xmlChildElementCount(parent);
	if (num == 0)
	{
		fprintf(stderr , "No Child");
		return NULL ;
	}

	if (index < 0 || index >= num)
	{
		fprintf(stderr , "The index is overflow");
		return NULL;
	}

	_result = parent->xmlChildrenNode;
	int i = 0;
	while (i < (index))
	{
		_result = _result->next;
		i +=1;
	}
	return _result;
}


NodePtr CWNXML :: findNode (const NodePtr parent ,const char * findContent)
{
	assert (parent != NULL);
	unsigned long sum = xmlChildElementCount(parent);
	if (0 == sum )
	{
		fprintf(stderr ,"No child");
		return NULL;
	}
	for (unsigned long i = 0 ; i<sum ; i++)
	{
		NodePtr tmp = getNode(parent , i);
		if (!xmlStrcmp(tmp->name , BAD_CAST findContent))
		{
			//cout<<"Node NAME:   " <<tmp->name<<endl;
			return tmp;
		}
	}
	return NULL;
}


void CWNXML :: getTree (const NodePtr root)
{
	assert (root!=NULL);
	if (hasChild(root))
	{
		_read.push(root);
	}
	NodePtr node = root->children;
	while (node != NULL)
	{
		getTree (node);
		node = node->next;
	}
}

NodePtr CWNXML:: findNode (const char * context)
{
	NodePtr _result  =NULL;
	_result = findNode (getRoot() , context);
	if (_result)
	{
		return _result;
	}
	getTree(getRoot());
	NodePtr node =NULL;
	while(!_read.empty())
	{
		node = _read.top();
		//cout<<"Node -- > NAME:   " <<node->name<<endl;
		if (!isSameNode(node , getRoot()))
		{
			_result =findNode (node , context);
			if (_result)
			{	
				return _result;
			}
		}
		_read.pop();
	}
	return NULL;
}


bool CWNXML :: deleteNode ( NodePtr parent , const char * context)
{
	assert (parent!=NULL);
	NodePtr node = findNode(parent , context);
	if ( NULL == node)
		return false ;
	xmlUnlinkNode(node);
	xmlFreeNode(node);
	return true;
}

bool CWNXML :: isSameNode (const NodePtr node1 , const NodePtr node2)
{
	if (!xmlStrcmp(node1->name , node2->name))
		return true;
	return false;
}

bool CWNXML :: CompareName (const NodePtr node , const char * name)
{
	if (!xmlStrcmp(node->name , BAD_CAST name))
		return true;
	return false;
}


bool CWNXML :: modifyNode (const char * findContext ,const char * modify)
{
	NodePtr node = findNode(findContext);
	if (node)
	{
		node->name = BAD_CAST modify;
		return true;
	}
	else
	{
		fprintf(stderr , "No find the node!");
		return false;
	}
}


void CWNXML :: addAttibute (NodePtr nodePtr , const char * name , const char * value)
{
	assert (nodePtr!=NULL);
	xmlNewProp(nodePtr , BAD_CAST name , BAD_CAST value);
}

void CWNXML :: modifyAttibute (const NodePtr node , const char * findname , const char * modifyValue)
{
	assert (node != NULL);
	assert (findname !=NULL);
	if (!hasAttribute(node))
		return ;
	xmlSetProp(node , BAD_CAST findname , BAD_CAST modifyValue);
}

bool CWNXML :: hasAttribute (const NodePtr node)
{
	assert (node != NULL);
	if (node->properties)
		return true;
	return false;
}

xmlChar * CWNXML :: getAttribute ( const NodePtr node , const char * name)
{
	assert (node != NULL);
	if (!hasAttribute(node))
		return NULL;
	return xmlGetProp(node , BAD_CAST name);
}


bool  CWNXML :: deleteAttibute (NodePtr nodePtr , const char * name)
{
	assert (nodePtr!=NULL);
	AttrPtr attrptr = xmlHasProp(nodePtr , BAD_CAST name);
	if (0==xmlRemoveProp(attrptr))
		return true;
	return false;
	
}

bool CWNXML :: saveXML (const char * fileName)
{
	assert (fileName!=NULL);
	assert (_xPtrDoc !=NULL);
	int nRel = xmlSaveFile(fileName ,_xPtrDoc);
	if (nRel !=-1)
	{
		return true;
	}
	return false;
}