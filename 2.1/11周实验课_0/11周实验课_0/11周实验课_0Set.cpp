
// 11��ʵ���_0Set.cpp : CMy11��ʵ���_0Set ���ʵ��
//

#include "stdafx.h"
#include "11��ʵ���_0.h"
#include "11��ʵ���_0Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11��ʵ���_0Set ʵ��

// ���������� 2020��5��16��, ���� 5:40

IMPLEMENT_DYNAMIC(CMy11��ʵ���_0Set, CRecordset)

CMy11��ʵ���_0Set::CMy11��ʵ���_0Set(CDatabase* pdb)
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
// #error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMy11��ʵ���_0Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90-\x5b66\x751f\x4fe1\x606f\x8868;DBQ=W:\\\x5b66\x751f\x4fe1\x606f\x8868.xls;DefaultDir=W:;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMy11��ʵ���_0Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMy11��ʵ���_0Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�ֻ���]"), column4);
	RFX_Text(pFX, _T("[��Ƭ·��]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11��ʵ���_0Set ���

#ifdef _DEBUG
void CMy11��ʵ���_0Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11��ʵ���_0Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

