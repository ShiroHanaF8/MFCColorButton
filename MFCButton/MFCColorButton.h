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
public:
    virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

