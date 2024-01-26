// VideoBuy.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "VideoBuy.h"
#include "afxdialogex.h"


// VideoBuy 대화 상자

/********************************************************
* 파일명 : VideoBuy.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 비디오 구매 창을 구현하는 부분
*******************************************************/

IMPLEMENT_DYNAMIC(VideoBuy, CDialog)

/*****************************************************
* Interface : VideoBuy::VideoBuy(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

VideoBuy::VideoBuy(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_VIDEO_BUY, pParent)
	, m_VideoTitle(_T(""))
	, m_VideoGenre(_T(""))
	, m_VideoCost(0)
	, m_VideoCount(0)
{

}

/*****************************************************
* Interface : VideoBuy::~VideoBuy()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

VideoBuy::~VideoBuy()
{
}

/*****************************************************
* Interface : void VideoBuy::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러를 설정하는 함수
*****************************************************/

void VideoBuy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_VideoTitle);
	DDX_Text(pDX, IDC_EDIT_GENRE, m_VideoGenre);
	DDX_Text(pDX, IDC_EDIT_COST, m_VideoCost);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_VideoCount);
}


BEGIN_MESSAGE_MAP(VideoBuy, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Video_Buy, &VideoBuy::OnBnClickedButtonVideoBuy)
END_MESSAGE_MAP()


// VideoBuy 메시지 처리기

/*****************************************************
* Interface : void VideoBuy::OnBnClickedButtonVideoBuy()
* Parameter : 
* 기능 : 비디오 구매 기능 함수
*****************************************************/

void VideoBuy::OnBnClickedButtonVideoBuy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Trade writetrade;
	Video addVideo;
	VideoList addVideoList;
	long videonumber;

	UpdateData(TRUE);

	if (!addVideoList.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	addVideoList.AddNew();
	videonumber = addVideoList.m_V_ListCode;
	addVideoList.m_V_Title = m_VideoTitle;
	addVideoList.m_V_Genre = m_VideoGenre;
	addVideoList.m_V_Count = m_VideoCount;
	addVideoList.Update();
	addVideoList.Requery();

	addVideoList.Close();
	
	if (!addVideo.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}
	
	for (int i = 0; i < m_VideoCount; i++)
	{
		CString temp;
		temp.Format(_T("%d"), videonumber);

		addVideo.AddNew();
		addVideo.m_V_ListCode = temp;
		addVideo.m_V_Status = TRUE;
		addVideo.Update();
		addVideo.Requery();
	}

	addVideo.Close();

	if (!writetrade.Open())
	{
		AfxMessageBox(_T("데이터 베이스 연결 오류"));
	}

	writetrade.AddNew();
	writetrade.m_Type = "비용";
	writetrade.m_Title = m_VideoTitle;
	writetrade.m_Cost = m_VideoCount * m_VideoCost;

	writetrade.Update();
	writetrade.Requery();
	writetrade.Close();

	UpdateData(FALSE);
}
