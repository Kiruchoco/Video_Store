#pragma once
#include "Video.h"
#include "VideoList.h"
#include "Trade.h"

/********************************************************
* 파일명 : VideoBuy.h
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 비디오 구입 헤더파일
*******************************************************/

// VideoBuy 대화 상자

class VideoBuy : public CDialog
{
	DECLARE_DYNAMIC(VideoBuy)

public:
	VideoBuy(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~VideoBuy();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_VIDEO_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonVideoBuy();
	CString m_VideoTitle;
	CString m_VideoGenre;
	int m_VideoCost;
	int m_VideoCount;
};
