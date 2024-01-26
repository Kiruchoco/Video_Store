// CBuy.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "CBuy.h"
#include "afxdialogex.h"
#include "BuyMatrial.h"
#include "VideoBuy.h"

/********************************************************
* 파일명 : CBuy.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 비디오와 물품구매 등록을 하는 창
*******************************************************/

BuyMatrial mat;
VideoBuy buyVideo;

// CBuy 대화 상자

IMPLEMENT_DYNAMIC(CBuy, CDialog)

/*****************************************************
* Interface :CBuy::CBuy(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

CBuy::CBuy(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Buy, pParent)
{

}

/*****************************************************
* Interface : CBuy::~CBuy()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

CBuy::~CBuy()
{

}

/*****************************************************
* Interface : void CBuy::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 리스트 컨트롤러 설정
*****************************************************/

void CBuy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Buy, m_ListBuy);
}


BEGIN_MESSAGE_MAP(CBuy, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_BUY, &CBuy::OnClickedButtonBuy)
	ON_BN_CLICKED(IDC_BUTTON_VIDEO, &CBuy::OnClickedButtonVideo)
END_MESSAGE_MAP()


// CBuy 메시지 처리기


void CBuy::PreInitDialog()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialog::PreInitDialog();
}

/*****************************************************
* Interface : BOOL CBuy::OnInitDialog()
* Parameter : 
* 기능 : 물품구매창 초기화
*****************************************************/

BOOL CBuy::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_ListBuy.InsertColumn(0, _T("순번"), LVCFMT_LEFT, 80);
	m_ListBuy.InsertColumn(1, _T("구매물품"), LVCFMT_LEFT, 80);
	m_ListBuy.InsertColumn(2, _T("가격"), LVCFMT_LEFT, 80);

	Trade trader;
	int i = 0;

	if (!trader.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	while (!trader.IsEOF())
	{
		CString temp;
		temp.Format(_T("%ld"), trader.m_No);
		m_ListBuy.InsertItem(i,temp);	//순번
		
		CString exer = (CString)trader.m_Title;
		m_ListBuy.SetItemText(i, 1, exer);	//구매물품
		exer.Format(_T("%ld"), trader.m_Cost);
		m_ListBuy.SetItemText(i, 2, exer);	//가격

		trader.MoveNext();
		i++;
	}

	trader.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

/*****************************************************
* Interface : void CBuy::OnClickedButtonBuy()
* Parameter :
* 기능 : 구매등록 창 불러오기
*****************************************************/

void CBuy::OnClickedButtonBuy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mat.DoModal();	//구매등록 창 불러오기
}

/*****************************************************
* Interface : void CBuy::OnClickedButtonVideo()
* Parameter :
* 기능 : 비디오 구매 등록 창 불러오기
*****************************************************/

void CBuy::OnClickedButtonVideo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	buyVideo.DoModal();	//비디오 구매 등록 창 불러오기
}
