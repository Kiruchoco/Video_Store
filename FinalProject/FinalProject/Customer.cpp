// Customer.h : Customer Ŭ������ �����Դϴ�.



// Customer �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 7:55

/********************************************************
* ���ϸ� : Customer.cpp
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : �� ���� �����ͺ��̽�
*******************************************************/

#include "stdafx.h"
#include "Customer.h"
IMPLEMENT_DYNAMIC(Customer, CRecordset)

/*****************************************************
* Interface : Customer::Customer(CDatabase* pdb)
* Parameter : CDatabase* pdb
* ��� : �� �����ͺ��̽� ������ 
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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.

/*****************************************************
* Interface : CString Customer::GetDefaultConnect()
* Parameter : 
* ��� : �� �����ͺ��̽� ��ġ �Լ�
*****************************************************/

CString Customer::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Customer::GetDefaultSQL()
* Parameter :
* ��� : �� �����ͺ��̽� ���̺� �Լ�
*****************************************************/

CString Customer::GetDefaultSQL()
{
	return _T("[Customer]");
}

/*****************************************************
* Interface : void Customer::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* ��� : �� �����ͺ��̽��� ������ �ҷ����� �Լ�
*****************************************************/

void Customer::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[No]"), m_No);
	RFX_Text(pFX, _T("[Cu_ID]"), m_Cu_ID);
	RFX_Text(pFX, _T("[Cu_PW]"), m_Cu_PW);
	RFX_Text(pFX, _T("[Cu_Name]"), m_Cu_Name);
	RFX_Text(pFX, _T("[Cu_Tel]"), m_Cu_Tel);
	RFX_Text(pFX, _T("[Cu_Address]"), m_Cu_Address);
	RFX_Long(pFX, _T("[Cu_VideoCount]"), m_Cu_VideoCount);

}
/////////////////////////////////////////////////////////////////////////////
// Customer ����

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


