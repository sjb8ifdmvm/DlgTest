
// DlgTest.cpp : �w�q���ε{�������O�欰�C
//

#include "stdafx.h"
#include "DlgTest.h"
#include "DlgTestDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��k�G
//SetProp + EnumWindows
TCHAR g_szPropName[] = _T("{42830D12-C55C-49A6-AEEA-B6B2F68B784F}");
HANDLE g_hValue = (HANDLE)9527;;

// CDlgTestApp

BEGIN_MESSAGE_MAP(CDlgTestApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDlgTestApp �غc

CDlgTestApp::CDlgTestApp()
{
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CDlgTestApp ����

CDlgTestApp theApp;


// CDlgTestApp ��l�]�w

BOOL CDlgTestApp::InitInstance()
{
	// ���p���ε{����T�M����w�ϥ� ComCtl32.dll 6 (�t) �H�᪩���A
	// �ӱҰʵ�ı�Ƽ˦��A�b Windows XP �W�A�h�ݭn InitCommonControls()�C
	// �_�h����������إ߳��N���ѡC
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �]�w�n�]�t�Ҧ��z�Q�n�Ω����ε{������
	// �q�α�����O�C
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// �зǪ�l�]�w
	// �p�G�z���ϥγo�ǥ\��åB�Q���
	// �̫᧹�����i�����ɤj�p�A�z�i�H
	// �q�U�C�{���X�������ݭn����l�Ʊ`���A
	// �ܧ��x�s�]�w�Ȫ��n�����X
	// TODO: �z���ӾA�׭ק惡�r��
	// (�Ҧp�A���q�W�٩β�´�W��)
	SetRegistryKey(_T("���� AppWizard �Ҳ��ͪ����ε{��"));

	//HANDLE m_hMutex = ::CreateMutex(NULL, FALSE, _T("{42830D12-C55C-49A6-AEEA-B6B2F68B784F}"));
	//if (GetLastError() == ERROR_ALREADY_EXISTS) {
	//	HWND hWnd = ::FindWindow(_T("#32770"), _T("�n�J"));
	//	if (hWnd != NULL) {
	//		AfxMessageBox(_T("�{�ǹB�椤"));
	//		::ShowWindow(hWnd, SW_NORMAL);
	//		::SetForegroundWindow(hWnd);
	//		CloseHandle(&m_hMutex);
	//		m_hMutex = NULL;
	//		return FALSE;
	//	}
	//	else if ((hWnd = ::FindWindow(L"#32770", L"DlgTest")) != NULL)
	//	{
	//		AfxMessageBox(_T("�{�ǹB�椤"));
	//		::ShowWindow(hWnd, SW_NORMAL);
	//		::SetForegroundWindow(hWnd);
	//		CloseHandle(&m_hMutex);
	//		m_hMutex = NULL;
	//		return FALSE;
	//	}
	//}

	////////////////////////////////
	///////Lesson1 START
	////////////////////////////////
	CLoginDlg loginDlg;
	INT_PTR iRet = loginDlg.DoModal();
	if (iRet == IDCANCEL)
	{
		//if (m_hMutex) {
		//	CloseHandle(&m_hMutex);
		//	m_hMutex = NULL;
		//}

		return FALSE;
	}
	////////////////////////////////
	///////Lesson1 END
	////////////////////////////////

	CDlgTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �b����m��ϥ� [�T�w] �Ӱ���ϥι�ܤ����
		// �B�z���{���X
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �b����m��ϥ� [����] �Ӱ���ϥι�ܤ����
		// �B�z���{���X
	}

	//if (m_hMutex) {
	//	CloseHandle(&m_hMutex);
	//	m_hMutex = NULL;
	//}
	// �]���w�g������ܤ���A�Ǧ^ FALSE�A�ҥH�ڭ̷|�������ε{���A
	// �ӫD���ܶ}�l���ε{�����T���C
	return FALSE;
}

//��k�G
//SetProp + EnumWindows
BOOL CALLBACK EnumWndProc(HWND hwnd, LPARAM lParam)
{
	HANDLE hProp = GetProp(hwnd, g_szPropName);
	if (hProp == g_hValue) {
		*(HWND*)lParam = hwnd;
		return FALSE;
	}
	return TRUE;
}