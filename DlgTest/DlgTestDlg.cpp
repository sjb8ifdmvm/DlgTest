
// DlgTestDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "DlgTest.h"
#include "DlgTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDlgTestDlg 對話方塊




CDlgTestDlg::CDlgTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_TEST_BUTTON, &CDlgTestDlg::OnBnClickedButton1)
	/////////////////////////////////////////////
	//Lesson2 START
	/////////////////////////////////////////////
	ON_MESSAGE(WM_CLICKME_MSG, &CDlgTestDlg::GetParamFromBTN1)
	/////////////////////////////////////////////
	//Lesson2 END
	/////////////////////////////////////////////
	ON_BN_CLICKED(IDC_ENUMWINDOW_BUTTON, &CDlgTestDlg::OnBnClickedEnumwindowButton)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTestDlg 訊息處理常式

BOOL CDlgTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此加入額外的初始設定

	//方法二
	//SetProp + EnumWindows
	HWND hPreWnd = NULL;
	::EnumWindows(EnumWndProc, (LPARAM)&hPreWnd);
	if (hPreWnd != NULL) {
		AfxMessageBox(_T("程序運行中"));
		::ShowWindow(hPreWnd, SW_NORMAL);
		::SetForegroundWindow(hPreWnd);
		ExitProcess(0);
		return FALSE;
	}
	::SetProp(m_hWnd, g_szPropName, g_hValue);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CDlgTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CDlgTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CDlgTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/////////////////////////////////////////////
//Lesson2 START
/////////////////////////////////////////////
void CDlgTestDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//MessageBox(L"測試按鈕功能 OK!",L"提示", 0);
	WPARAM wp = 103;
	TCHAR Buffer[] = L"消息傳送測試";
	SendMessage(WM_CLICKME_MSG, wp, (LPARAM)Buffer);
}

LRESULT CDlgTestDlg::GetParamFromBTN1(WPARAM wParam, LPARAM lParam)
{
	//TCHAR* pStr = (TCHAR *)lParam;

	CString strText;
	strText.Format(_T("wParam=%d \nlParam=%s"), wParam, (wchar_t*)lParam);
	MessageBox(strText, 0, 0);
	return TRUE;
}
/////////////////////////////////////////////
//Lesson2 END
/////////////////////////////////////////////

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	TCHAR titleText[MAX_PATH] = { 0 };
	::GetWindowText(hwnd, titleText, MAX_PATH);
	if (_tcslen(titleText) > 0 )
	{
		AfxMessageBox(titleText);
	}
	return TRUE;
}


void CDlgTestDlg::OnBnClickedEnumwindowButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	//方法一
	/*
	TCHAR titleText[MAX_PATH] = { 0 };

	//查找桌面的子視窗
	HWND nHwnd = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
	while (nHwnd != NULL) {
		::GetWindowText(nHwnd, titleText, MAX_PATH);
		if (_tcslen(titleText) > 0)
		{
			MessageBox(titleText);
		}
		//GW_HWNDNEXT 查找下一個
		nHwnd = ::GetWindow(nHwnd, GW_HWNDNEXT);
	}
	*/

	//方法二
	/*
	TCHAR titleText[MAX_PATH] = { 0 };

	HWND nHwnd = ::FindWindow(NULL, NULL);
	while (nHwnd != NULL) {
		::GetWindowText(nHwnd, titleText, MAX_PATH);
		if (_tcslen(titleText) > 0)
		{
			MessageBox(titleText);
		}
		nHwnd = ::FindWindowEx(0, nHwnd, NULL, NULL);
	}
	*/

	//方法三
	//建議使用該方法
	/*
	EnumWindows(EnumWindowsProc, NULL);
	MessageBox(L"窗口查找完成！", L"提示", 0);
	*/

	//方法四
	//方法三之進階函式
	/*
	EnumChildWindows(NULL, EnumWindowsProc, NULL);
	MessageBox(L"窗口查找完成！", L"提示", 0);
	*/

	//方法五
	//類別及標題之查找
	/*
	HWND hCalc = ::FindWindow(_T("ApplicationFrameWindow"), _T("小算盤"));
	if (hCalc) {
		::SetWindowText(hCalc, _T("sjb8ifdmvm 的計算機"));
		HWND hSub = ::FindWindowEx(hCalc, NULL, _T("ApplicationFrameInputSinkWindow"), NULL);
		::SendMessage(hSub, WM_SETTEXT, 0, (LPARAM)_T("85201478"));

	}
	*/

	//方法六
	//FindWindowEx查找子視窗
	/*
	HWND hWnd = ::FindWindow(_T("Afx:00007FF638DC0000:8:0000000000010003:0000000000000000:000000003CAC0C3D"), _T("MFCDlgTest1 - MFC_DlgTest"));
	if (hWnd) {
		::SetWindowText(hWnd, _T("sjb8ifdmvm 的軟體"));
		HWND hSub = ::FindWindowEx(hWnd, NULL, L"Afx:ControlBar:38dc0000:8:10003:10", L"類別檢視");
		if (hSub)
		{
			::SetWindowText(hSub, L"Edit OK!");
		}
	}
	*/

	//方法7
	//鑒於FindWindowEx較容易出現不確定的情況 故使用GetDlgItem查找
	/*
	HWND hWnd = ::FindWindow(L"Notepad", L"文字.txt - 記事本");
	if (hWnd) {
		//HWND parent = ::GetParent(hWnd);
		::SetWindowText(hWnd, _T("sjb8ifdmvm 的筆記本"));
		HWND hSub = ::GetDlgItem(hWnd, 0xF);
		if (hSub)
		{
			::SendMessage(hSub, WM_SETTEXT, NULL, (LPARAM)L"傳送訊息測試 OK!");
		}
	}
	*/

	//Ex:獲取Proccess ID
	DWORD ProcID;
	HWND hWnd = ::FindWindow(L"Notepad", L"文字.txt - 記事本");
	GetWindowThreadProcessId(hWnd, &ProcID);
	CString strID;
	strID.Format(L"Proc:%d", ProcID);
	MessageBox(strID);
}


void CDlgTestDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 在此加入您的訊息處理常式程式碼

	//方法二
	//SetProp + EnumWindows
	::RemoveProp(m_hWnd, g_szPropName);
}
