#pragma once
#include <afxbutton.h>
class MFCColorButton :
    public CMFCButton
{
public:
    MFCColorButton();
    virtual ~MFCColorButton();

private:
    bool m_isRoundButton = false;
    int m_roundSize = 5; // Windows11ÇÃïWèÄ

    void SetButtonStyleFromBuildVersion();

    const COLORREF m_checkedColor = RGB(210, 240, 255);

protected:

    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    BOOL IsHighContrastMode();
};

