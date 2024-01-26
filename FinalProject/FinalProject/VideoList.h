// VideoList.h : VideoList�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 19�� ������, ���� 8:20

/********************************************************
* ���ϸ� : VideoList.h
* ������ : ȫ�ּ�(2015024123)
* ���� : 2018.12.19.
* ���� : ���� ����Ʈ �����ͺ��̽� �������
*******************************************************/

class VideoList : public CRecordset
{
public:
	VideoList(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(VideoList)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_V_ListCode;
	CString	m_V_Title;	//����
	CString	m_V_Genre;	//�帣
	long	m_V_Count;	//����

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


