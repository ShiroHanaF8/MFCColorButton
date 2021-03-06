
// MFCButtonDlg.h : ヘッダー ファイル
//

#pragma once

#include "MFCColorButton.h"

// CMFCButtonDlg ダイアログ
class CMFCButtonDlg : public CDialogEx
{
// コンストラクション
public:
	CMFCButtonDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBUTTON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_button1;
	CMFCButton m_colorButton;
	MFCColorButton m_buttonMFC;
	CMFCButton m_radio2;
	CMFCButton m_radio3;
	MFCColorButton m_radio4;
	MFCColorButton m_radio5;
	MFCColorButton m_check;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
};
