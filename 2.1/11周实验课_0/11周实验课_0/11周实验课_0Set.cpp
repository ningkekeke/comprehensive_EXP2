
// 11周实验课_0Set.cpp : CMy11周实验课_0Set 类的实现
//

#include "stdafx.h"
#include "11周实验课_0.h"
#include "11周实验课_0Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11周实验课_0Set 实现

// 代码生成在 2020年5月16日, 下午 5:40

IMPLEMENT_DYNAMIC(CMy11周实验课_0Set, CRecordset)

CMy11周实验课_0Set::CMy11周实验课_0Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = 0.0;
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
// #error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMy11周实验课_0Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90-\x5b66\x751f\x4fe1\x606f\x8868;DBQ=W:\\\x5b66\x751f\x4fe1\x606f\x8868.xls;DefaultDir=W:;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMy11周实验课_0Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMy11周实验课_0Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Double(pFX, _T("[学号]"), column2);
	RFX_Double(pFX, _T("[年龄]"), column3);
	RFX_Double(pFX, _T("[手机号]"), column4);
	RFX_Text(pFX, _T("[照片路径]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11周实验课_0Set 诊断

#ifdef _DEBUG
void CMy11周实验课_0Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11周实验课_0Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

