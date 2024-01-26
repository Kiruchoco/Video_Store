#pragma once
#include "Trade.h"

// BuyMatrial 대화 상자

/********************************************************
* 파일명 : BuyMatrial.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 구매등록 헤더파일
*******************************************************/

class BuyMatrial : public CDialog
{
	DECLARE_DYNAMIC(BuyMatrial)

public:
	BuyMatrial(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BuyMatrial();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_Buy_Name;
	int m_Buy_Cost;
	int m_Buy_Count;
	afx_msg void OnClickedButtonRegBuy();
};
