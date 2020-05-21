
// 11周实验课_0View.cpp : CMy11周实验课_0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11周实验课_0.h"
#endif

#include "11周实验课_0Set.h"
#include "11周实验课_0Doc.h"
#include "11周实验课_0View.h"
#include "ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11周实验课_0View

IMPLEMENT_DYNCREATE(CMy11周实验课_0View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11周实验课_0View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11周实验课_0View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11周实验课_0View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11周实验课_0View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11周实验课_0View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11周实验课_0View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy11周实验课_0View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11周实验课_0View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11周实验课_0View::ShowPicture)
END_MESSAGE_MAP()

// CMy11周实验课_0View 构造/析构

CMy11周实验课_0View::CMy11周实验课_0View()
	: CRecordView(IDD_MY11_0_FORM)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phoneNum(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMy11周实验课_0View::~CMy11周实验课_0View()
{
}

void CMy11周实验课_0View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CMy11周实验课_0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11周实验课_0View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11周实验课_0Set;
	CRecordView::OnInitialUpdate();

}


// CMy11周实验课_0View 诊断

#ifdef _DEBUG
void CMy11周实验课_0View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11周实验课_0View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11周实验课_0Doc* CMy11周实验课_0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11周实验课_0Doc)));
	return (CMy11周实验课_0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11周实验课_0View 数据库支持
CRecordset* CMy11周实验课_0View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11周实验课_0View 消息处理程序


void CMy11周实验课_0View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CMy11周实验课_0View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
}


void CMy11周实验课_0View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11周实验课_0View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev(); 
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE); 
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11周实验课_0View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11周实验课_0View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11周实验课_0View::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag)
		flag = 0;
	else
		flag = 1;
}


void CMy11周实验课_0View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	filename = m_pSet->column5;
	ADD_DLG* dlg = new ADD_DLG;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(1);
}


void CMy11周实验课_0View::ShowPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	
}
