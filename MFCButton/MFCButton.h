
// MFCButton.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCButtonApp:
// このクラスの実装については、MFCButton.cpp を参照してください
//

class CMFCButtonApp : public CWinApp
{
public:
	CMFCButtonApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCButtonApp theApp;
