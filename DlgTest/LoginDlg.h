#pragma once


// CLoginDlg ��ܤ��

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CLoginDlg();

// ��ܤ�����
	enum { IDD = IDD_LOGINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
