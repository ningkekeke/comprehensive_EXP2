// ADD_DLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "11��ʵ���_0.h"
#include "ADD_DLG.h"
#include "afxdialogex.h"
#include "11��ʵ���_0Set.h"
#include "MainFrm.h"
#include "11��ʵ���_0Doc.h"
#include "11��ʵ���_0View.h"
// ADD_DLG �Ի���
IMPLEMENT_DYNAMIC(ADD_DLG, CDialogEx)

ADD_DLG::ADD_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ADD_DLG::~ADD_DLG()
{
}

void ADD_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ADD_DLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ADD_DLG::OnBnClickedButton2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ADD_DLG ��Ϣ�������


void ADD_DLG::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ADD_DLG::OnPaint()
{
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CMy11��ʵ���_0View* pView = (CMy11��ʵ���_0View*)pFrame->GetActiveView();
	CPaintDC dc(this); 
	CImage img;
	img.Load(pView->filename);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC2)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void ADD_DLG::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&rect);
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
