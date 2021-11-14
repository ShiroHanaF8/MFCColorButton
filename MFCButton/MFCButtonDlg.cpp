
// MFCButtonDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MFCButton.h"
#include "MFCButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCButtonDlg ダイアログ



CMFCButtonDlg::CMFCButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_colorButton);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_buttonMFC);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_RADIO3, m_radio3);
	DDX_Control(pDX, IDC_RADIO4, m_radio4);
	DDX_Control(pDX, IDC_RADIO5, m_radio5);
	DDX_Control(pDX, IDC_CHECK1, m_check);
}

BEGIN_MESSAGE_MAP(CMFCButtonDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO2, &CMFCButtonDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCButtonDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CMFCButtonDlg メッセージ ハンドラー

BOOL CMFCButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	m_radio2.SetCheck(TRUE);

	m_radio4.SetCheck(TRUE);

	auto icon = LoadIcon(NULL, IDI_HAND);
	m_radio4.SetIcon(icon);

	icon = LoadIcon(NULL, IDI_INFORMATION);
	m_radio5.SetIcon(icon);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCButtonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCButtonDlg::OnBnClickedRadio2()
{
	m_radio4.EnableWindow(TRUE);
	m_radio5.EnableWindow(TRUE);
}


void CMFCButtonDlg::OnBnClickedRadio3()
{
	m_radio4.EnableWindow(FALSE);
	m_radio5.EnableWindow(FALSE);
}
