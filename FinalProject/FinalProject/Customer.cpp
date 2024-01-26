// Customer.h : Customer 클래스의 구현입니다.



// Customer 구현입니다.

// 코드 생성 위치 2018년 12월 19일 수요일, 오후 7:55

/********************************************************
* 파일명 : Customer.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 고객 관련 데이터베이스
*******************************************************/

#include "stdafx.h"
#include "Customer.h"
IMPLEMENT_DYNAMIC(Customer, CRecordset)

/*****************************************************
* Interface : Customer::Customer(CDatabase* pdb)
* Parameter : CDatabase* pdb
* 기능 : 고객 데이터베이스 생성자 
*****************************************************/

Customer::Customer(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_No = 0;
	m_Cu_ID = L"";
	m_Cu_PW = L"";
	m_Cu_Name = L"";
	m_Cu_Tel = L"";
	m_Cu_Address = L"";
	m_Cu_VideoCount = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.

/*****************************************************
* Interface : CString Customer::GetDefaultConnect()
* Parameter : 
* 기능 : 고객 데이터베이스 위치 함수
*****************************************************/

CString Customer::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Customer::GetDefaultSQL()
* Parameter :
* 기능 : 고객 데이터베이스 테이블 함수
*****************************************************/

CString Customer::GetDefaultSQL()
{
	return _T("[Customer]");
}

/*****************************************************
* Interface : void Customer::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* 기능 : 고객 데이터베이스의 값들을 불러오는 함수
*****************************************************/

void Customer::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[No]"), m_No);
	RFX_Text(pFX, _T("[Cu_ID]"), m_Cu_ID);
	RFX_Text(pFX, _T("[Cu_PW]"), m_Cu_PW);
	RFX_Text(pFX, _T("[Cu_Name]"), m_Cu_Name);
	RFX_Text(pFX, _T("[Cu_Tel]"), m_Cu_Tel);
	RFX_Text(pFX, _T("[Cu_Address]"), m_Cu_Address);
	RFX_Long(pFX, _T("[Cu_VideoCount]"), m_Cu_VideoCount);

}
/////////////////////////////////////////////////////////////////////////////
// Customer 진단

#ifdef _DEBUG
void Customer::AssertValid() const
{
	CRecordset::AssertValid();
}

void Customer::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


