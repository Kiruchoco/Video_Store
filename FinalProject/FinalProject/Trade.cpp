// Trade.h : Trade 클래스의 구현입니다.



// Trade 구현입니다.

// 코드 생성 위치 2018년 12월 19일 수요일, 오후 8:45

/********************************************************
* 파일명 : Trade.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 거래내역을 저장하는 데이터베이스
*******************************************************/

#include "stdafx.h"
#include "Trade.h"
IMPLEMENT_DYNAMIC(Trade, CRecordset)

/*****************************************************
* Interface : Trade::Trade(CDatabase* pdb)
* Parameter : CDatabase* pdb
* 기능 : 생성자
*****************************************************/

Trade::Trade(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_No = 0;
	m_Type = L"";
	m_Title = L"";
	m_Cost = 0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.

/*****************************************************
* Interface : CString Trade::GetDefaultConnect()
* Parameter : 
* 기능 : 데이터베이스 연결 설정 함수
*****************************************************/

CString Trade::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Trade::GetDefaultSQL()
* Parameter :
* 기능 : 데이터베이스 테이블 설정 함수
*****************************************************/

CString Trade::GetDefaultSQL()
{
	return _T("[Trade]");
}

/*****************************************************
* Interface : void Trade::DoFieldExchange(CFieldExchange* pFX)
* Parameter :
* 기능 : 데이터베이스로부터 값을 불러들이는 함수
*****************************************************/

void Trade::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[No]"), m_No);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Long(pFX, _T("[Cost]"), m_Cost);

}
/////////////////////////////////////////////////////////////////////////////
// Trade 진단

#ifdef _DEBUG
void Trade::AssertValid() const
{
	CRecordset::AssertValid();
}

void Trade::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


