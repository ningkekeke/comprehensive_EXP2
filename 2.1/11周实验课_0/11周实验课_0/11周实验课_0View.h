
// 11��ʵ���_0View.h : CMy11��ʵ���_0View ��Ľӿ�
//

#pragma once

class CMy11��ʵ���_0Set;

class CMy11��ʵ���_0View : public CRecordView
{
protected: // �������л�����
	CMy11��ʵ���_0View();
	DECLARE_DYNCREATE(CMy11��ʵ���_0View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY11_0_FORM };
#endif
	CMy11��ʵ���_0Set* m_pSet;

// ����
public:
	CMy11��ʵ���_0Doc* GetDocument() const;

// ����
public:
	int flag = 0;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMy11��ʵ���_0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	double ID;
	CString name;
	double number;
	double age;
	double phoneNum;
	afx_msg void OnBnClickedButton1();
	void foo(CImage& img, int& sx, int& sy, int& w, int& h);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void ShowPicture();
};

#ifndef _DEBUG  // 11��ʵ���_0View.cpp �еĵ��԰汾
inline CMy11��ʵ���_0Doc* CMy11��ʵ���_0View::GetDocument() const
   { return reinterpret_cast<CMy11��ʵ���_0Doc*>(m_pDocument); }
#endif

