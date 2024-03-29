// CLogin.cpp: 구현 파일
//

#include "stdafx.h"
#include "FinalProject.h"
#include "CLogin.h"
#include "afxdialogex.h"
#include "Register.h"
#include <atlstr.h>

/********************************************************
* 파일명 : CLogin.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 로그인 기능이 있는 창
*******************************************************/

// CLogin 대화 상자

IMPLEMENT_DYNAMIC(CLogin, CDialog)

/*****************************************************
* Interface : CLogin::CLogin(CWnd* pParent)
* Parameter : CWnd* pParent 
* 기능 : 생성자
*****************************************************/

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Login, pParent)
	, m_Login_ID(_T(""))
	, m_Login_PW(_T(""))
{

}

/*****************************************************
* Interface : CLogin::~CLogin()
* Parameter : 
* 기능 : 소멸자
*****************************************************/

CLogin::~CLogin()
{
}

/*****************************************************
* Interface : void CLogin::DoDataExchange(CDataExchange* pDX)
* Parameter : CDataExchange* pDX
* 기능 : 컨트롤러들을 설정하는 함수
*****************************************************/

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_Login_ID);
	DDX_Text(pDX, IDC_EDIT_PW, m_Login_PW);
	DDX_Control(pDX, IDC_RADIO_Client, m_rClient);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Login, &CLogin::OnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_Reg, &CLogin::OnClickedButtonReg)
END_MESSAGE_MAP()


// CLogin 메시지 처리기

/*****************************************************
* Interface : void CLogin::OnClickedButtonLogin()
* Parameter : 
* 기능 : 로그인 버튼을 클릭하였을 때 로그인 하는 기능
*****************************************************/

void CLogin::OnClickedButtonLogin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_rClient.GetCheck() == BST_CHECKED)
	{
		Customer custom;
		if (!custom.Open())
		{
			AfxMessageBox(_T("데이터 소스와 연결 못함"));
		}

		while (!custom.IsEOF())
		{
			CStringW ID(m_Login_ID);	//형변환(아이디)
			LPCWSTR pID = ID;
			CStringW PW(m_Login_PW);	//형변환(비밀번호)
			LPCWSTR pPW = PW;
			if (custom.m_Cu_ID.Compare(pID)==0)	//아이디 비교
			{
				if (custom.m_Cu_PW.Compare(pPW)==0)	//비밀번호 비교
				{
					AfxMessageBox(_T("로그인 성공"));
					user_ID = m_Login_ID;
					break;
				}
			}
	
			custom.MoveNext();
		}
		custom.Close();
	}
	else
	{
		Clerk clk;
		if (!clk.Open())
		{
			AfxMessageBox(_T("데이터 소스와 연결 못함"));
		}

		while (!clk.IsEOF())
		{
			CStringW ID(m_Login_ID);	//아이디 형변환
			LPCWSTR pID = ID;
			CStringW PW(m_Login_PW);	//비밀번호 형변환
			LPCWSTR pPW = PW;
			if (clk.m_Cl_ID.Compare(pID)==0)	//아이디 확인
			{
				if (clk.m_Cl_PW.Compare(pPW)==0)	//비밀번호 확인
				{
					AfxMessageBox(_T("로그인 성공"));
					user_ID = m_Login_ID;
					break;
				}
			}
			clk.MoveNext();
		}
	}
}

/*****************************************************
* Interface : void CLogin::OnClickedButtonReg()
* Parameter :
* 기능 : 회원가입을 클릭하였을 때 회원가입 창을 불러오는 기능
*****************************************************/

void CLogin::OnClickedButtonReg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Register reg;

	reg.DoModal();	//회원가입 창 불러오기
}
