#pragma once

#include "Trade.h"

/********************************************************
* 파일명 : CFinance.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 재무관리 창 헤더파일
*******************************************************/

// CFinance 대화 상자

class CFinance : public CDialog
{
	DECLARE_DYNAMIC(CFinance)

public:
	CFinance(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFinance();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Finance };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListFinance;
	int Revenue=0;
	int Cost=0;
};
