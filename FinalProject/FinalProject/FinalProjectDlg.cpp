
// FinalProjectDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "FinalProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/********************************************************
* 파일명 : FinalProjectDlg.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 프로젝트 기본 대화상자를 표현하는 부분
		 탭 컨트롤러가 구현되어 있음.
*******************************************************/

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

/*****************************************************
* Interface : CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
* Parameter :
* 기능 : 생성자
*****************************************************/

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

/*****************************************************
* Interface : void CAboutDlg::DoDataExchange(CDataExchange* pDX)
* Parameter :
* 기능 : 컨트롤러를 설정하는 함수
*****************************************************/

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalProjectDlg 대화 상자

/*****************************************************
* Interface : CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 아이콘 설정 함수
*****************************************************/

CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/*****************************************************
* Interface : void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러를 설정하는 함수(탭 컨트롤러)
*****************************************************/

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_Tab);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CFinalProjectDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// CFinalProjectDlg 메시지 처리기

/*****************************************************
* Interface : BOOL CFinalProjectDlg::OnInitDialog()
* Parameter : 
* 기능 : 메인 화면을 초기화하는 함수
*****************************************************/

BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	// 탭 컨트롤러 구현
	CString strTab = _T("");
	strTab.Format(_T("로그인"));
	this->m_Tab.InsertItem(0, strTab, 0);
	strTab.Format(_T("대여반납"));
	this->m_Tab.InsertItem(1, strTab, 0);
	strTab.Format(_T("직원관리"));
	this->m_Tab.InsertItem(2, strTab, 0);
	strTab.Format(_T("물품구매"));
	this->m_Tab.InsertItem(3, strTab, 0);
	strTab.Format(_T("재정관리"));
	this->m_Tab.InsertItem(4, strTab, 0);

	// 한 탭을 선택하면 그 탭만 표현하도록 구현
	CRect rect;
	this->m_Tab.GetClientRect(&rect);
	this->m_tab1.Create(IDD_DIALOG_Login, &this->m_Tab);
	this->m_tab1.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);

	this->m_tab2.Create(IDD_DIALOG_Rent, &this->m_Tab);
	this->m_tab2.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	this->m_tab3.Create(IDD_DIALOG_Clerk, &this->m_Tab);
	this->m_tab3.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	this->m_tab4.Create(IDD_DIALOG_Buy, &this->m_Tab);
	this->m_tab4.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	this->m_tab5.Create(IDD_DIALOG_Finance, &this->m_Tab);
	this->m_tab5.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

	this->m_pwndShow = &this->m_tab1;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

/*****************************************************
* Interface : void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
* Parameter : UINT nID, LPARAM lParam
* 기능 : 시스템 도움말 확인 함수
*****************************************************/

void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

/*****************************************************
* Interface : void CFinalProjectDlg::OnPaint()
* Parameter : 
* 기능 : 창을 생성하는 함수
*****************************************************/

void CFinalProjectDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.

/*****************************************************
* Interface : HCURSOR CFinalProjectDlg::OnQueryDragIcon()
* Parameter :
* 기능 : 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서 이 함수를 호출합니다.
*****************************************************/

HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*****************************************************
* Interface : void CFinalProjectDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
* Parameter : NMHDR *pNMHDR, LRESULT *pResult
* 기능 : 탭 컨트롤러를 운영하는 함수
*****************************************************/

void CFinalProjectDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (this->m_pwndShow != NULL)
	{
		this->m_pwndShow->ShowWindow(SW_HIDE);
		this->m_pwndShow = NULL;
	}

	int tabIndex = this->m_Tab.GetCurSel();

	// 해당 탭만 보이게 함
	switch (tabIndex)
	{
	case 0:
		this->m_tab1.ShowWindow(SW_SHOW);
		this->m_pwndShow = &this->m_tab1;
		break;
	case 1:
		this->m_tab2.ShowWindow(SW_SHOW);
		this->m_pwndShow = &this->m_tab2;
		break;
	case 2:
		this->m_tab3.ShowWindow(SW_SHOW);
		this->m_pwndShow = &this->m_tab3;
		break;
	case 3:
		this->m_tab4.ShowWindow(SW_SHOW);
		this->m_pwndShow = &this->m_tab4;
		break;
	case 4:
		this->m_tab5.ShowWindow(SW_SHOW);
		this->m_pwndShow = &this->m_tab5;
		break;
	}


	*pResult = 0;
}
