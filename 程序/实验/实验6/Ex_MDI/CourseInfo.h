class CCourseInfo : public CObject
{
	CString strNO;					// 课程号
	CString strName;				// 课课名称
	CString	strSpecial;				// 所属专业
	CString	strType;				// 课程类型
	BYTE	nOpen;					// 开课学期
	BYTE	nHours;					// 课时数
	float	fCredit;				// 学分
	DECLARE_SERIAL(CCourseInfo)		// 序列化声明
public:
	CCourseInfo() {};
	CCourseInfo(CString id, CString name, CString special, CString type,
		BYTE term, BYTE hours, float credit);
	void Serialize(CArchive &ar);
	void Display(int y, CDC *pDC);	// 在坐标为(0,y)处显示数据
};