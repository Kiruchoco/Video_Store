// CFinance.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "CFinance.h"
#include "afxdialogex.h"

/********************************************************
* 파일명 : CFinance.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 재무관리를 하는 창
*******************************************************/

// CFinance 대화 상자

IMPLEMENT_DYNAMIC(CFinance, CDialog)

/*****************************************************
* Interface : CFinance::CFinance(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

CFinance::CFinance(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Finance, pParent)
{

	Revenue = 0;
	Cost = 0;
}

/*****************************************************
* Interface : CFinance::~CFinance()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

CFinance::~CFinance()
{
}

/*****************************************************
* Interface : void CFinance::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 리스트 컨트롤러를 설정하는 함수
*****************************************************/

void CFinance::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Finance, m_ListFinance);
}


BEGIN_MESSAGE_MAP(CFinance, CDialog)
END_MESSAGE_MAP()


// CFinance 메시지 처리기

/*****************************************************
* Interface : BOOL CFinance::OnInitDialog()
* Parameter : 
* 기능 : 재무관리 창을 초기화시키는 함수
*****************************************************/

BOOL CFinance::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_ListFinance.InsertColumn(0, _T("거래번호"), LVCFMT_LEFT, 80);
	m_ListFinance.InsertColumn(1, _T("유형"), LVCFMT_LEFT, 80);
	m_ListFinance.InsertColumn(2, _T("거래내역"), LVCFMT_LEFT, 80);
	m_ListFinance.InsertColumn(3, _T("금액"), LVCFMT_LEFT, 80);

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
		m_ListFinance.InsertItem(i, temp);	//거래번호

		CString exer = (CString)trader.m_Type;
		m_ListFinance.SetItemText(i, 1, exer);	//유형

		if (exer.Compare("비용"))
		{
			Cost += trader.m_Cost;	//총비용 계산
		}
		else if (exer.Compare("수익"))
		{
			Revenue += trader.m_Cost;	//총수익 계산
		}

		exer = (CString)trader.m_Title;
		m_ListFinance.SetItemText(i, 2, exer);	//거래내역

		exer.Format(_T("%ld"), trader.m_Cost);
		m_ListFinance.SetItemText(i, 3, exer);	//금액

		trader.MoveNext();
		i++;
	}

	trader.Close();

	UpdateData(TRUE);

	SetDlgItemInt(IDC_EDIT_TOTCOST, Revenue);//총비용
	SetDlgItemInt(IDC_EDIT_TOTREV, Cost);	//총수익
	SetDlgItemInt(IDC_EDIT_REV, -(Revenue - Cost));	//순수익

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
