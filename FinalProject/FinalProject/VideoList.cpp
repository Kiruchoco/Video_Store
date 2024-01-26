// VideoList.h : VideoList Ŭ������ �����Դϴ�.



// VideoList �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:20

/********************************************************
* ���ϸ� : VideoList.cpp
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� ����Ʈ �����ͺ��̽�
*******************************************************/

#include "stdafx.h"
#include "VideoList.h"
IMPLEMENT_DYNAMIC(VideoList, CRecordset)

/*****************************************************
* Interface : VideoList::VideoList(CDatabase* pdb)
* Parameter : CDatabase* pdb
* ��� : ������
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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.

/*****************************************************
* Interface : CString VideoList::GetDefaultConnect()
* Parameter :
* ��� : �����ͺ��̽� ���� �Լ�
*****************************************************/

CString VideoList::GetDefaultConnect()
{
	return _T("DSN=VideoDB;DBQ=D:\\VideoManagement.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

/*****************************************************
* Interface : CString VideoList::GetDefaultSQL()
* Parameter :
* ��� : �����ͺ��̽� ���̺� ���� �Լ�
*****************************************************/

CString VideoList::GetDefaultSQL()
{
	return _T("[VideoList]");
}

/*****************************************************
* Interface : void VideoList::DoFieldExchange(CFieldExchange* pFX)
* Parameter : CFieldExchange* pFX
* ��� : �����ͺ��̽��κ��� ���� �о���̴� �Լ�
*****************************************************/

void VideoList::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[V_ListCode]"), m_V_ListCode);
	RFX_Text(pFX, _T("[V_Title]"), m_V_Title);
	RFX_Text(pFX, _T("[V_Genre]"), m_V_Genre);
	RFX_Long(pFX, _T("[V_Count]"), m_V_Count);

}
/////////////////////////////////////////////////////////////////////////////
// VideoList ����

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


