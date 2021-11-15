#pragma once
#include <afxbutton.h>
class MFCColorButton :
    public CMFCButton
{
public:
    MFCColorButton();
    virtual ~MFCColorButton();

private:
    bool m_isRoundButton;
    int m_roundSize;
    const COLORREF m_checkedColor;

    void SetButtonStyleFromBuildVersion();

protected:
    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    BOOL IsHighContrastMode();
};

