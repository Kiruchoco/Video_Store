// Trade.h : Trade Ŭ������ �����Դϴ�.



// Trade �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:45

/********************************************************
* ���ϸ� : Trade.cpp
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : �ŷ������� �����ϴ� �����ͺ��̽�
*******************************************************/

#include "stdafx.h"
#include "Trade.h"
IMPLEMENT_DYNAMIC(Trade, CRecordset)

/*****************************************************
* Interface : Trade::Trade(CDatabase* pdb)
* Parameter : CDatabase* pdb
* ��� : ������
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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.

/*****************************************************
* Interface : CString Trade::GetDefaultConnect()
* Parameter : 
* ��� : �����ͺ��̽� ���� ���� �Լ�
*****************************************************/

CString Trade::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Trade::GetDefaultSQL()
* Parameter :
* ��� : �����ͺ��̽� ���̺� ���� �Լ�
*****************************************************/

CString Trade::GetDefaultSQL()
{
	return _T("[Trade]");
}

/*****************************************************
* Interface : void Trade::DoFieldExchange(CFieldExchange* pFX)
* Parameter :
* ��� : �����ͺ��̽��κ��� ���� �ҷ����̴� �Լ�
*****************************************************/

void Trade::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[No]"), m_No);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Long(pFX, _T("[Cost]"), m_Cost);

}
/////////////////////////////////////////////////////////////////////////////
// Trade ����

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


