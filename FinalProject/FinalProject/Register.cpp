// Register.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "Register.h"
#include "afxdialogex.h"

/********************************************************
* 파일명 : Register.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 회원가입하는 창 구현
*******************************************************/

// Register 대화 상자

IMPLEMENT_DYNAMIC(Register, CDialog)

/*****************************************************
* Interface : Register::Register(CWnd* pParent)
* Parameter : CWnd* pParent
* 기능 : 생성자
*****************************************************/

Register::Register(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Reg, pParent)
	, m_Reg_ID(_T(""))
	, m_Reg_PW(_T(""))
	, m_Reg_Name(_T(""))
	, m_Reg_Tel(_T(""))
	, m_Reg_Address(_T(""))
{

}

/*****************************************************
* Interface : Register::~Register()
* Parameter :
* 기능 : 소멸자
*****************************************************/

Register::~Register()
{
}

/*****************************************************
* Interface : void Register::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러를 설정하는 함수
*****************************************************/

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_Reg_ID);
	DDX_Text(pDX, IDC_EDIT_PW, m_Reg_PW);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Reg_Name);
	DDX_Text(pDX, IDC_EDIT_TEL, m_Reg_Tel);
	DDX_Text(pDX, IDC_EDIT_ADD, m_Reg_Address);
}


BEGIN_MESSAGE_MAP(Register, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Register::OnClickedButton1)
END_MESSAGE_MAP()


// Register 메시지 처리기

/*****************************************************
* Interface : void Register::OnClickedButton1()
* Parameter :
* 기능 : 회원가입 기능 함수
*****************************************************/

void Register::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Customer custom;
	
	UpdateData(TRUE);

	if (!custom.Open())
	{
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}

	custom.AddNew();	//회원가입하기
	custom.m_Cu_ID = m_Reg_ID;
	custom.m_Cu_PW = m_Reg_PW;
	custom.m_Cu_Name = m_Reg_Name;
	custom.m_Cu_Address = m_Reg_Address;
	custom.m_Cu_Tel = m_Reg_Tel;
	
	custom.Update();
	custom.Requery();

	UpdateData(FALSE);

	custom.Close();
	
	AfxMessageBox(_T("회원가입 완료"));
}
