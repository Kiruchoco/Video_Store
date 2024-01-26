// Customer.h : Customer�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 7:55

/********************************************************
* ���ϸ� : Customer.h
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : �� �������
*******************************************************/

class Customer : public CRecordset
{
public:
	Customer(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Customer)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_No;
	CStringW	m_Cu_ID;	//���̵�
	CStringW	m_Cu_PW;	//��й�ȣ
	CStringW	m_Cu_Name;	//�̸�
	CStringW	m_Cu_Tel;	//����ó
	CStringW	m_Cu_Address;	//�ּ�
	long	m_Cu_VideoCount;	//���� ���� ����

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


