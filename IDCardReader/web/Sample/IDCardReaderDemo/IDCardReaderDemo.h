
// IDCardReaderDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIDCardReaderDemoApp:
// �йش����ʵ�֣������ IDCardReaderDemo.cpp
//

class CIDCardReaderDemoApp : public CWinAppEx
{
public:
	CIDCardReaderDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIDCardReaderDemoApp theApp;