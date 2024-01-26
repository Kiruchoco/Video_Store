#pragma once
#include "Video.h"
#include "VideoList.h"
#include "CLogin.h"
#include "Trade.h"

// CRent 대화 상자

/********************************************************
* 파일명 : CRent.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 대여 헤더파일
*******************************************************/

class CRent : public CDialog
{
	DECLARE_DYNAMIC(CRent)

public:
	CRent(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRent();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Rent };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIddDialogRent();
	virtual BOOL OnInitDialog();
	CListBox m_ListLendable;
	CListBox m_ListRent;
	afx_msg void OnClickedButtonRend();
	afx_msg void OnClickedButtonRe();
};
