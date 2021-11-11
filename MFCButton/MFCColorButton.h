#pragma once
#include <afxbutton.h>
class MFCColorButton :
    public CMFCButton
{
public:
    MFCColorButton();
    virtual ~MFCColorButton();

private:
    CBrush m_checkedBrush;
    CBrush m_uncheckedBrush;
    CPen m_borderPen;
    bool m_isRoundButton = false;
    int m_roundSize = 5; // Windows11�̕W��

    void SetButtonStyleFromBuildVersion();
public:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

protected:
    //virtual void OnFillBackground(CDC* pDC, const CRect& rectClient);

    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    //virtual void OnDraw(CDC* pDC, const CRect& rect, UINT uiState);
    virtual void OnDrawFocusRect(CDC* pDC, const CRect& rectClient);
};

