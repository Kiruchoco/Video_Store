#pragma once

#include "Clerk.h"
#include "Trade.h"

// CClerk 대화 상자

/********************************************************
* 파일명 : CClerk.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 직원 관리 헤더파일
*******************************************************/

class CClerk : public CDialog
{
	DECLARE_DYNAMIC(CClerk)

public:

	CClerk(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CClerk();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Clerk };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ClerkList;
	afx_msg void OnClickedButtonNew();
	afx_msg void OnClickedButtonPay();
};
