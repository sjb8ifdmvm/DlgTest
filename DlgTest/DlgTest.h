
// DlgTest.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CDlgTestApp:
// �аѾ\��@�����O�� DlgTest.cpp
//

class CDlgTestApp : public CWinAppEx
{
public:
	CDlgTestApp();

// �мg
	public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CDlgTestApp theApp;