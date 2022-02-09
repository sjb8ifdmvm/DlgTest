// LoginDlg.cpp : ��@��
//

#include "stdafx.h"
#include "DlgTest.h"
#include "LoginDlg.h"


// CLoginDlg ��ܤ��

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


// CLoginDlg �T���B�z�`��

//////////////////////////////////////////////////////
//Lesson1 START
//////////////////////////////////////////////////////
void CLoginDlg::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CString strID;
	CString strPass;
	GetDlgItemText(IDC_USER_EDIT,strID);
	GetDlgItemText(IDC_PASS_EDIT,strPass);
	if(strID.IsEmpty() || strPass.IsEmpty())
	{
		MessageBox(_T("�b���αK�X���o���šI"), _T("����"), MB_OK);
		return;
	}
	else if(strID != _T("1") || strPass != _T("1"))
	{
		MessageBox(_T("�b���αK�X���~�I"), _T("����"), MB_OK);
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

	// TODO:  �b���[�J�B�~����l��

	if (hPreWnd == NULL) {
		hPreWnd = m_hWnd;
	}
	else {
		AfxMessageBox(_T("�{�ǹB�椤"));
		::ShowWindow(hPreWnd, SW_NORMAL);
		::SetForegroundWindow(hPreWnd);
		ExitProcess(0);
		return FALSE;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}


void CLoginDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �b���[�J�z���T���B�z�`���{���X
}
