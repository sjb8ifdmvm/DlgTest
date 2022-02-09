// LoginDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "DlgTest.h"
#include "LoginDlg.h"


// CLoginDlg 對話方塊

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CLoginDlg 訊息處理常式

//////////////////////////////////////////////////////
//Lesson1 START
//////////////////////////////////////////////////////
void CLoginDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CString strID;
	CString strPass;
	GetDlgItemText(IDC_USER_EDIT,strID);
	GetDlgItemText(IDC_PASS_EDIT,strPass);
	if(strID.IsEmpty() || strPass.IsEmpty())
	{
		MessageBox(_T("帳號或密碼不得為空！"), _T("提示"), MB_OK);
		return;
	}
	else if(strID != _T("1") || strPass != _T("1"))
	{
		MessageBox(_T("帳號或密碼錯誤！"), _T("提示"), MB_OK);
		return;
	}
	OnOK();
}

//////////////////////////////////////////////////////
//Lesson1 END
//////////////////////////////////////////////////////

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此加入額外的初始化

	if (hPreWnd == NULL) {
		hPreWnd = m_hWnd;
	}
	else {
		AfxMessageBox(_T("程序運行中"));
		::ShowWindow(hPreWnd, SW_NORMAL);
		::SetForegroundWindow(hPreWnd);
		ExitProcess(0);
		return FALSE;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void CLoginDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 在此加入您的訊息處理常式程式碼
}
