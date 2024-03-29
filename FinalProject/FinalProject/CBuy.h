#pragma once

#include "Trade.h"

/********************************************************
* 파일명 : CBuy.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 물품구입 및 비디오 구매 헤더파일
*******************************************************/

// CBuy 대화 상자

class CBuy : public CDialog
{
	DECLARE_DYNAMIC(CBuy)

public:
	CBuy(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBuy();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Buy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PreInitDialog();
public:
	CListCtrl m_ListBuy;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonBuy();
	afx_msg void OnClickedButtonVideo();
};
