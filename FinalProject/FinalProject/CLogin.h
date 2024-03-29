#pragma once
#include "Customer.h"
#include "Clerk.h"
#include "stdafx.h"

/********************************************************
* 파일명 : CLogin.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 로그인 창 헤더파일
*******************************************************/

// CLogin 대화 상자

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLogin();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	CString m_Login_ID;
	CString m_Login_PW;
	CButton m_rClient;
	CString user_ID;
	CString user_PW;
	afx_msg void OnClickedButtonLogin();
	afx_msg void OnClickedButtonReg();
};
