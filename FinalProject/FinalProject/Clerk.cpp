// Clerk.h : Clerk 클래스의 구현입니다.

// Clerk 구현입니다.

// 코드 생성 위치 2018년 12월 19일 수요일, 오후 8:07

/********************************************************
* 파일명 : Clerk.cpp
* 제작자 : 홍주성(2015024123)
* 일자 : 2018.12.19.
* 설명 : 직원 관련 데이터베이스
*******************************************************/

#include "stdafx.h"
#include "Clerk.h"
IMPLEMENT_DYNAMIC(Clerk, CRecordset)

/*****************************************************
* Interface : Clerk::Clerk(CDatabase* pdb)
* Parameter : CDatabase* pdb
* 기능 : 생성자
*****************************************************/

Clerk::Clerk(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Cl_ID = L"";	//ID
	m_Cl_PW = L"";	//PW
	m_Cl_Name = L"";	//이름
	m_Cl_Tel = L"";		//연락처
	m_Cl_Address = L"";		//주소
	m_Cl_hour = 0;		//근로시간
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.

/*****************************************************
* Interface : CString Clerk::GetDefaultConnect()
* Parameter : 
* 기능 : 데이터베이스 주소를 입력함
*****************************************************/

CString Clerk::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Clerk::GetDefaultSQL()
* Parameter :
* 기능 : 테이블 정보를 입력함.
*****************************************************/

CString Clerk::GetDefaultSQL()
{
	return _T("[Clerk]");
}

/*****************************************************
* Interface : void Clerk::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* 기능 :해당 값을 데이터베이스로부터 가져옴
*****************************************************/

void Clerk::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Cl_ID]"), m_Cl_ID);
	RFX_Text(pFX, _T("[Cl_PW]"), m_Cl_PW);
	RFX_Text(pFX, _T("[Cl_Name]"), m_Cl_Name);
	RFX_Text(pFX, _T("[Cl_Tel]"), m_Cl_Tel);
	RFX_Text(pFX, _T("[Cl_Address]"), m_Cl_Address);
	RFX_Long(pFX, _T("[Cl_hour]"), m_Cl_hour);

}
/////////////////////////////////////////////////////////////////////////////
// Clerk 진단

#ifdef _DEBUG
void Clerk::AssertValid() const
{
	CRecordset::AssertValid();
}

void Clerk::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


