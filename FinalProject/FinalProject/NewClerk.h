#pragma once
#include "Clerk.h"

// NewClerk 대화 상자

/********************************************************
* 파일명 : NewClerk.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 신규 직원을 추가 헤더파일
*******************************************************/

class NewClerk : public CDialogEx
{
	DECLARE_DYNAMIC(NewClerk)

public:
	NewClerk(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~NewClerk();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NewClerk };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonReg();
	CString m_Reg_ID;
	CString m_Reg_PW;
	CString m_Reg_Name;
	CString m_Reg_Tel;
	CString m_Reg_Address;
};
