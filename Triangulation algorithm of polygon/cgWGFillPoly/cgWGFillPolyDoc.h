
// cgWGFillPolyDoc.h : CcgWGFillPolyDoc ��Ľӿ�
//


#pragma once


class CcgWGFillPolyDoc : public CDocument
{
protected: // �������л�����
	CcgWGFillPolyDoc();
	DECLARE_DYNCREATE(CcgWGFillPolyDoc)

// ����
public:
	int MHeight;/// �Ӵ��߶�
	int MWidth;/// �Ӵ����
	int MDisplayMode;/// ����ģʽ

	double pointwiseRunTime;/// ��㷨����ʱ��
	CString pointwiseInformation;/// ��㷨��ʾ��Ϣ
	double sortedEdgeTableTime;/// ����߱�����ʱ��
	CString sortedEdgeTableInformation;/// ����߱���ʾ��Ϣ
	double seedRunTime;/// ���ӷ�����ʱ��
	CString seedInformation;/// ���ӷ���ʾ��Ϣ
	CString comparisonInforamtion;/// �Ƚ���ʾ��Ϣ
	double polygonalTriangualtionRuntime;/// ����ε������ʷ�ʱ��
	CString polygonalTriangulationInformation;/// ����ε������ʷ���Ϣ

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CcgWGFillPolyDoc();
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
