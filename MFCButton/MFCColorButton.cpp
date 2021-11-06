#include "pch.h"
#include "MFCColorButton.h"
BEGIN_MESSAGE_MAP(MFCColorButton, CMFCButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


MFCColorButton::MFCColorButton()
{
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
		if (IsWindowsThemingEnabled()) {
			EnableWindowsTheming(FALSE);
		}

		if (IsChecked()) {
			SetFaceColor(RGB(255, 0, 0));
		}
		else {
			SetFaceColor(RGB(0, 255, 0));
		}
		//TRACE(_T("%8X %8X %8X\n"), message, wParam, lParam);
	}

	return CMFCButton::OnWndMsg(message, wParam, lParam, pResult);
}
