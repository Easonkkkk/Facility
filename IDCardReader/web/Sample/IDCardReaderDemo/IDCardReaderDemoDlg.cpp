
// IDCardReaderDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IDCardReaderDemo.h"
#include "IDCardReaderDemoDlg.h"
#include "include/termb.h"
#include "include/mffunc.h"

CString g_app_path = _T("");

#ifdef _WIN64
#pragma comment(lib, "lib/x64/termb.lib")
#else
#pragma comment(lib, "lib/x86/termb.lib")
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CIDCardReaderDemoDlg 对话框




CIDCardReaderDemoDlg::CIDCardReaderDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIDCardReaderDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIDCardReaderDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_comboComport);
	DDX_Control(pDX, IDC_COMBO_SECTOR, m_combSector);
	DDX_Control(pDX, IDC_COMBO_BLOCK, m_comboBlock);
	DDX_Control(pDX, IDC_STATIC_PHOTO, m_bmpPhoto);
}

BEGIN_MESSAGE_MAP(CIDCardReaderDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CONSAM, &CIDCardReaderDemoDlg::OnBnClickedBtnConsam)
	ON_BN_CLICKED(IDC_BTN_DISCONNSAM, &CIDCardReaderDemoDlg::OnBnClickedBtnDisconnsam)
	ON_BN_CLICKED(IDC_BTN_READIDR, &CIDCardReaderDemoDlg::OnBnClickedBtnReadidr)
	ON_BN_CLICKED(IDC_BTN_ICREAD, &CIDCardReaderDemoDlg::OnBnClickedBtnIcread)
	ON_BN_CLICKED(IDC_BTN_ICWRITE, &CIDCardReaderDemoDlg::OnBnClickedBtnIcwrite)
	ON_BN_CLICKED(IDC_BTN_ICSNR, &CIDCardReaderDemoDlg::OnBnClickedBtnIcsnr)
	ON_BN_CLICKED(IDC_BTN_IDSNR, &CIDCardReaderDemoDlg::OnBnClickedBtnIdsnr)
	ON_BN_CLICKED(IDC_BN_GETDBCODE, &CIDCardReaderDemoDlg::OnBnClickedBnGetdbcode)
END_MESSAGE_MAP()


// CIDCardReaderDemoDlg 消息处理程序

BOOL CIDCardReaderDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	SetDlgItemText(IDC_EDIT_DATA, _T("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"));	//1 block have 16 bytes space.
	SetDlgItemText(IDC_EDIT_KEY, _T("FFFFFFFFFFFF")); //6 bytes key as hexstring
	CString strTemp;
	for (int i=1;i<=64;i++)
	{
		strTemp.Format(_T("COM%d"), i);
		m_comboComport.AddString(strTemp);
	}
	for (int i=1;i<16;i++)
	{
		strTemp.Format(_T("%d"), i);
		m_combSector.AddString(strTemp);
	}
	for (int i=0;i<3;i++)
	{
		strTemp.Format(_T("%d"), i);
		m_comboBlock.AddString(strTemp);
	}

	((CButton*)GetDlgItem(IDC_BTN_DISCONNSAM))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BTN_READIDR))->EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIDCardReaderDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CIDCardReaderDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CIDCardReaderDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CIDCardReaderDemoDlg::OnBnClickedBtnConsam()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPort = 0;
	nPort = InitCommExt();
	if (nPort > 0)
	{
		char szSamid[64] = {0x0};
		GetSAMID(szSamid);
		CStringA strMsg;
		strMsg.Format("连接身份证阅读器成功,SAM模块编号:%s", szSamid);
		//MessageBoxA(strMsg);
		((CButton*)GetDlgItem(IDC_BTN_CONSAM))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_BTN_DISCONNSAM))->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BTN_READIDR))->EnableWindow(TRUE);
		return;
	}
	else
	{
		MessageBox(_T("请确认设备是否连接正确"));
		return;
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBtnDisconnsam()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton*)GetDlgItem(IDC_BTN_CONSAM))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BTN_DISCONNSAM))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BTN_READIDR))->EnableWindow(FALSE);
	CloseComm();
}

void CIDCardReaderDemoDlg::OnBnClickedBtnReadidr()
{
	// TODO: 在此添加控件通知处理程序代码
	//Clear content
	CStringA strTemp1;
	CStringA strTemp2;
	char szTemp[128] = {0x0};
	m_bmpPhoto.SetBitmap(NULL);
	SetDlgItemTextA(IDC_EDIT_NAME, szTemp);
	SetDlgItemTextA(IDC_EDIT_SEX, szTemp);
	SetDlgItemTextA(IDC_EDIT_NATION, szTemp);
	SetDlgItemTextA(IDC_EDIT_BORN, szTemp);
	SetDlgItemTextA(IDC_EDIT_ADDR, szTemp);
	SetDlgItemTextA(IDC_EDIT_ID, szTemp);
	SetDlgItemTextA(IDC_EDIT_ISSUEAT, szTemp);
	SetDlgItemTextA(IDC_EDIT_VALIDDATE, szTemp);
	SetDlgItemTextA(IDC_EDIT_PASSNUM, szTemp);
	SetDlgItemTextA(IDC_EDIT_VISATIMES, szTemp);
	SetDlgItemTextA(IDC_EDIT_CARD_TYPE, szTemp);
	Authenticate();	//不判断返回值，可以重复读卡
	int ret = Read_Content(1);
	if(1 != ret && 2 != ret && 3 != ret)
	{
		MessageBox(_T("读卡失败，请重新放卡"));
		return;
	}
	BOOL bPhoto = FALSE;
	bPhoto = (1 == GetBmpPhotoExt());
	
	if (1 == ret || 3 == ret)
	{
		memset(szTemp, 0x0, 128);
		getName(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_NAME, szTemp);
		memset(szTemp, 0x0, 128);
		getSex(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_SEX, szTemp);
		memset(szTemp, 0x0, 128);
		getBirthdate(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_BORN, szTemp);
		memset(szTemp, 0x0, 128);
		getAddress(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_ADDR, szTemp);
		memset(szTemp, 0x0, 128);
		getIDNum(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_ID, szTemp);
		memset(szTemp, 0x0, 128);
		getIssue(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_ISSUEAT, szTemp);
		memset(szTemp, 0x0, 128);
		getEffectedDate(szTemp, 128);
		strTemp1.Format(_T("%s-"), szTemp);
		memset(szTemp, 0x0, 128);
		getExpiredDate(szTemp, 128);
		strTemp2.Format(_T("%s%s"), strTemp1, szTemp);
		SetDlgItemTextA(IDC_EDIT_VALIDDATE, strTemp2);
		if (1 == ret)
		{
			memset(szTemp, 0x0, 128);
			getNation(szTemp, 128);
			SetDlgItemTextA(IDC_EDIT_NATION, szTemp);
			SetDlgItemTextA(IDC_EDIT_CARD_TYPE, "居民身份证");
		}
		else
		{
			memset(szTemp, 0x0, 128);
			getPassNum(szTemp, 128);
			SetDlgItemTextA(IDC_EDIT_PASSNUM, szTemp);

			strTemp1.Format("%d", getVisaTimes());
			SetDlgItemTextA(IDC_EDIT_VISATIMES, strTemp1);
			SetDlgItemTextA(IDC_EDIT_CARD_TYPE, "港澳台居住证");
		}
	}
	else
	{
		memset(szTemp, 0x0, 128);
		//中文名/英文名组合
		getName(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_NAME, szTemp);
		//getCnName/getEnName	新接口增加单独取中英文名
		memset(szTemp, 0x0, 128);
		getSex(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_SEX, szTemp);
		memset(szTemp, 0x0, 128);
		getNation(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_NATION, szTemp);
		memset(szTemp, 0x0, 128);
		getBirthdate(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_BORN, szTemp);
		SetDlgItemTextA(IDC_EDIT_ADDR, "");
		memset(szTemp, 0x0, 128);
		getIDNum(szTemp, 128);
		SetDlgItemTextA(IDC_EDIT_ID, szTemp);
		SetDlgItemTextA(IDC_EDIT_ISSUEAT, "公安部");
		memset(szTemp, 0x0, 128);
		getEffectedDate(szTemp, 128);
		strTemp1.Format(_T("%s-"), szTemp);
		memset(szTemp, 0x0, 128);
		getExpiredDate(szTemp, 128);
		strTemp2.Format(_T("%s%s"), strTemp1, szTemp);
		SetDlgItemTextA(IDC_EDIT_VALIDDATE, strTemp2);
		SetDlgItemTextA(IDC_EDIT_CARD_TYPE, "外国人永居证");
		SetDlgItemTextA(IDC_EDIT_PASSNUM, "");
		SetDlgItemTextA(IDC_EDIT_VISATIMES, "");
	}
	
	if (bPhoto)
	{
		HBITMAP hbitmap=(HBITMAP)::LoadImage(::AfxGetInstanceHandle(), g_app_path + _T("zp.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if (NULL != hbitmap)
		{
			m_bmpPhoto.SetBitmap(hbitmap);
		}
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBtnIcread()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strKeyA = "";
	GetDlgItemTextA(IDC_EDIT_KEY, strKeyA);
	if (m_comboBlock.GetCurSel() == -1 || m_combSector.GetCurSel() == -1 || m_comboComport.GetCurSel() == -1 ||
		strKeyA.IsEmpty() || strKeyA.GetLength() != 12)
	{
		MessageBox(_T("输入不合法"));
		return;
	}
	char szData[128] = {0x0};
	unsigned int snr = 0;
	int ret = IC_ReadData(m_comboComport.GetCurSel()+1, 0, m_combSector.GetCurSel()+1, m_comboBlock.GetCurSel(), strKeyA.GetBuffer(), szData, 128, &snr);
	if (1 == ret)
	{
		SetDlgItemTextA(IDC_EDIT_RES, szData);
	}
	else
	{
		MessageBox(_T("读卡失败"));
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBtnIcwrite()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strKeyA = "";
	CString strDataA = "";
	GetDlgItemTextA(IDC_EDIT_KEY, strKeyA);
	GetDlgItemTextA(IDC_EDIT_DATA, strDataA);
	if (m_comboBlock.GetCurSel() == -1 || m_combSector.GetCurSel() == -1 || m_comboComport.GetCurSel() == -1 ||
		strKeyA.IsEmpty() || strKeyA.GetLength() != 12 || strDataA.IsEmpty() || strDataA.GetLength() != 32)
	{
		MessageBox(_T("输入不合法"));
		return;
	}
	unsigned int snr = 0;
	int ret = IC_WriteData(m_comboComport.GetCurSel()+1, 0, m_combSector.GetCurSel()+1, m_comboBlock.GetCurSel(), strKeyA.GetBuffer(), strDataA.GetBuffer(), strDataA.GetLength(), &snr);
	if (1 == ret)
	{
		MessageBox(_T("写卡成功"));
	}
	else
	{
		MessageBox(_T("写卡失败"));
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBtnIcsnr()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_comboComport.GetCurSel() == -1 )
	{
		MessageBox(_T("输入不合法"));
		return;
	}
	int ret = 0;
	unsigned int snr = 0;
	ret = IC_GetICSnr(m_comboComport.GetCurSel()+1, &snr);
	if (ret == 1)
	{
		CString strMsg;
		strMsg.Format(_T("IC卡物理卡号：%d"), snr);
		SetDlgItemText(IDC_EDIT_RES, strMsg);
	}
	else
	{
		MessageBox(_T("读IC卡物理卡号失败"));
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBtnIdsnr()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_comboComport.GetCurSel() == -1 )
	{
		MessageBox(_T("输入不合法"));
		return;
	}
	char szBuf[128] = {0x0};
	int ret = IC_GetIDSnr(m_comboComport.GetCurSel()+1, szBuf, 128);
	if (ret == 1)
	{
		CString strMsg;
		strMsg.Format(_T("身份证物理卡号：%s"), szBuf);
		SetDlgItemText(IDC_EDIT_RES, strMsg);
	}
	else
	{
		MessageBox(_T("读身份证物理卡号失败"));
	}
}

void CIDCardReaderDemoDlg::OnBnClickedBnGetdbcode()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_comboComport.GetCurSel() == -1 )
	{
		MessageBox(_T("输入不合法"));
		return;
	}
	char szBuf[128] = {0x0};
	int ret = IC_GetIDDNCode(m_comboComport.GetCurSel()+1, szBuf, 128);
	if (ret == 1)
	{
		CString strMsg;
		strMsg.Format(_T("身份证物理卡号：%s"), szBuf);
		SetDlgItemText(IDC_EDIT_RES, strMsg);
	}
	else
	{
		MessageBox(_T("读身份证DN码失败"));
	}
}
