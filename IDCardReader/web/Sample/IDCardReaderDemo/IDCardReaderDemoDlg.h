
// IDCardReaderDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CIDCardReaderDemoDlg 对话框
class CIDCardReaderDemoDlg : public CDialog
{
// 构造
public:
	CIDCardReaderDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IDCARDREADERDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboComport;
	CComboBox m_combSector;
	CComboBox m_comboBlock;
	afx_msg void OnBnClickedBtnConsam();
	afx_msg void OnBnClickedBtnDisconnsam();
	afx_msg void OnBnClickedBtnReadidr();
	CStatic m_bmpPhoto;
	afx_msg void OnBnClickedBtnIcread();
	afx_msg void OnBnClickedBtnIcwrite();
	afx_msg void OnBnClickedBtnIcsnr();
	afx_msg void OnBnClickedBtnIdsnr();
	afx_msg void OnBnClickedBnGetdbcode();
};
