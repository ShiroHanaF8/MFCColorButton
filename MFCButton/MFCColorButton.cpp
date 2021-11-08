#include "pch.h"
#include "MFCColorButton.h"
BEGIN_MESSAGE_MAP(MFCColorButton, CMFCButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


MFCColorButton::MFCColorButton()
{
	m_bTransparent = FALSE;
	m_bDontUseWinXPTheme = TRUE;
}

MFCColorButton::~MFCColorButton()
{
}


void MFCColorButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
{
	return CMFCButton::OnDrawBorder(pDC, rectClient, uiState);
}


BOOL MFCColorButton::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if (message == WM_PAINT)
	{
		if (IsChecked()) {
			SetFaceColor(GetSysColor(COLOR_BTNHIGHLIGHT));
		}
		else {
			SetFaceColor(GetSysColor(COLOR_3DDKSHADOW));
		}

	}
	else if (message == WM_CTLCOLOR) {
		TRACE(_T("WM_CTLCOLOR %8X %8X\n"), wParam, lParam);
	}
	else if (message == WM_CTLCOLORBTN) {
		TRACE(_T("WM_CTLCOLORBTN %8X %8X\n"), wParam, lParam);
	}
	else {
		//TRACE(_T("%8X %8X %8X\n"), message, wParam, lParam);
	}

	return CMFCButton::OnWndMsg(message, wParam, lParam, pResult);
}
