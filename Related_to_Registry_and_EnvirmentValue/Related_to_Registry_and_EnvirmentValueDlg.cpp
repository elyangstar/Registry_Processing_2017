
// Related_to_Registry_and_EnvirmentValueDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Related_to_Registry_and_EnvirmentValue.h"
#include "Related_to_Registry_and_EnvirmentValueDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRelatedtoRegistryandEnvirmentValueDlg 대화 상자



CRelatedtoRegistryandEnvirmentValueDlg::CRelatedtoRegistryandEnvirmentValueDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RELATED_TO_REGISTRY_AND_ENVIRMENTVALUE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_strRegistryPath	= "SOFTWARE\\TEST_YEY";
	m_strItemName		= "VALUENAME";
	m_strItemValue		= "C:\\YEY";
	m_strRegistryRead	= "";
	m_strRegistryName2	= "";
	m_strRegiModifyPath = "";

	m_strEnvirName		= "VIEW_PATH";
	m_strEnvirValue		= "";
	m_strModifyEnvirValue = "";
	m_strRefreshData	= "";

	m_strEclipseID		= "t4300691";
	m_strEclipsePW		= "diddmsdyd123";
}

void CRelatedtoRegistryandEnvirmentValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_REGISTRY_PATH, m_strRegistryPath);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM, m_strItemName);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM2, m_strItemValue);
	DDX_Text(pDX, IDC_REGISTRY_READ_DATA, m_strRegistryRead);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM3, m_strRegistryName2);
	DDX_Text(pDX, IDC_REGISTRY_CREATE_ITEM4, m_strRegiModifyPath);
	DDX_Text(pDX, IDC_ENVIRONMENT_NAME, m_strEnvirName);
	DDX_Text(pDX, IDC_ENVIRONMENT_VALUE, m_strEnvirValue);
	DDX_Text(pDX, IDC_ENVIRONMENT_VALUE_MOD, m_strModifyEnvirValue);
	DDX_Text(pDX, IDC_ENVIRONMENT_REFRESH_DATA, m_strRefreshData);
	DDX_Text(pDX, IDC_ECLIPSE_ID, m_strEclipseID);
	DDX_Text(pDX, IDC_ECLIPSE_PW, m_strEclipsePW);
}

BEGIN_MESSAGE_MAP(CRelatedtoRegistryandEnvirmentValueDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATE_FOLDER, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonCreateFolder)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_NEW_CREATE, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonNewCreate)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY_PATH, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonModifyPath)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_PATH, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonDeletePath)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE2, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue2)
	ON_BN_CLICKED(IDC_BUTTON_READ_ENVIRVALUE3, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue3)
	ON_BN_CLICKED(IDC_BUTTON1, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CRelatedtoRegistryandEnvirmentValueDlg 메시지 처리기

BOOL CRelatedtoRegistryandEnvirmentValueDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRelatedtoRegistryandEnvirmentValueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRelatedtoRegistryandEnvirmentValueDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRelatedtoRegistryandEnvirmentValueDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonOpen()
{
	//Registry Key 값 받아 오기******************************************************************************************************************************************
	UpdateData(TRUE);
	
	LSTATUS lstRes = ERROR_SUCCESS;
	lstRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, m_strRegistryPath, 0, KEY_ALL_ACCESS, &m_hRegKey);

	if (ERROR_SUCCESS != lstRes)
		AfxMessageBox("access Impossible and Path incorrect");
}

void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonCreateFolder()
{
	//Registry 경로 생성******************************************************************************************************************************************
	UpdateData(TRUE);
	DWORD dwDisp = 0;
	LSTATUS lstRes = ::RegCreateKeyEx(HKEY_LOCAL_MACHINE, m_strRegistryPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &m_hRegKey, &dwDisp);
	if (ERROR_SUCCESS == lstRes)
	{
		AfxMessageBox(_T("Create"));
	}
	else
	{
		AfxMessageBox(_T("Create Fail"));
	}
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonNewCreate()
{
	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];

	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strItemValue.GetLength() + 1, m_strItemValue.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strItemName, 0, REG_SZ, (LPBYTE)atcvalue, m_strItemName.GetLength() + 1);
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonRead()
{
	//Registry 읽기******************************************************************************************************************************************
	LSTATUS lstRes  = ERROR_SUCCESS;
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	lstRes = ::RegQueryValueEx(m_hRegKey, m_strItemName, NULL, NULL, NULL, &dwBufSiz);

	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strItemName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strItemValue.Format(_T("%s"), atcvalue);

		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	m_strRegistryRead = m_strItemValue;
	m_strRegistryName2 = m_strItemName;
	UpdateData(FALSE);
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonModifyPath()
{
	//Registry 수정******************************************************************************************************************************************
	UpdateData(TRUE);
	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strRegiModifyPath.GetLength() + 1, m_strRegiModifyPath.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strItemName, 0, REG_SZ, (LPBYTE)atcvalue, m_strRegiModifyPath.GetLength() + 1);

	UpdateData(FALSE);
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonDeletePath()
{
	//Registry Delete******************************************************************************************************************************************
	LSTATUS lstRes;
	
	if (NULL != m_hRegKey)
	{
		lstRes = ::RegDeleteValue(m_hRegKey, m_strItemName);
	}
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonClose()
{
	//Registry Close******************************************************************************************************************************************
	LSTATUS lstRes = ERROR_SUCCESS;
	if (NULL != m_hRegKey)
	{
		lstRes = ::RegCloseKey(m_hRegKey);
		m_hRegKey = NULL;
	}
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue()
{
	UpdateData(TRUE);
	CString strEnvironmentPath = "System\\CurrentControlSet\\Control\\Session Manager\\Environment";

	LSTATUS lstRes = ERROR_SUCCESS;
	lstRes = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strEnvironmentPath, 0, KEY_ALL_ACCESS, &m_hRegKey);
	if (ERROR_SUCCESS != lstRes)
	{
		AfxMessageBox(_T("open Fail"));
	}

	//Registry 읽기******************************************************************************************************************************************
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, NULL, &dwBufSiz);
	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strEnvirValue.Format(_T("%s"), atcvalue);
		
		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	UpdateData(FALSE);
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue2()
{
	UpdateData(TRUE);

	LSTATUS lstRes = ERROR_SUCCESS;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	_tcscpy_s(atcvalue, m_strModifyEnvirValue.GetLength() + 1, m_strModifyEnvirValue.GetBuffer());
	lstRes = ::RegSetValueEx(m_hRegKey, m_strEnvirName, 0, REG_SZ, (LPBYTE)atcvalue, m_strModifyEnvirValue.GetLength() + 1);

	UpdateData(FALSE);
}



void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButtonReadEnvirvalue3()
{

	//Registry 읽기******************************************************************************************************************************************
	DWORD dwBufSiz = 0;
	TCHAR atcvalue[MAX_PATH];
	ZeroMemory(atcvalue, sizeof(atcvalue));
	LSTATUS lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, NULL, &dwBufSiz);
	if (ERROR_SUCCESS == lstRes)
	{
		TCHAR atcvalue[MAX_PATH];
		ZeroMemory(atcvalue, sizeof(atcvalue));
		lstRes = ::RegQueryValueEx(m_hRegKey, m_strEnvirName, NULL, NULL, (LPBYTE)atcvalue, &dwBufSiz);
		m_strRefreshData.Format(_T("%s"), atcvalue);

		if (ERROR_SUCCESS != lstRes)
			AfxMessageBox("Read Fail");
	}

	UpdateData(FALSE);
}

void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton1()
{
	ShellExecute(NULL, "open", "..\\BatFile\\1.PathCheck.Bat", NULL, NULL, SW_SHOW);
}

void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton2()
{
	FILE* pf = NULL;
	CString strPath = "./Config/bat.bat";

	pf = fopen(strPath, "w");

	if (pf)
	{
		fprintf(pf, "@ECHO ON\n");
		fprintf(pf, "set | find \"VIEW_PATH\"\n");
		fprintf(pf, "set | find \"AXCELIS\"\n");
		fprintf(pf, "PAUSE");	//test 완료후 삭제할것.
		fclose(pf);

		system("bat.bat"); //bat파일 실행
		system("del bat.bat"); //bat파일 삭제
	}
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);

	FILE* pf = NULL;
	CString strData = "";
	CString strPath = ".\\Config\\Cdandscm.bat";
	strData.Format("scm login -r https://ma960app.axcelis.com:9443/ccm/ -n repo -c -u %s -P %s\n", m_strEclipseID,m_strEclipsePW);

	pf = fopen(strPath, "w");

	if (pf)
	{
		fprintf(pf, "@ECHO ON\n");
		fprintf(pf, "cd C:\\Program Files\\IBM\\TeamConcert\\scmtools\\eclipse\n");
		fprintf(pf, strData);
		fprintf(pf, "PAUSE");	//test 완료후 삭제할것.
		fclose(pf);

		ShellExecute(NULL, "open", strPath, NULL, NULL, SW_SHOW);

	}
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	CString strData = "";
	strData = m_strEnvirValue + "\\Oracle\\RTC_Script\\RTCFile.txt";
	ShellExecute(NULL, "open", strData, NULL, NULL, SW_SHOW);
}


void CRelatedtoRegistryandEnvirmentValueDlg::OnBnClickedButton5()
{
	CString strPath = ".\\config\\RTCFile2.txt";
	CString strData = "";
	
	strData = m_strEnvirValue + "\\Oracle\\RTC_Script\\RTCFile.txt";
	
	FILE* pf = fopen(strPath, "w");
	//아래의 항목들은 옵션 처리해서 설정 하도록 하자.
	if (pf)
	{
		fprintf(pf, "Usage : User should use only one workspace, Product Name and source stream entry (Don't add more than one worksapce or source stream name)\n");
		fprintf(pf, "Usage : Enter loadrules file name with full share path\n");
		fprintf(pf, "Usage : Product, Stream and loadrule should match as single product \n");
		fprintf(pf, "\n");

		fprintf(pf, "::Below type Exact WorkSpace name and one WorkSpace at a time\n");
		fprintf(pf, "YEY_CSSSSSS\n");
		fprintf(pf, "\n");

		fprintf(pf, "::Product Name (XE_FLR or H_FLR or M_FLR)\n");
		fprintf(pf, "H_FLR\n");
		fprintf(pf, "\n");

		fprintf(pf, "::Product's integration Stream Name.\n");
		fprintf(pf, "PurionH_V4.1_Korea\n");
		fprintf(pf, "\n");

		fprintf(pf, "::loadrules\n");
		fprintf(pf, "\\\\prodsoftware.axcelis.com\\SoftwareDev\\RTC\\Load_Rules\\SubSystems\\CSS\\Non_Common_H_FLR.loadrule");

		fclose(pf);
	}
	CopyFile(strPath, strData, FALSE);
}
