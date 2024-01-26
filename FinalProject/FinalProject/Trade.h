// Trade.h : Trade�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:45

/********************************************************
* ���ϸ� : Trade.h
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : �ŷ� �����ͺ��̽� �������
*******************************************************/

class Trade : public CRecordset
{
public:
	Trade(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Trade)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_No;	//�ŷ���ȣ
	CStringW	m_Type;	//�ŷ�����
	CStringW	m_Title;	//�ŷ�����
	long	m_Cost;	//�ݾ�

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


