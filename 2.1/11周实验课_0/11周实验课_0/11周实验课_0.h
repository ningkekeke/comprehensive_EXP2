
// 11��ʵ���_0.h : 11��ʵ���_0 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy11��ʵ���_0App:
// �йش����ʵ�֣������ 11��ʵ���_0.cpp
//

class CMy11��ʵ���_0App : public CWinApp
{
public:
	CMy11��ʵ���_0App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11��ʵ���_0App theApp;
