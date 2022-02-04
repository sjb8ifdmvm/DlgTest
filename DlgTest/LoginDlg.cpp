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