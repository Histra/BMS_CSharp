
// cgWGFillPolyView.h : CcgWGFillPolyView ��Ľӿ�
//

#pragma once
#define N 1000

class CcgWGFillPolyView : public CView
{
protected: // �������л�����
	CcgWGFillPolyView();
	DECLARE_DYNCREATE(CcgWGFillPolyView)

// ����
public:
	CcgWGFillPolyDoc* GetDocument() const;/// ��ȡDocָ�뺯��
	int pNumbers;/// ����ζ���ĸ���                      
	CPoint MPolygon[N];/// ����δ洢
	CPoint mousePoint;/// ���λ��
	int edgeNumbers;/// ����αߵ�����
	double yMax[N], yMin[N], Xa[N], Dx[N];/// ����߱����ݽṹ
	int edgeEnd, edgeBegin;/// ����߱�����ʼ�ͱ߽���
	int yScan;/// ����߱�yɨ����
	int dx[4];/// ���ӷ�������ͨx�����ʾ
	int dy[4];/// ���ӷ�������ͨy����biaoshi
	COLORREF judgeRgb;/// ���ӷ���ʼλ�õ�����ֵ
	COLORREF targetRgb;/// ���ӷ���Ҫ��������ֵ

// ����
public:
	void Define_OriginalPoint(CDC *pDC);/// ���¶�������ϵ����
	void SortedEdgeTableFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC);/// ����߱�
	void LoadPolygon(int pNumbers, CPoint MPolygon[]);/// �������εı�
	void InsertPolygon(double x1, double y1, double x2, double y2);/// �������εı�
	void Include();/// �󽻺���
	void UpdataXvalue();/// ���²����伯�Ϻ���
	void SortX(int edgeBedin, int i);/// ������
	void FillScan(CDC* pDC);/// ��亯��
	void PointwiseFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC);/// ��㷨
	bool JudgeIn(int x, int y, double tempx[], double tempy[], int pNumbers);/// �ж�һ�����Ƿ��ڶ������
	void SeedFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC);/// ������䷨
	void SeedRecursion(int x, int y, CDC* pDC);/// ��ֹ��䷨�ݹ麯��
	bool PT(int pNumbers, CPoint MPolygon[], CDC* pDC);/// ����ε������ʷֺ���

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CcgWGFillPolyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // cgWGFillPolyView.cpp �еĵ��԰汾
inline CcgWGFillPolyDoc* CcgWGFillPolyView::GetDocument() const
   { return reinterpret_cast<CcgWGFillPolyDoc*>(m_pDocument); }
#endif

