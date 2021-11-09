#include "pch.h"
#include "MFCColorButton.h"
BEGIN_MESSAGE_MAP(MFCColorButton, CMFCButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


MFCColorButton::MFCColorButton()
	:m_checkedBrush(RGB(100,100,255)),
	m_uncheckedBrush(RGB(255,200,200)),
	m_hilightedBrush(RGB(200,200,255))
{
	//m_bDontUseWinXPTheme = TRUE;
	//m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;

	// テキストカラー
	//tTextHotColor(RGB(0, 255, 255)); // シアン
	//tTextColor(RGB(255, 255, 0)); // 黄

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
			m_roundSize = 8;
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
	}
}

MFCColorButton::~MFCColorButton()
{
	m_checkedBrush.DeleteObject();
	m_uncheckedBrush.DeleteObject();
	m_hilightedBrush.DeleteObject();
}


BOOL MFCColorButton::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	return CMFCButton::OnWndMsg(message, wParam, lParam, pResult);
}

//void MFCColorButton::OnFillBackground(CDC* pDC, const CRect& rectClient)
//{
//	if (IsChecked()) {
//		m_clrFace = RGB(255, 0, 0); // 赤
//	}
//	else {
//		m_clrFace = RGB(0, 0, 255); // 青
//	}
//	return CMFCButton::OnFillBackground(pDC, rectClient);
//
//}

void MFCColorButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
{
	CMFCButton::OnDrawBorder(pDC, rectClient, uiState);

	CBrush *newBrush = nullptr;

	if (m_bHighlighted) {
		newBrush = &m_hilightedBrush;
	}
	else {
		newBrush = IsChecked() ? &m_checkedBrush : &m_uncheckedBrush;
	}

	if (newBrush == nullptr) {
		return;
	}

	auto old = SelectObject(pDC->m_hDC, *newBrush);
	const int roundNum = m_isRoundButton ? m_roundSize : 0;
	POINT round = { roundNum, roundNum };
	pDC->RoundRect(rectClient, round);
	SelectObject(pDC->m_hDC, old);

}

//void MFCColorButton::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
//{
//
//	return CMFCButton::OnDraw(pDC, rect, uiState);
//}

void MFCColorButton::OnDrawFocusRect(CDC* pDC, const CRect& rectClient)
{
	// フォーカス枠は邪魔なので削除
}
