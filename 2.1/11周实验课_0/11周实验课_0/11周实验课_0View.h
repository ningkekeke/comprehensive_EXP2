
// 11周实验课_0View.h : CMy11周实验课_0View 类的接口
//

#pragma once

class CMy11周实验课_0Set;

class CMy11周实验课_0View : public CRecordView
{
protected: // 仅从序列化创建
	CMy11周实验课_0View();
	DECLARE_DYNCREATE(CMy11周实验课_0View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY11_0_FORM };
#endif
	CMy11周实验课_0Set* m_pSet;

// 特性
public:
	CMy11周实验课_0Doc* GetDocument() const;

// 操作
public:
	int flag = 0;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMy11周实验课_0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 11周实验课_0View.cpp 中的调试版本
inline CMy11周实验课_0Doc* CMy11周实验课_0View::GetDocument() const
   { return reinterpret_cast<CMy11周实验课_0Doc*>(m_pDocument); }
#endif

