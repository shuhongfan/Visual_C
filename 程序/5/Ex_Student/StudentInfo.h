class CStudentInfo : public CObject
{
	CString strName;				// 姓名
	CString strNO;					// 学号
	BOOL	bMale;					// 性别，是否为男
	CTime	tBirth;					// 出生年月
	CString	strSpecial;				// 专业
	DECLARE_SERIAL(CStudentInfo)	// 序列化声明
public:
	CStudentInfo() {};
	CStudentInfo(CString name, CString id, BOOL male, CTime birth, CString special);
	void Serialize(CArchive &ar);
	void Display(int y, CDC *pDC);	// 在坐标为(0,y)处显示数据
};
