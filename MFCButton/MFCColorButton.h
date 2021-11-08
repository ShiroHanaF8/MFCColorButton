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
    bool m_initialized = false;
    CBrush m_redBrush;
    CBrush m_greenBrush;
    CBrush m_blueBrush;
public:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

protected:
    virtual void OnFillBackground(CDC* pDC, const CRect& rectClient);

    //virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    //virtual void OnDraw(CDC* pDC, const CRect& rect, UINT uiState);
    //virtual void OnDrawFocusRect(CDC* pDC, const CRect& rectClient);
    //void DrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
};

