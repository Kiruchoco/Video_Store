#pragma once

#include "Customer.h"

/********************************************************
* 파일명 : Register.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 회원가입 헤더파일
*******************************************************/

// Register 대화 상자

class Register : public CDialog
{
	DECLARE_DYNAMIC(Register)

public:
	Register(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Register();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Reg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_Reg_ID;
	CString m_Reg_PW;
	CString m_Reg_Name;
	CString m_Reg_Tel;
	CString m_Reg_Address;
	afx_msg void OnClickedButton1();
};
