// CRent.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "CRent.h"
#include "afxdialogex.h"

/********************************************************
* 파일명 : CRent.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 대여기능이 구현되어 있는 창
*******************************************************/

// CRent 대화 상자

IMPLEMENT_DYNAMIC(CRent, CDialog)
CLogin login;

/*****************************************************
* Interface : CRent::CRent(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

CRent::CRent(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Rent, pParent)
{
	
}

/*****************************************************
* Interface : CRent::~CRent()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

CRent::~CRent()
{
}

/*****************************************************
* Interface : void CRent::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러를 설정하는 함수
*****************************************************/

void CRent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_RENDABLE, m_ListLendable);
	DDX_Control(pDX, IDC_LIST_RENT, m_ListRent);
}


BEGIN_MESSAGE_MAP(CRent, CDialog)
	ON_COMMAND(IDD_DIALOG_Rent, &CRent::OnIddDialogRent)
	ON_BN_CLICKED(IDC_BUTTON_REND, &CRent::OnClickedButtonRend)
	ON_BN_CLICKED(IDC_BUTTON_RE, &CRent::OnClickedButtonRe)
END_MESSAGE_MAP()


// CRent 메시지 처리기

void CRent::OnIddDialogRent()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
}

/*****************************************************
* Interface : BOOL CRent::OnInitDialog()
* Parameter : 
* 기능 : 빌릴 수 있는 비디오와 이미 빌린 비디오를 불러오는 함수(초기화)
*****************************************************/

BOOL CRent::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//현재 빌릴 수 있는 비디오
	Video video;
	VideoList videolist;

	if(!video.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	if (!videolist.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	while (!video.IsEOF())
	{
		if (video.m_V_Status == TRUE)
		{
			while (!videolist.IsEOF())
			{
				if (video.m_V_ListCode == videolist.m_V_ListCode)	//비슷한 코드 발견
				{
					m_ListLendable.AddString(videolist.m_V_Title);	//제목 입력
				}
				videolist.MoveNext();
			}
		}
		video.MoveNext();
	}

	//현재 빌리고 있는 비디오
	while (!video.IsEOF())
	{
		if (video.m_V_User == login.m_Login_ID)
		{
			while (!videolist.IsEOF())
			{
				if (video.m_V_ListCode == videolist.m_V_ListCode)	//비슷한 코드 발견
				{
					m_ListLendable.AddString(videolist.m_V_Title);	//제목 입력
				}
				videolist.MoveNext();
			}
		}
		video.MoveNext();
	}

	videolist.Close();
	video.Close();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

/*****************************************************
* Interface : void CRent::OnClickedButtonRend()
* Parameter :
* 기능 : 대여기능을 담당하는 함수
*****************************************************/

void CRent::OnClickedButtonRend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int Index = m_ListLendable.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_ListLendable.GetText(Index, str);
		m_ListLendable.SetCurSel(Index);
		m_ListRent.AddString(str);

		Video video;
		VideoList videolist;

		if (!video.Open())
		{
			AfxMessageBox(_T("데이터베이스 연결 오류"));
		}

		if (!videolist.Open())
		{
			AfxMessageBox(_T("데이터베이스 연결 오류"));
		}

		while (!videolist.IsEOF())
		{
			if (videolist.m_V_Title==str)
			{
				while (!video.IsEOF())
				{
					if (video.m_V_ListCode == videolist.m_V_ListCode)	//비슷한 코드 발견
					{
						video.m_V_Status = FALSE;	//빌린 처리하기
					}
					video.MoveNext();
				}
			}
			videolist.MoveNext();
		}

		videolist.Close();
		video.Close();

		Trade trader;	//수익 입력

		if (!trader.Open())
		{
			AfxMessageBox(_T("데이터베이스 연결오류"));
		}

		trader.AddNew();
		trader.m_Type = "수익";
		trader.m_Title = "대여료";
		trader.m_Cost = 1000;

		trader.Update();
		trader.Requery();
		trader.Close();
	}
}

/*****************************************************
* Interface : void CRent::OnClickedButtonRe()
* Parameter :
* 기능 : 반납기능을 담당하는 함수
*****************************************************/

void CRent::OnClickedButtonRe()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int Index = m_ListRent.GetCurSel();

	if (Index != LB_ERR)
	{
		CString str;
		m_ListRent.GetText(Index, str);
		m_ListRent.SetCurSel(Index);
		m_ListLendable.AddString(str);

		Video video;
		VideoList videolist;

		if (!video.Open())
		{
			AfxMessageBox(_T("데이터베이스 연결 오류"));
		}

		if (!videolist.Open())
		{
			AfxMessageBox(_T("데이터베이스 연결 오류"));
		}

		while (!videolist.IsEOF())
		{
			if (videolist.m_V_Title == str)
			{
				while (!video.IsEOF())
				{
					if (video.m_V_ListCode == videolist.m_V_ListCode)	//비슷한 코드 발견
					{
						video.m_V_Status = TRUE;	//반납 처리하기
					}
					video.MoveNext();
				}
			}
			videolist.MoveNext();
		}

		videolist.Close();
		video.Close();
	}
}
