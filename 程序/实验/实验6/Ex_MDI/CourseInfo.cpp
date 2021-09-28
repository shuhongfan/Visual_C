#include "stdafx.h"
#include "CourseInfo.h"
CCourseInfo::CCourseInfo(CString id, CString name, CString special, CString type,
		BYTE term, BYTE hours, float credit)
{
	strNO		= id;
	strName		= name;
	strSpecial	= special;
	strType		= type;
	nOpen		= term;
	nHours		= hours;
	fCredit		= credit;
}
void CCourseInfo::Display(int y, CDC *pDC)
{
	CString str;
	str.Format("%s  %s  %s  %s  %d  %d  %4.1f", strNO, strName, 
		strSpecial, strType, nOpen, nHours, fCredit);
	pDC->TextOut(0, y, str);
}
IMPLEMENT_SERIAL(CCourseInfo, CObject, 1)	// 序列化实现
void CCourseInfo::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar<<strNO<<strName<<strSpecial<<strType<<nOpen<<nHours<<fCredit;
	else
		ar>>strNO>>strName>>strSpecial>>strType>>nOpen>>nHours>>fCredit;
}