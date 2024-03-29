
// DlgTest.cpp : 定義應用程式的類別行為。
//

#include "stdafx.h"
#include "DlgTest.h"
#include "DlgTestDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgTestApp

BEGIN_MESSAGE_MAP(CDlgTestApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDlgTestApp 建構

CDlgTestApp::CDlgTestApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CDlgTestApp 物件

CDlgTestApp theApp;


// CDlgTestApp 初始設定

BOOL CDlgTestApp::InitInstance()
{
	// 假如應用程式資訊清單指定使用 ComCtl32.dll 6 (含) 以後版本，
	// 來啟動視覺化樣式，在 Windows XP 上，則需要 InitCommonControls()。
	// 否則任何視窗的建立都將失敗。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 設定要包含所有您想要用於應用程式中的
	// 通用控制項類別。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));

	HANDLE m_hMutex = ::CreateMutex(NULL, FALSE, _T("{42830D12-C55C-49A6-AEEA-B6B2F68B784F}"));
	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		HWND hWnd = ::FindWindow(_T("#32770"), _T("登入"));
		if (hWnd != NULL) {
			AfxMessageBox(_T("程序運行中"));
			::ShowWindow(hWnd, SW_NORMAL);
			::SetForegroundWindow(hWnd);
			CloseHandle(&m_hMutex);
			m_hMutex = NULL;
			return FALSE;
		}
		else if ((hWnd = ::FindWindow(L"#32770", L"DlgTest")) != NULL)
		{
			AfxMessageBox(_T("程序運行中"));
			::ShowWindow(hWnd, SW_NORMAL);
			::SetForegroundWindow(hWnd);
			CloseHandle(&m_hMutex);
			m_hMutex = NULL;
			return FALSE;
		}
	}


	////////////////////////////////
	///////Lesson1 START
	////////////////////////////////
	CLoginDlg loginDlg;
	INT_PTR iRet = loginDlg.DoModal();
	if (iRet == IDCANCEL)
	{
		if (m_hMutex) {
			CloseHandle(&m_hMutex);
			m_hMutex = NULL;
		}

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
		// TODO: 在此放置於使用 [確定] 來停止使用對話方塊時
		// 處理的程式碼
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置於使用 [取消] 來停止使用對話方塊時
		// 處理的程式碼
	}

	if (m_hMutex) {
		CloseHandle(&m_hMutex);
		m_hMutex = NULL;
	}
	// 因為已經關閉對話方塊，傳回 FALSE，所以我們會結束應用程式，
	// 而非提示開始應用程式的訊息。
	return FALSE;
}
