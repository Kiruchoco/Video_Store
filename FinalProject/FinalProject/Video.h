// Video.h : Video�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:19

/********************************************************
* ���ϸ� : Video.h
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� �����ͺ��̽� �������
*******************************************************/

class Video : public CRecordset
{
public:
	Video(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Video)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_V_Code;	//���� �Ϸù�ȣ
	CStringW	m_V_ListCode;	//���� ����Ʈ �Ϸù�ȣ
	BOOL	m_V_Status;	//�뿩 ����
	long	m_V_User;	//�� �Ϸù�ȣ

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


