#pragma once


// CLoginDlg 對話方塊

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~CLoginDlg();

// 對話方塊資料
	enum { IDD = IDD_LOGINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
