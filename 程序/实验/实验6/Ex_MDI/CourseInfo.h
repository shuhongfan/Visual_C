class CCourseInfo : public CObject
{
	CString strNO;					// �γ̺�
	CString strName;				// �ο�����
	CString	strSpecial;				// ����רҵ
	CString	strType;				// �γ�����
	BYTE	nOpen;					// ����ѧ��
	BYTE	nHours;					// ��ʱ��
	float	fCredit;				// ѧ��
	DECLARE_SERIAL(CCourseInfo)		// ���л�����
public:
	CCourseInfo() {};
	CCourseInfo(CString id, CString name, CString special, CString type,
		BYTE term, BYTE hours, float credit);
	void Serialize(CArchive &ar);
	void Display(int y, CDC *pDC);	// ������Ϊ(0,y)����ʾ����
};