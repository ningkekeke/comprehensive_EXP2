
// 11��ʵ���_0Doc.h : CMy11��ʵ���_0Doc ��Ľӿ�
//


#pragma once
#include "11��ʵ���_0Set.h"


class CMy11��ʵ���_0Doc : public CDocument
{
protected: // �������л�����
	CMy11��ʵ���_0Doc();
	DECLARE_DYNCREATE(CMy11��ʵ���_0Doc)

// ����
public:
	CMy11��ʵ���_0Set m_My11��ʵ���_0Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy11��ʵ���_0Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
