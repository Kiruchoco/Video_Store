// Video.h : Video 클래스의 구현입니다.



// Video 구현입니다.

// 코드 생성 위치 2018년 12월 19일 수요일, 오후 8:19

/********************************************************
* 파일명 : Video.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 비디오 데이터베이스
*******************************************************/

#include "stdafx.h"
#include "Video.h"
IMPLEMENT_DYNAMIC(Video, CRecordset)

/*****************************************************
* Interface : Video::Video(CDatabase* pdb)
* Parameter : CDatabase* pdb
* 기능 : 생성자
*****************************************************/

Video::Video(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_V_Code = 0;
	m_V_ListCode = L"";
	m_V_Status = FALSE;
	m_V_User = 0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.

/*****************************************************
* Interface : CString Video::GetDefaultConnect()
* Parameter : 
* 기능 : 데이터베이스 설정 함수
*****************************************************/

CString Video::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Video::GetDefaultSQL()
* Parameter :
* 기능 : 데이터베이스 테이블 설정 함수
*****************************************************/

CString Video::GetDefaultSQL()
{
	return _T("[Video]");
}

/*****************************************************
* Interface : void Video::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* 기능 : 데이터베이스로부터 값을 불러들이는 함수
*****************************************************/

void Video::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[V_Code]"), m_V_Code);
	RFX_Text(pFX, _T("[V_ListCode]"), m_V_ListCode);
	RFX_Bool(pFX, _T("[V_Status]"), m_V_Status);
	RFX_Long(pFX, _T("[V_User]"), m_V_User);

}
/////////////////////////////////////////////////////////////////////////////
// Video 진단

#ifdef _DEBUG
void Video::AssertValid() const
{
	CRecordset::AssertValid();
}

void Video::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


