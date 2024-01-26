
// FinalProjectDlg.h: 헤더 파일
//

#pragma once
#include "CLogin.h"
#include "CRent.h"
#include "CClerk.h"
#include "CBuy.h"
#include "CFinance.h"

/********************************************************
* 파일명 : FinalProjectDlg.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 프로젝트 초기화 헤더파일
*******************************************************/

// CFinalProjectDlg 대화 상자
class CFinalProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CFinalProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CLogin m_tab1;
	CRent m_tab2;
	CClerk m_tab3;
	CBuy m_tab4;
	CFinance m_tab5;

	CWnd* m_pwndShow;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
