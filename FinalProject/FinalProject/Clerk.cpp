// Clerk.h : Clerk Ŭ������ �����Դϴ�.

// Clerk �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:07

/********************************************************
* ���ϸ� : Clerk.cpp
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� ���� �����ͺ��̽�
*******************************************************/

#include "stdafx.h"
#include "Clerk.h"
IMPLEMENT_DYNAMIC(Clerk, CRecordset)

/*****************************************************
* Interface : Clerk::Clerk(CDatabase* pdb)
* Parameter : CDatabase* pdb
* ��� : ������
*****************************************************/

Clerk::Clerk(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Cl_ID = L"";	//ID
	m_Cl_PW = L"";	//PW
	m_Cl_Name = L"";	//�̸�
	m_Cl_Tel = L"";		//����ó
	m_Cl_Address = L"";		//�ּ�
	m_Cl_hour = 0;		//�ٷνð�
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.

/*****************************************************
* Interface : CString Clerk::GetDefaultConnect()
* Parameter : 
* ��� : �����ͺ��̽� �ּҸ� �Է���
*****************************************************/

CString Clerk::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Clerk::GetDefaultSQL()
* Parameter :
* ��� : ���̺� ������ �Է���.
*****************************************************/

CString Clerk::GetDefaultSQL()
{
	return _T("[Clerk]");
}

/*****************************************************
* Interface : void Clerk::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* ��� :�ش� ���� �����ͺ��̽��κ��� ������
*****************************************************/

void Clerk::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Cl_ID]"), m_Cl_ID);
	RFX_Text(pFX, _T("[Cl_PW]"), m_Cl_PW);
	RFX_Text(pFX, _T("[Cl_Name]"), m_Cl_Name);
	RFX_Text(pFX, _T("[Cl_Tel]"), m_Cl_Tel);
	RFX_Text(pFX, _T("[Cl_Address]"), m_Cl_Address);
	RFX_Long(pFX, _T("[Cl_hour]"), m_Cl_hour);

}
/////////////////////////////////////////////////////////////////////////////
// Clerk ����

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


