#include "XMLFile.h"

XMLFile::XMLFile(const char *xmlFileName)
{
	m_xmlFileName = new char[20];
	strcpy(m_xmlFileName, xmlFileName);
	m_pDocument = NULL;
	m_pDeclaration = NULL;
}

XMLFile::~XMLFile()
{
	if (m_xmlFileName != NULL)
		delete m_xmlFileName;

	if (m_pDocument != NULL)
		delete m_pDocument;

	if (m_pDeclaration != NULL)
		delete m_pDeclaration;
}

void XMLFile::CreateXML()
{
	//����XML�ĵ�ָ��
	m_pDocument = new TiXmlDocument(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return;
	}

	//����XML
	m_pDeclaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	if (NULL == m_pDeclaration)
	{
		return;
	}
	m_pDocument->LinkEndChild(m_pDeclaration);

	//�������ڵ�
	string xmlFileName = m_xmlFileName;
	string rootName = (xmlFileName.substr(0, xmlFileName.find(".")));//���ڵ�Ԫ����Ϊ�ļ���ȥ��.xml
	TiXmlElement *pRoot = new TiXmlElement(rootName.c_str());
	if (NULL == pRoot)
	{
		return;
	}
	//����XML�ĵ�����ΪXML�ĵ��ĸ��ڵ�
	m_pDocument->LinkEndChild(pRoot);

	TiXmlText *pText = new TiXmlText("ѧ����");
	pRoot->LinkEndChild(pText);

	//�������ӽڵ�
	TiXmlElement *pStudent = new TiXmlElement("Student");
	if (NULL == pStudent)
	{
		return;
	}
	TiXmlText *pStuText = new TiXmlText("Сѧ��");
	pStudent->LinkEndChild(pStuText);


	pStudent->SetAttribute("id", 1);
	pStudent->SetAttribute("age", 18);
	pStudent->SetAttribute("name", "����");

	TiXmlElement *pYuWen = new TiXmlElement("YuWen");
	TiXmlText *pYuWenText = new TiXmlText("98");
	pYuWen->LinkEndChild(pYuWenText);

	TiXmlElement *pMathe = new TiXmlElement("Mathe");
	TiXmlText *pMatheText = new TiXmlText("99");
	pMathe->LinkEndChild(pMatheText);

	TiXmlElement *pEnglish = new TiXmlElement("English");
	TiXmlText *pEnglishText = new TiXmlText("100");
	pEnglish->LinkEndChild(pEnglishText);

	pStudent->LinkEndChild(pYuWen);
	pStudent->LinkEndChild(pMathe);
	pStudent->LinkEndChild(pEnglish);

	//�������ڵ㣬��Ϊ���ڵ�ĺ��ӽڵ�
	pRoot->LinkEndChild(pStudent);

	m_pDocument->SaveFile(m_xmlFileName);
}

//��ȡXML�ļ���������
void XMLFile::ReadXML()
{
	if (m_xmlFileName == NULL)
	{
		cout << " null " << endl;
		return;
	}
	m_pDocument->LoadFile(m_xmlFileName);
	m_pDocument->Print();
}

//��ȡXML���������磺<?xml version="1.0" encoding="UTF-8" ?>
void XMLFile::ReadDeclaration(string &version, string &encoding, string &standalone)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlNode *pNode = m_pDocument->FirstChild();
	if (NULL != pNode)
	{
		//��ȡ����ָ��
		m_pDeclaration = pNode->ToDeclaration();

		if (NULL != m_pDeclaration)
		{
			version = m_pDeclaration->Version();
			encoding = m_pDeclaration->Encoding();
			standalone = m_pDeclaration->Standalone();
		}
	}
}

//���ݽڵ������жϽڵ��Ƿ����
bool XMLFile::FindNode(TiXmlElement *pRoot, const string nodeName, TiXmlElement *&pNode)
{
	const char *value = pRoot->Value();
	if (strcmp(pRoot->Value(), nodeName.c_str()) == 0)
	{
		pNode = pRoot;
		return true;
	}

	TiXmlElement *p = pRoot;
	for (p = p->FirstChildElement(); p != NULL; p = p->NextSiblingElement())
	{
		FindNode(p, nodeName, pNode);
		return true;
	}

	return false;
}

//���ݽڵ�������ȡ�ýڵ��ı�
bool XMLFile::GetNodeText(const string nodeName, const char *&text)
{
	m_pDocument->LoadFile(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return false;
	}

	TiXmlElement *pRoot = m_pDocument->RootElement();
	const char *value = pRoot->Value();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		text = pNode->GetText();
		return true;
	}

	return false;
}

//��ȡ���ݽڵ����� ��ȡ�ڵ�����
bool XMLFile::GetNodeAttribute(const string nodeName, map<string, string> &mapAttribute)
{
	m_pDocument->LoadFile(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return false;
	}

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlAttribute *pAttr = NULL;
		for (pAttr = pNode->FirstAttribute(); pAttr != NULL; pAttr = pAttr->Next())
		{
			string name = pAttr->Name();
			string value = pAttr->Value();
			mapAttribute.insert(make_pair(name, value));
		}

		return true;
	}

	return false;
}

//ɾ���ڵ�
bool XMLFile::DeleteNode(const string nodeName)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		if (pNode == pRoot)
		{//����Ǹ��ڵ�
			m_pDocument->RemoveChild(pRoot);
			m_pDocument->SaveFile(m_xmlFileName);
			return true;
		}
		else
		{//�ӽڵ�
			TiXmlNode *parent = pNode->Parent();//�ҵ��ýڵ�ĸ��ڵ�
			if (NULL == parent)
			{
				return false;
			}

			TiXmlElement *parentElem = parent->ToElement();
			if (NULL == parentElem)
			{
				return false;
			}
			parentElem->RemoveChild(pNode);
			m_pDocument->SaveFile(m_xmlFileName);
			return true;
		}
	}

	return false;
}

//�޸Ľڵ��ı�
bool XMLFile::modifyText(const string nodeName, const string text)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		//pNode->Clear();//ɾ��ԭ�ڵ��µ�����Ԫ��
		TiXmlText *pText = new TiXmlText(text.c_str());
		pNode->LinkEndChild(pText);
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}

//�޸Ľڵ�����
bool XMLFile::modifyAttribution(const string nodeName, map<string, string> &mapAttribute)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlAttribute *pAttr = pNode->FirstAttribute();
		char *strName = NULL;
		for (; pAttr != NULL; pAttr = pAttr->Next())
		{
			strName = const_cast<char *>(pAttr->Name());
			for (auto it = mapAttribute.begin(); it != mapAttribute.end(); ++it)
			{
				if (strName == it->first)
				{
					pNode->SetAttribute(strName, it->second.c_str());
				}
			}
		}
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}

//����ΪnodeName�Ľڵ��²����ӽڵ�
bool XMLFile::AddNode(const string nodeName, const char * newNodeName, const char *text)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlElement *pNewNode = new TiXmlElement(newNodeName);
		TiXmlText *pNewText = new TiXmlText(text);
		pNewNode->LinkEndChild(pNewText);
		pNode->InsertEndChild(*pNewNode);
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}
