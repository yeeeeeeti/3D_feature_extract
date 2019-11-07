typedef enum __eFaceType {  
	// �����Ͷ���  
	eEmpty = 0,
	eIn_Plane = 10,  
	eOut_Plane = 11,  
	eIn_Surface_Cylinder = 20,  
	eOut_Surface_Cylinder = 21,  
	eIn_Surface_Cone = 30,  
	eOut_Surface_Cone = 31,  
	eIn_Surface_Sphere = 40, 
	eOut_Surface_Sphere = 41,

	eFaceType_Undefined = 999
}eFaceType;

typedef enum __eCurveType {  
	// �����潻�ߵ����Ͷ���  
	eConcave_Line = 10,  
	eConvex_Line = 11,  
	eConcave_Circle = 20, 
	eConvex_Circle = 21, 
	eConcave_Ellipse = 30, 
	eConvex_Ellipse = 31, 
	eConcave_BSpline = 40, 
	eConvex_BSpline = 41,

	eCurveType_Undefined = 999
}eCurveType;

typedef union __uElemType {  
	// ��չ�����ڽӾ�����Ԫ�ص�����  
	enum __eFaceType A_ii;
	enum __eCurveType A_ij;
} uElemType; 

typedef struct __EAAG { 
	// ��ά���ģ�͵���չ�����ڽ�ͼ����ṹ����  
	int nDim; // ����ά��  
	uElemType ** elem; // ��ά���飬���ڴ洢��չ�����ڽ�ͼ���� 
}EAAG; 

TopoDS_Shape ReadStep(Standard_CString str);
bool GenerateEAAGFromShape(EAAG& rEAAG, const TopoDS_Shape& crShape);
bool ClearEAAG(EAAG &anEAAG);
bool DumpEAAGInfo(const EAAG& anEAAG);