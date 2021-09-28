#include "stdafx.h"
#include "StudentInfo.h"
CStudentInfo::CStudentInfo(CString name, CString id, BOOL male, CTime birth, CString special)
{
	strName		= name;
	strNO		= id;
	bMale		= male;
	tBirth		= birth;
	strSpecial	= special;
}
void CStudentInfo::Display(int y, CDC *pDC)
{
	CString str, strSex("女");
	if (bMale) strSex = "男";
	str.Format("%s  %s  %s  %s  %s", strName, strNO,
		strSex, tBirth.Format("%Y-%m-%d"), strSpecial);
	pDC->TextOut(0, y, str);
}
IMPLEMENT_SERIAL(CStudentInfo, CObject, 1)	// 序列化实现
void CStudentInfo::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
		ar<<strName<<strNO<<bMale<<tBirth<<strSpecial;
	else
		ar>>strName>>strNO>>bMale>>tBirth>>strSpecial;
}
