#include "pch.h"
#include "MFCColorButton.h"


MFCColorButton::MFCColorButton()
{
	m_bDontUseWinXPTheme = FALSE;
	m_nFlatStyle = BUTTONSTYLE_3D;

	SetButtonStyleFromBuildVersion();
}

void MFCColorButton::SetButtonStyleFromBuildVersion()
{
	HMODULE hMod = GetModuleHandle(_T("ntdll.dll")); // ロード済みのため再ロードしない
	if (hMod) {
		OSVERSIONINFOEXW osw = {};
		void(WINAPI * func)(OSVERSIONINFOEXW*) = (void(WINAPI*)(OSVERSIONINFOEXW*))GetProcAddress(hMod, "RtlGetVersion");
		if (func == nullptr) {
			FreeLibrary(hMod);
			return;
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
	else {
		m_isRoundButton = false;
	}
}

MFCColorButton::~MFCColorButton()
{
}

void MFCColorButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
{
	CMFCButton::OnDrawBorder(pDC, rectClient, uiState);

	if (IsChecked() && this->IsWindowEnabled()) {
		COLORREF color = {};
		if (IsHighContrastMode()) {
			color = GetGlobalData()->clrBtnShadow;
		}
		else {
			color = m_checkedColor;
		}
		CBrush brush(color);
		auto oldBrush = SelectObject(pDC->m_hDC, brush);
		CPen pen(PS_SOLID, 0, GetGlobalData()->clrActiveBorder);
		auto oldPen = SelectObject(pDC->m_hDC, pen);
		const int roundNum = (m_isRoundButton && !IsHighContrastMode()) ? m_roundSize : 0;
		POINT round = { roundNum, roundNum };
		pDC->RoundRect(rectClient, round);
		SelectObject(pDC->m_hDC, oldBrush);
		SelectObject(pDC->m_hDC, oldPen);
	}
}

BOOL MFCColorButton::IsHighContrastMode()
{
	HIGHCONTRAST hc = {};
	hc.cbSize = sizeof(HIGHCONTRAST);
	SystemParametersInfo(SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), &hc, 0);
	return hc.dwFlags & HCF_HIGHCONTRASTON;
}