
// 11��ʵ���_0Set.h: CMy11��ʵ���_0Set ��Ľӿ�
//


#pragma once

// ���������� 2020��5��16��, ���� 5:40

class CMy11��ʵ���_0Set : public CRecordset
{
public:
	CMy11��ʵ���_0Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMy11��ʵ���_0Set)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	double	m_ID;
	CStringW	column1;
	double	column2;
	double	column3;
	double	column4;
	CStringW	column5;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

