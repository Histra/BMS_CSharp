
// cgWGFillPoly.h : cgWGFillPoly Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CcgWGFillPolyApp:
// �йش����ʵ�֣������ cgWGFillPoly.cpp
//

class CcgWGFillPolyApp : public CWinApp
{
public:
	CcgWGFillPolyApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CcgWGFillPolyApp theApp;
