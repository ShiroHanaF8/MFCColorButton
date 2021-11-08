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
    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

protected:

    virtual void OnFillBackground(CDC* pDC, const CRect& rectClient);
    virtual void OnDrawFocusRect(CDC* pDC, const CRect& rectClient);
};

