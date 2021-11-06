#pragma once
#include <afxbutton.h>
class MFCColorButton :
    public CMFCButton
{
public:
    MFCColorButton();
    virtual ~MFCColorButton();

    bool OninitDialog();

public:
    DECLARE_MESSAGE_MAP()

private:
    bool m_initialized = false;

};

