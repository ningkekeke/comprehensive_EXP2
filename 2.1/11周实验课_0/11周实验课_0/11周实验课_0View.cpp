
// 11��ʵ���_0View.cpp : CMy11��ʵ���_0View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "11��ʵ���_0.h"
#endif

#include "11��ʵ���_0Set.h"
#include "11��ʵ���_0Doc.h"
#include "11��ʵ���_0View.h"
#include "ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11��ʵ���_0View

IMPLEMENT_DYNCREATE(CMy11��ʵ���_0View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11��ʵ���_0View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11��ʵ���_0View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11��ʵ���_0View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11��ʵ���_0View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11��ʵ���_0View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11��ʵ���_0View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy11��ʵ���_0View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11��ʵ���_0View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11��ʵ���_0View::ShowPicture)
END_MESSAGE_MAP()

// CMy11��ʵ���_0View ����/����

CMy11��ʵ���_0View::CMy11��ʵ���_0View()
	: CRecordView(IDD_MY11_0_FORM)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phoneNum(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMy11��ʵ���_0View::~CMy11��ʵ���_0View()
{
}

void CMy11��ʵ���_0View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CMy11��ʵ���_0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy11��ʵ���_0View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11��ʵ���_0Set;
	CRecordView::OnInitialUpdate();

}


// CMy11��ʵ���_0View ���

#ifdef _DEBUG
void CMy11��ʵ���_0View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11��ʵ���_0View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11��ʵ���_0Doc* CMy11��ʵ���_0View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11��ʵ���_0Doc)));
	return (CMy11��ʵ���_0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11��ʵ���_0View ���ݿ�֧��
CRecordset* CMy11��ʵ���_0View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11��ʵ���_0View ��Ϣ�������


void CMy11��ʵ���_0View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CImage img;
	img.Load(m_pSet->column5);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CMy11��ʵ���_0View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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


void CMy11��ʵ���_0View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
		pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11��ʵ���_0View::OnRecordPrev()
{
	// TODO: �ڴ���������������
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
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
		pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11��ʵ���_0View::OnRecordNext()
{
	// TODO: �ڴ���������������
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
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
		pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11��ʵ���_0View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	if (flag) {
		CImage img;
		img.Load(m_pSet->column5);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
		pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


void CMy11��ʵ���_0View::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flag)
		flag = 0;
	else
		flag = 1;
}


void CMy11��ʵ���_0View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	filename = m_pSet->column5;
	ADD_DLG* dlg = new ADD_DLG;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(1);
}


void CMy11��ʵ���_0View::ShowPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}
