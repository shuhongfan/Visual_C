class CStudentInfo : public CObject
{
public:
	CString strName;					// ����
	CString strNO;					// ѧ��
	BOOL	bMale;				// �Ա��Ƿ�Ϊ��
	CTime	tBirth;				// ��������
	CString	strSpecial;				// רҵ
	DECLARE_SERIAL(CStudentInfo)	// ���л�����
	CStudentInfo() {};
	CStudentInfo(CString name, CString id, BOOL male, CTime birth, CString special);
	void Serialize(CArchive &ar);
	void Display(int y, CDC *pDC);		// ������Ϊ(0,y)����ʾ����
};
