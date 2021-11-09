#pragma once
#include <afxbutton.h>
class MFCColorButton :
    public CMFCButton
{
public:
    MFCColorButton();
    virtual ~MFCColorButton();

public:
    DECLARE_MESSAGE_MAP()

private:
    CBrush m_checkedBrush;
    CBrush m_uncheckedBrush;
    CBrush m_hilightedBrush;
    bool m_isRoundButton = false;
    int m_roundSize = 8; // Windows11ÇÃïWèÄ

    void SetButtonStyleFromBuildVersion();
public:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

protected:
    //virtual void OnFillBackground(CDC* pDC, const CRect& rectClient);

    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    //virtual void OnDraw(CDC* pDC, const CRect& rect, UINT uiState);
    virtual void OnDrawFocusRect(CDC* pDC, const CRect& rectClient);
};

