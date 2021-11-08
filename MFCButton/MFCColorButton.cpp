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
	SetTextHotColor(RGB(0, 255, 255)); // シアン
	SetTextColor(RGB(255, 255, 0)); // 黄

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
		m_clrFace = RGB(255, 0, 0); // 赤
	}
	else {
		m_clrFace = RGB(0, 0, 255); // 青
	}
	return CMFCButton::OnFillBackground(pDC, rectClient);

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
