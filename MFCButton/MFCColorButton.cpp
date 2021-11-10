#include "pch.h"
#include "MFCColorButton.h"
BEGIN_MESSAGE_MAP(MFCColorButton, CMFCButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


MFCColorButton::MFCColorButton()
	:m_uncheckedBrush(GetGlobalData()->clrBtnLight),
	m_borderPen(PS_SOLID, 1, GetGlobalData()->clrActiveBorder)
{
	m_bDontUseWinXPTheme = FALSE;
	m_nFlatStyle = BUTTONSTYLE_3D;



	if (GetGlobalData()->IsHighContrastMode()) {
		m_checkedBrush.CreateSolidBrush(GetGlobalData()->clrBtnShadow);
	}
	else {
		m_checkedBrush.CreateSolidBrush(RGB(210, 240, 255));
	}

	SetButtonStyleFromBuildVersion();
}

void MFCColorButton::SetButtonStyleFromBuildVersion()
{
	HMODULE hMod;
	hMod = LoadLibrary(_T("ntdll.dll"));
	if (hMod) {
		OSVERSIONINFOEXW osw = {};
		void(WINAPI * func)(OSVERSIONINFOEXW*) = (void(WINAPI*)(OSVERSIONINFOEXW*))GetProcAddress(hMod, "RtlGetVersion");
		if (func == nullptr) {
			FreeLibrary(hMod);
		}
		osw.dwOSVersionInfoSize = sizeof(osw);
		func(&osw);
		FreeLibrary(hMod);

		const DWORD buildVer = osw.dwBuildNumber;
		if (buildVer >= 22000) { // Windows 11
			m_isRoundButton = true;
			m_roundSize = 5;
		}
		else if (buildVer > 10000) { // Windows 10
			m_isRoundButton = false;
		}
		else if (buildVer > 9000) { // Windows 8
			m_isRoundButton = false;
		}
		else if (buildVer > 6000) { // Windows XP
			m_isRoundButton = true;
			m_roundSize = 10;
		}
		else {
			m_isRoundButton = false;
		}
	}
}

MFCColorButton::~MFCColorButton()
{
	m_checkedBrush.DeleteObject();
	m_uncheckedBrush.DeleteObject();
}


BOOL MFCColorButton::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	return CMFCButton::OnWndMsg(message, wParam, lParam, pResult);
}

//void MFCColorButton::OnFillBackground(CDC* pDC, const CRect& rectClient)
//{
//	if (IsChecked()) {
//		m_clrFace = RGB(255, 0, 0); // Ô
//	}
//	else {
//		m_clrFace = RGB(0, 0, 255); // Â
//	}
//	return CMFCButton::OnFillBackground(pDC, rectClient);
//
//}

void MFCColorButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
{
	CMFCButton::OnDrawBorder(pDC, rectClient, uiState);

	CBrush *newBrush = nullptr;

	if (m_bHighlighted && !IsChecked()) {
		return;
	}
	else {
		newBrush = IsChecked() ? &m_checkedBrush : &m_uncheckedBrush;
	}

	if (newBrush == nullptr) {
		return;
	}

	auto oldBrush = SelectObject(pDC->m_hDC, *newBrush);
	auto oldPen = SelectObject(pDC->m_hDC, m_borderPen);
	const int roundNum = (m_isRoundButton && !GetGlobalData()->IsHighContrastMode()) ? m_roundSize : 0;
	POINT round = { roundNum, roundNum };
	pDC->RoundRect(rectClient, round);
	SelectObject(pDC->m_hDC, oldBrush);
	SelectObject(pDC->m_hDC, oldPen);

}

//void MFCColorButton::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
//{
//
//	return CMFCButton::OnDraw(pDC, rect, uiState);
//}

void MFCColorButton::OnDrawFocusRect(CDC* pDC, const CRect& rectClient)
{
	return CMFCButton::OnDrawFocusRect(pDC, rectClient);
}
