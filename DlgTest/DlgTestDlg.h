
// DlgTestDlg.h : ���Y��
//

#pragma once

/////////////////////////////////////////////
//Lesson2 START
/////////////////////////////////////////////
//�Y���w�q�����Ѽ�
//�Ѽƫ�ĳ�� WM_USER + 1 �}�l �קK�P�t�Τw�w�q���Ѽƭ���
#define WM_CLICKME_MSG (WM_USER + 100)
/////////////////////////////////////////////
//Lesson2 END
/////////////////////////////////////////////


// CDlgTestDlg ��ܤ��
class CDlgTestDlg : public CDialog
{
// �غc
public:
	CDlgTestDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_DLGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
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
