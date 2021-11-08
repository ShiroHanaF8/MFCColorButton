#include "pch.h"
#include "MFCColorButton.h"
BEGIN_MESSAGE_MAP(MFCColorButton, CMFCButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


MFCColorButton::MFCColorButton()
	:m_redBrush(RGB(255,0,0)),
	m_greenBrush(RGB(0,255,0)),
	m_blueBrush(RGB(0,0,255))
{
	m_bDontUseWinXPTheme = TRUE;
	m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;

	// テキストカラー
	SetTextHotColor(RGB(255, 0, 255)); // 紫
	SetTextColor(RGB(255, 255, 0)); // 黄
	m_clrFace = RGB(0, 255, 255); // シアン
}

MFCColorButton::~MFCColorButton()
{
}


BOOL MFCColorButton::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	return CMFCButton::OnWndMsg(message, wParam, lParam, pResult);
}

void MFCColorButton::OnFillBackground(CDC* pDC, const CRect& rectClient)
{
	if (IsChecked()) {
		pDC->FillRect(rectClient, &m_redBrush);
	}
	else {
		pDC->FillRect(rectClient, &m_blueBrush);
	}
}

//void MFCColorButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
//{
//	return CMFCButton::OnDrawBorder(pDC, rectClient, uiState);
//}

//void MFCColorButton::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
//{
//
//	return CMFCButton::OnDraw(pDC, rect, uiState);
//}

//void MFCColorButton::OnDrawFocusRect(CDC* pDC, const CRect& rectClient)
//{
//}
