// CClerk.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "CClerk.h"
#include "afxdialogex.h"
#include "NewClerk.h"

/********************************************************
* 파일명 : CClerk.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 고객 관리를 하는 창
*******************************************************/

// CClerk 대화 상자

NewClerk newclerk;

IMPLEMENT_DYNAMIC(CClerk, CDialog)

/*****************************************************
* Interface : CClerk::CClerk(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

CClerk::CClerk(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Clerk, pParent)
{

}

/*****************************************************
* Interface : CClerk::~CClerk()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

CClerk::~CClerk()
{

}

/*****************************************************
* Interface : void CClerk::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤 리스트를 설정하는 함수
*****************************************************/

void CClerk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Clerk, m_ClerkList);
}


BEGIN_MESSAGE_MAP(CClerk, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CClerk::OnClickedButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_PAY, &CClerk::OnClickedButtonPay)
END_MESSAGE_MAP()


// CClerk 메시지 처리기

/*****************************************************
* Interface : BOOL CClerk::OnInitDialog()
* Parameter : 
* 기능 : 직원 관리 창을 초기화하는 함수
*****************************************************/

BOOL CClerk::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	char *szText[4] = { "아이디","이름","연락처","근무시간" };
	int nWidth[4] = { 80,80,80,80 };

	LV_COLUMN iCol;
	iCol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	iCol.fmt = LVCFMT_LEFT;
	m_ClerkList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);	// 리스트 창 설정

	for (int i = 0; i < 4; i++)
	{
		iCol.pszText = szText[i];
		iCol.iSubItem = i;
		iCol.cx = nWidth[i];
		m_ClerkList.InsertColumn(i, &iCol);
	}

	Clerk clk;
	int i = 0;

	if (!clk.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	while (!clk.IsEOF())
	{
		CString temp = (CString)clk.m_Cl_ID;
		m_ClerkList.InsertItem(i, temp);	//아이디

		temp = (CString)clk.m_Cl_Name;
		m_ClerkList.SetItemText(i, 1, temp);	//이름

		temp = (CString)clk.m_Cl_Tel;
		m_ClerkList.SetItemText(i, 2, temp);	//연락처

		temp.Format(_T("%ld"), clk.m_Cl_hour);
		m_ClerkList.SetItemText(i, 3, temp);	//근로시간

		clk.MoveNext();
		i++;
	}

	clk.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

/*****************************************************
* Interface : void CClerk::OnClickedButtonNew()
* Parameter :
* 기능 : 새 직원을 추가하는 창을 불러옴
*****************************************************/

void CClerk::OnClickedButtonNew()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	newclerk.DoModal();
}

/*****************************************************
* Interface : void CClerk::OnClickedButtonPay()
* Parameter :
* 기능 : 직원에게 임금을 주는 기능 수행
*****************************************************/

void CClerk::OnClickedButtonPay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString temp1,temp2;

	for (int nItem = 0; nItem < m_ClerkList.GetItemCount();)
	{
		if (m_ClerkList.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
		{
			temp2 = m_ClerkList.GetItemText(nItem, 1);	//이름
			temp1 = m_ClerkList.GetItemText(nItem, 3);	//노동시간
		}
		else
		{
			nItem++;
		}
	}

	int hour = _ttoi(temp1);

	int money = hour * 10000;	//시간당 10000원으로 계산

	Trade trader;	//비용처리

	trader.AddNew();
	trader.m_Type = "비용";
	trader.m_Title = temp2;
	trader.m_Cost = money;

	trader.Update();
	trader.Requery();
	trader.Close();

	UpdateData(FALSE);
}
