// ADD_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "11周实验课_0.h"
#include "ADD_DLG.h"
#include "afxdialogex.h"
#include "11周实验课_0Set.h"
#include "MainFrm.h"
#include "11周实验课_0Doc.h"
#include "11周实验课_0View.h"
// ADD_DLG 对话框
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


// ADD_DLG 消息处理程序


void ADD_DLG::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ADD_DLG::OnPaint()
{
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CMy11周实验课_0View* pView = (CMy11周实验课_0View*)pFrame->GetActiveView();
	CPaintDC dc(this); 
	CImage img;
	img.Load(pView->filename);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC2)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
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
