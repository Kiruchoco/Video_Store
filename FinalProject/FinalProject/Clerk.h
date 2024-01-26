// Clerk.h : Clerk�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:07

/********************************************************
* ���ϸ� : Clerk.h
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� �����ͺ��̽� �������
*******************************************************/

class Clerk : public CRecordset
{
public:
	Clerk(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Clerk)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_ID;
	CStringW	m_Cl_ID;	//���̵�
	CStringW	m_Cl_PW;	//��й�ȣ
	CStringW	m_Cl_Name;	//�̸�
	CStringW	m_Cl_Tel;	//����ó
	CStringW	m_Cl_Address;	//�ּ�
	long	m_Cl_hour;	//�ٷνð�

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


