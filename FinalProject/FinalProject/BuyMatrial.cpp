// BuyMatrial.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "BuyMatrial.h"
#include "afxdialogex.h"

/********************************************************
* 파일명 : BuyMatrial.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 구매등록을 하는 창
*******************************************************/

// BuyMatrial 대화 상자

IMPLEMENT_DYNAMIC(BuyMatrial, CDialog)

/*****************************************************
* Interface : BuyMatrial::BuyMatrial(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

BuyMatrial::BuyMatrial(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_MAT, pParent)
	, m_Buy_Name(_T(""))
	, m_Buy_Cost(0)
	, m_Buy_Count(0)
{

}

/*****************************************************
* Interface : BuyMatrial::~BuyMatrial()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

BuyMatrial::~BuyMatrial()
{
}

/*****************************************************
* Interface : void BuyMatrial::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 해당 컨트롤에 대한 변수 설정
*****************************************************/

void BuyMatrial::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BUY_NAME, m_Buy_Name);
	DDX_Text(pDX, IDC_EDIT_BUY_COST, m_Buy_Cost);
	DDX_Text(pDX, IDC_EDIT_BUY_COUNT, m_Buy_Count);
}


BEGIN_MESSAGE_MAP(BuyMatrial, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_REG_BUY, &BuyMatrial::OnClickedButtonRegBuy)
END_MESSAGE_MAP()


// BuyMatrial 메시지 처리기


/*****************************************************
* Interface : void BuyMatrial::OnClickedButtonRegBuy()
* Parameter : 
* 기능 : 구매 물품 비용처리
*****************************************************/

void BuyMatrial::OnClickedButtonRegBuy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Trade trader;
	UpdateData(TRUE);

	if (!trader.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	trader.AddNew();
	trader.m_Title = m_Buy_Name;
	trader.m_Type = "비용";
	trader.m_Cost = m_Buy_Count * m_Buy_Cost;	//구매 물품 비용처리

	trader.Update();
	trader.Requery();
	AfxMessageBox("비용 처리 완료");

	trader.Close();

	UpdateData(FALSE);
}
