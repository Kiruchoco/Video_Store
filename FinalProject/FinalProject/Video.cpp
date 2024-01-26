// Video.h : Video Ŭ������ �����Դϴ�.



// Video �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:19

/********************************************************
* ���ϸ� : Video.cpp
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� �����ͺ��̽�
*******************************************************/

#include "stdafx.h"
#include "Video.h"
IMPLEMENT_DYNAMIC(Video, CRecordset)

/*****************************************************
* Interface : Video::Video(CDatabase* pdb)
* Parameter : CDatabase* pdb
* ��� : ������
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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.

/*****************************************************
* Interface : CString Video::GetDefaultConnect()
* Parameter : 
* ��� : �����ͺ��̽� ���� �Լ�
*****************************************************/

CString Video::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString Video::GetDefaultSQL()
* Parameter :
* ��� : �����ͺ��̽� ���̺� ���� �Լ�
*****************************************************/

CString Video::GetDefaultSQL()
{
	return _T("[Video]");
}

/*****************************************************
* Interface : void Video::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* ��� : �����ͺ��̽��κ��� ���� �ҷ����̴� �Լ�
*****************************************************/

void Video::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[V_Code]"), m_V_Code);
	RFX_Text(pFX, _T("[V_ListCode]"), m_V_ListCode);
	RFX_Bool(pFX, _T("[V_Status]"), m_V_Status);
	RFX_Long(pFX, _T("[V_User]"), m_V_User);

}
/////////////////////////////////////////////////////////////////////////////
// Video ����

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


