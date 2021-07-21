
// IDCardReaderDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CIDCardReaderDemoDlg �Ի���
class CIDCardReaderDemoDlg : public CDialog
{
// ����
public:
	CIDCardReaderDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IDCARDREADERDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
