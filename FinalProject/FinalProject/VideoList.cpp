// VideoList.h : VideoList 클래스의 구현입니다.



// VideoList 구현입니다.

// 코드 생성 위치 2018년 12월 19일 수요일, 오후 8:20

/********************************************************
* 파일명 : VideoList.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 비디오 리스트 데이터베이스
*******************************************************/

#include "stdafx.h"
#include "VideoList.h"
IMPLEMENT_DYNAMIC(VideoList, CRecordset)

/*****************************************************
* Interface : VideoList::VideoList(CDatabase* pdb)
* Parameter : CDatabase* pdb
* 기능 : 생성자
*****************************************************/

VideoList::VideoList(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_V_ListCode = 0;
	m_V_Title = L"";
	m_V_Genre = L"";
	m_V_Count = 0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.

/*****************************************************
* Interface : CString VideoList::GetDefaultConnect()
* Parameter :
* 기능 : 데이터베이스 연결 함수
*****************************************************/

CString VideoList::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString VideoList::GetDefaultSQL()
* Parameter :
* 기능 : 데이터베이스 테이블 연결 함수
*****************************************************/

CString VideoList::GetDefaultSQL()
{
	return _T("[VideoList]");
}

/*****************************************************
* Interface : void VideoList::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* 기능 : 데이터베이스로부터 값을 읽어들이는 함수
*****************************************************/

void VideoList::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[V_ListCode]"), m_V_ListCode);
	RFX_Text(pFX, _T("[V_Title]"), m_V_Title);
	RFX_Text(pFX, _T("[V_Genre]"), m_V_Genre);
	RFX_Long(pFX, _T("[V_Count]"), m_V_Count);

}
/////////////////////////////////////////////////////////////////////////////
// VideoList 진단

#ifdef _DEBUG
void VideoList::AssertValid() const
{
	CRecordset::AssertValid();
}

void VideoList::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


