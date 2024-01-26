// NewClerk.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "NewClerk.h"
#include "afxdialogex.h"

/********************************************************
* 파일명 : NewClerk.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 신규 직원을 등록하는 창을 구현
*******************************************************/

// NewClerk 대화 상자

IMPLEMENT_DYNAMIC(NewClerk, CDialogEx)

/*****************************************************
* Interface : NewClerk::NewClerk(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

NewClerk::NewClerk(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NewClerk, pParent)
	, m_Reg_ID(_T(""))
	, m_Reg_PW(_T(""))
	, m_Reg_Name(_T(""))
	, m_Reg_Tel(_T(""))
	, m_Reg_Address(_T(""))
{

}

/*****************************************************
* Interface : NewClerk::~NewClerk()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

NewClerk::~NewClerk()
{
}

/*****************************************************
* Interface : void NewClerk::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러를 설정하는 함수
*****************************************************/

void NewClerk::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_Reg_ID);
	DDX_Text(pDX, IDC_EDIT_PW, m_Reg_PW);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Reg_Name);
	DDX_Text(pDX, IDC_EDIT_TEL, m_Reg_Tel);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Reg_Address);
}


BEGIN_MESSAGE_MAP(NewClerk, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Reg, &NewClerk::OnBnClickedButtonReg)
END_MESSAGE_MAP()


// NewClerk 메시지 처리기

/*****************************************************
* Interface : void NewClerk::OnBnClickedButtonReg()
* Parameter : 
* 기능 : 신규직원을 등록하는 함수
*****************************************************/

void NewClerk::OnBnClickedButtonReg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Clerk clk;

	UpdateData(TRUE);

	if (!clk.Open())
	{
		AfxMessageBox(_T("데이터베이스 연결 오류"));
	}

	clk.AddNew();	//신규 직원 등록
	clk.m_Cl_ID = m_Reg_ID;
	clk.m_Cl_PW = m_Reg_PW;
	clk.m_Cl_Name = m_Reg_Name;
	clk.m_Cl_Tel = m_Reg_Tel;
	clk.m_Cl_Address = m_Reg_Address;
	clk.m_Cl_hour = 0;

	clk.Update();
	clk.Requery();

	UpdateData(FALSE);

	clk.Close();

	AfxMessageBox(_T("신규 직원 정보 입력 완료"));
}
