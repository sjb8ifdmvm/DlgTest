
// DlgTestDlg.h : 標頭檔
//

#pragma once

/////////////////////////////////////////////
//Lesson2 START
/////////////////////////////////////////////
//頭文件定義消息參數
//參數建議為 WM_USER + 1 開始 避免與系統已定義之參數重複
#define WM_CLICKME_MSG (WM_USER + 100)
/////////////////////////////////////////////
//Lesson2 END
/////////////////////////////////////////////


// CDlgTestDlg 對話方塊
class CDlgTestDlg : public CDialog
{
// 建構
public:
	CDlgTestDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_DLGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	/////////////////////////////////////////////
	//Lesson2 START
	/////////////////////////////////////////////
	afx_msg void OnBnClickedButton1();
	afx_msg LRESULT GetParamFromBTN1(WPARAM wParam, LPARAM lParam);
	/////////////////////////////////////////////
	//Lesson2 END
	/////////////////////////////////////////////
	afx_msg void OnBnClickedEnumwindowButton();
};
