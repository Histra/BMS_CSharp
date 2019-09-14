
// cgWGFillPolyView.cpp : CcgWGFillPolyView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "cgWGFillPoly.h"
#endif

#include "cgWGFillPolyDoc.h"
#include "cgWGFillPolyView.h"
#include <stack>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcgWGFillPolyView

IMPLEMENT_DYNCREATE(CcgWGFillPolyView, CView)

BEGIN_MESSAGE_MAP(CcgWGFillPolyView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CcgWGFillPolyView ����/����

CcgWGFillPolyView::CcgWGFillPolyView()
{
	// TODO: �ڴ˴���ӹ������
	pNumbers = 0;/// ��ʼ��pNumbers
	/// ��ʼ��dx��dy����
	dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
	dy[0] = -1, dy[1] = 0, dy[2] = 1, dy[3] = 0;
}

CcgWGFillPolyView::~CcgWGFillPolyView()
{
}

void CcgWGFillPolyView::Define_OriginalPoint(CDC *pDC) {
	CcgWGFillPolyDoc *pDoc = GetDocument();// ��ȡ�ĵ���CcgWGDrawLineDoc��ָ��
	CRect rect;
	GetClientRect(&rect);// ��ô��ڵĵ�ǰ�Ŀͻ���
	pDC->SetMapMode(MM_ANISOTROPIC);// ����ָ���豸������ӳ�䷽ʽ
									/// �߼�������߼������ת��
	pDC->SetViewportOrg(rect.right / 2, rect.bottom / 2);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(pDoc->MWidth, -pDoc->MHeight);
}

BOOL CcgWGFillPolyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CcgWGFillPolyView ����

void CcgWGFillPolyView::OnDraw(CDC* /*pDC*/)
{
	CcgWGFillPolyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	/*CDC* pDC = GetDC();
	/// ��������ϵ
	pDC->MoveTo(0, pDoc->MHeight / 2);
	pDC->LineTo(pDoc->MWidth, pDoc->MHeight / 2);
	pDC->MoveTo(pDoc->MWidth / 2, 0);
	pDC->LineTo(pDoc->MWidth / 2, pDoc->MHeight);*/

	///Define_OriginalPoint(pDC);	
}


// CcgWGFillPolyView ��ӡ

BOOL CcgWGFillPolyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CcgWGFillPolyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CcgWGFillPolyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CcgWGFillPolyView ���

#ifdef _DEBUG
void CcgWGFillPolyView::AssertValid() const
{
	CView::AssertValid();
}

void CcgWGFillPolyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcgWGFillPolyDoc* CcgWGFillPolyView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcgWGFillPolyDoc)));
	return (CcgWGFillPolyDoc*)m_pDocument;
}
#endif //_DEBUG


// CcgWGFillPolyView ��Ϣ�������

void CcgWGFillPolyView::PointwiseFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC)
{
	DWORD dwStart = GetTickCount();/// ��ȡ��ʼʱ��

	const int INF = 0x3f3f3f3f;/// �������ֵ����
	int maxX = -INF, minX = INF, maxY = -INF, minY = INF;/// ������ֵ
	/// tempx��tempy��MPolygon�����ư��洢����
	double tempx[N];/// ����tempx
	double tempy[N];/// ����tempy
	for (int i = 0; i < pNumbers; i++) {/// ����tempx��tempy����
		tempx[i] = MPolygon[i].x;
		tempy[i] = MPolygon[i].y;
		if (tempx[i] > maxX) {
			maxX = (int)tempx[i];
		}
		if (tempx[i] < minX) {
			minX = (int)tempx[i];
		}
		if (tempy[i] > maxY) {
			maxY = (int)tempy[i];
		}
		if (tempy[i] < minY) {
			minY = (int)tempy[i];
		}
		tempy[i] += 0.5;/// ���ư��
	}
	for (int i = minX; i <= maxX; i++) {/// ѭ��������������
		for (int j = minY; j <= maxY; j++) {
			if (JudgeIn(i, j, tempx, tempy, pNumbers)) {/// �ж��õ��ǲ����ڶ������
				pDC->SetPixel(i, j, RGB(255, 0, 0));
			}
		}
	}

	DWORD dwStop = GetTickCount();/// ��ý���ʱ��
	DWORD dwInterval = dwStop - dwStart;/// �������ʱ��
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();/// ���Docָ��
	pDoc->pointwiseRunTime = (double)dwInterval;/// ������д��pointwiseRunTime
	CString str;/// ������д��pointwiseInformation���������ʽ��
	str.Format(_T("%.2lf"), pDoc->pointwiseRunTime);
	pDoc->pointwiseInformation += _T("Runtime Consuming : ") + str + _T("ms\r\n");

	pDoc->UpdateAllViews(this);/// ������ͼ
}

bool CcgWGFillPolyView::JudgeIn(int x, int y, double tempx[], double tempy[], int pNumbers)
{/// �ж�һ����(x, y)�ǲ����ڶ����(tempx��tempy��ʾ)�ڣ�pNumbers�Ƕ���ε�ĸ���
	int i, j;/// ����ѭ������
	int ans = 0;/// ans��ʾ��ǰ�����������ߺͶ���εĽ������
	for (i = 1, j = 0; i < pNumbers; j = i++) {/// ����
		bool cond1 = (y < tempy[i] && y > tempy[j]);/// ����һ
		bool cond2 = (y < tempy[j] && y > tempy[i]);/// ������
		bool cond3;/// ������
		if (tempy[i] - tempy[j] > 0)
			cond3 = ((y*(tempx[i] - tempx[j]) - tempy[j] * (tempx[i] - tempx[j]) + (tempy[i] - tempy[j])*tempx[j]) 
				>= x * (tempy[i] - tempy[j]));
		else
			cond3 = ((y*(tempx[i] - tempx[j]) - tempy[j] * (tempx[i] - tempx[j]) + (tempy[i] - tempy[j])*tempx[j]) 
				<= x * (tempy[i] - tempy[j]));
		if ((cond1 || cond2) && cond3) {
			ans++;/// ����ans
		} 
	}
	return (ans % 2 != 0);/// ansΪż������FALSE����������TRUE
}

void CcgWGFillPolyView::SortedEdgeTableFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC)
{
	DWORD dwStart = GetTickCount();/// ��ȡ��ʼʱ��
	const int runCount = 100;/// �������д���
	int time = runCount;

	while (time--) {/// ѭ����ͼ
		edgeNumbers = 0;/// ����߸���
		LoadPolygon(pNumbers, MPolygon);/// ����MPolygon����
		edgeBegin = edgeEnd = 0;/// ����߿�ʼ�ͱ߽�������
		yScan = (int)yMax[0];/// ��ʼ��yɨ����
		Include();/// �ж��Ƿ��н���
		UpdataXvalue();/// ���¿�ʼ�ߺͽ����ߣ��༴��ǰ�����ıߵļ���
		while (edgeBegin < edgeEnd) {/// ����ʼ�ߺͽ����߲��غ�ʱ
			FillScan(pDC);/// ��ֱ��
			yScan--;/// yɨ���ߵ�������
			Include();/// �ж��Ƿ񽻵㣬�༴�Ƿ����µı߼���
			UpdataXvalue();/// ���µ�ǰ�����ıߵļ���
		}
	}

	DWORD dwStop = GetTickCount();/// ��ȡ����ʱ��
	DWORD dwInterval = dwStop - dwStart;/// ��ȡ����ʱ��
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();/// ��ȡDocָ��
	pDoc->sortedEdgeTableTime = (double)dwInterval / runCount;/// ������ʱ��д��sortedEdgeTableTime
	CString str;/// ������д��sortedEdgeTableInformation��
	str.Format(_T("%.2lf"), pDoc->sortedEdgeTableTime);
	pDoc->sortedEdgeTableInformation += _T("Runtime Consuming : ") + str + _T("ms\r\n");

	pDoc->UpdateAllViews(this);/// ������ͼ
}


void CcgWGFillPolyView::LoadPolygon(int pNumbers, CPoint MPolygon[])
{
	double x1, y1, x2, y2;/// �������

	x1 = MPolygon[0].x; 
	y1 = MPolygon[0].y + 0.5;/// ���ư��
	for (int i = 1; i < pNumbers; i++) {
		x2 = MPolygon[i].x;
		y2 = MPolygon[i].y + 0.5;
		if (y1 != y2) {/// ��б�ʲ�Ϊ0��ֱ�߲�ִ��д��
			InsertPolygon(x1, y1, x2, y2);
		}
		x1 = x2;/// ����x1
		y1 = y2;/// ����x2
	}
}

void CcgWGFillPolyView::InsertPolygon(double x1, double y1, double x2, double y2)
{
	int i;/// ����ѭ������
	double Ymax, Ymin;/// ��������������ֵYmax����СֵYmin
	Ymax = (y2 > y1) ? y2 : y1;/// ����Ymax
	Ymin = (y2 > y1) ? y1 : y2;/// ����Ymin
	i = edgeNumbers;/// ����iֵΪ�߸���
	/// ð�����򣬰����������С��������
	while (i > 0 && Ymax > yMax[i - 1]) {///���߲��գ��ҵ�ǰYmax������һ���ߵ�������
		yMax[i] = yMax[i - 1];/// ������ֵ
		yMin[i] = yMin[i - 1];
		Xa[i] = Xa[i - 1];
		Dx[i] = Dx[i - 1];
		i--;/// ����i��iͬʱ�ִ���Ymax��Ymin��Ҫ�����λ��
	}
	yMax[i] = Ymax;/// ��ֵ
	yMin[i] = Ymin;/// ��ֵ
	if (y2 > y1) /// ����Xa[i]����ֵΪYmax��Ӧ�ĺ�����ֵ;
		Xa[i] = x2;
	else         
		Xa[i] = x1;
	Dx[i] = (x1 - x2) / (y1 - y2);/// ����Dx[i]Ϊ��ǰֱ�ߵ�б�ʵĵ���
	edgeNumbers++;/// �ߵĸ�����һ
}

void CcgWGFillPolyView::Include()
{
	while (edgeEnd < edgeNumbers && yScan < yMax[edgeEnd]) {
		/// ���߽���С�ڱ�������ɨ����С�ڱ߽����ߵ�y����ʱ
		Xa[edgeEnd] = Xa[edgeEnd] - 0.5 * Dx[edgeEnd];///���������x����
		Dx[edgeEnd] = -Dx[edgeEnd];/// ȥDx�ĵ����������������
		edgeEnd++;/// ��֤��������һ���±�
	}
}

void CcgWGFillPolyView::UpdataXvalue()
{
	int start = edgeBegin;/// ����start�߱���

	for (int i = start; i < edgeEnd; i++) {///��start�ߵ������߱���
		if (yScan > yMin[i]) {/// ��ǰi�ߵ�yMinС��yɨ����
			Xa[i] = Xa[i] + Dx[i];/// ����Xa[i]����ֵ������һ�ε�Xa[i]���
			SortX(edgeBegin, i);/// Xa����ӿ�ʼ�䵽��ǰ��i��С��������
		}
		else {/// ��ǰ����Ҫ��ȥ��
			for (int j = i; j > edgeBegin; j--) {
				/// �ӵ�ǰ��i����ʼ�ߴӺ���ǰ����
				yMin[j] = yMin[j - 1];/// ��һ���ߵ����ݸ���Ϊǰһ���ߵ�����
				Xa[j] = Xa[j - 1];
				Dx[j] = Dx[j - 1];
				///yMax[j] = yMax[j - 1];���Լ��ϣ������ò���
			}
			edgeBegin++;/// ���¿�ʼ��
		}
	}
}

void CcgWGFillPolyView::SortX(int edgeBegin, int i)
{
	double temp;/// ������ʱ����
	while (i > edgeBegin && Xa[i] < Xa[i - 1]) {/// ð������
		temp = Xa[i]; Xa[i] = Xa[i - 1]; Xa[i - 1] = temp;
		temp = Dx[i]; Dx[i] = Dx[i - 1]; Dx[i - 1] = temp;
		temp = yMin[i]; yMin[i] = yMin[i - 1]; yMin[i - 1] = temp;
		///temp = yMax[i]; yMax[i] = yMax[i - 1]; yMax[i - 1] = temp;���Լ���
		i--;/// ����
	}
}

void CcgWGFillPolyView::FillScan(CDC* pDC)
{
	for (int i = edgeBegin; i < edgeEnd; i += 2) {///���֮�仭��
		pDC->MoveTo(Xa[i], yScan);
		pDC->LineTo(Xa[i + 1], yScan);
	}
}

void CcgWGFillPolyView::SeedFillPolygon(int pNumbers, CPoint MPolygon[], CDC* pDC)
{
	DWORD dwStart = GetTickCount();/// ��ÿ�ʼʱ��
	const int INF = 0x3f3f3f3f;/// �������ֵ����
	int maxX = -INF, minX = INF, maxY = -INF, minY = INF;/// ��ֵ
	/// tempx��tempy��MPolygon�����ư��洢����
	double tempx[N];/// ����tempx
	double tempy[N];/// ����tempy
	for (int i = 0; i < pNumbers; i++) {/// ����tempx��tempy����
		tempx[i] = MPolygon[i].x;
		tempy[i] = MPolygon[i].y;
		if (tempx[i] > maxX) {
			maxX = (int)tempx[i];
		}
		if (tempx[i] < minX) {
			minX = (int)tempx[i];
		}
		if (tempy[i] > maxY) {
			maxY = (int)tempy[i];
		}
		if (tempy[i] < minY) {
			minY = (int)tempy[i];
		}
		tempy[i] += 0.5;/// ���ư��
	}
	srand(unsigned(time(NULL)));/// �������
	int randX, randY;/// ���������������(randX, randY)
	while (TRUE) {/// ֱ���ҵ��ڶ�����ڲ���һ����Ϊֹ
		/// �ھ�������(minX,minY)~(maxX, maxY)���ҵ�
		randX = rand() % (maxX - minX) + minX;
		randY = rand() % (maxY - minY) + minY;
		if (JudgeIn(randX, randY, tempx, tempy, pNumbers))
			break;/// �жϵ�ǰ���ǲ����ڶ������
	}

	judgeRgb = pDC->GetPixel(randX, randY);/// ����judgeRgb
	targetRgb = RGB(0, 255, 0);/// ������Ҫ������ɫ
	
	SeedRecursion(randX, randY, pDC);/// ִ�еݹ麯��

	DWORD dwStop = GetTickCount();/// ��ý���ʱ��
	DWORD dwInterval = dwStop - dwStart;/// ����ʱ��
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();/// ��ȡDocָ��
	pDoc->seedRunTime = (double)dwInterval;/// ������ʱ��д��seedRunTime��
	CString str;/// ������д��seedInformation,����ʽ��
	str.Format(_T("%.2lf"), pDoc->seedRunTime);
	pDoc->seedInformation += _T("Runtime Consuming : ") + str + _T("ms\r\n");

	pDoc->UpdateAllViews(this);/// ������ͼ	
}

void CcgWGFillPolyView::SeedRecursion(int x, int y, CDC* pDC)
{/// ͼ���ܻ�̫��qwq
	pDC->SetPixel(x, y, targetRgb);/// ����ǰ��
	for (int i = 0; i < 4; i++) {/// ѭ������dx��dy����,��ʵ�ֶ����������ͨ
		COLORREF now = pDC->GetPixel(x + dx[i], y + dy[i]);/// �õ��µĵ�ǰ�������ֵ
		if (now == judgeRgb)/// ����µĵ�ǰ�������ֵ��judgeRbg�Ļ�
			SeedRecursion(x + dx[i], y + dy[i], pDC);///�ݹ����SeedRecursion
	}
}

bool CcgWGFillPolyView::PT(int pNumbers, CPoint MPOlygon[], CDC* pDC)
{
	if (pNumbers <= 4)/// �����ǰ����εı���С��3��ô�ж��ö���ηǷ�
		return FALSE;

	DWORD dwStart = GetTickCount();/// ��ÿ�ʼ����ʱ��
	CPen pNewPen;///���廭����ɫΪ��ɫ
	pNewPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* poldPen = pDC->SelectObject(&pNewPen);
	/// ����ѭ������i,j,k
	int i = 0;
	int j = 1;
	int k = 2;
	while (pNumbers > 4) {/// ������εı�������3ʱ����
		bool cond1;/// ����һ������ij�ĺ�����ik�ļнǱ���С�ڦ�
		double a1 = MPOlygon[j].x - MPOlygon[i].x;
		double a2 = MPOlygon[j].y - MPOlygon[i].y;
		double b1 = MPOlygon[k].x - MPOlygon[i].x;
		double b2 = MPOlygon[k].y - MPOlygon[i].y;
		cond1 = (a1*b2 <= a2*b1);
		bool cond2 = TRUE;/// ����������ǰ������в�����������
		double tempx[4];/// ��ǰ��������ư��
		double tempy[4];
		tempx[0] = MPOlygon[i].x;
		tempy[0] = MPOlygon[i].y+0.5;
		tempx[1] = MPOlygon[j].x;
		tempy[1] = MPOlygon[j].y+0.5;
		tempx[2] = MPOlygon[k].x;
		tempy[2] = MPOlygon[k].y+0.5;
		tempx[3] = tempx[0];
		tempy[3] = tempy[0];
		for (int p = 0; p < pNumbers; p++) {
			if (p != i && p != j && p != k) {/// �ж��������Ƿ��ڵ�ǰ��������
				if (JudgeIn(MPOlygon[p].x, MPOlygon[p].y, tempx, tempy, 3 + 1)) {
					cond2 = FALSE;
					break;
				}	
			}
		}
		///cond1 = true;////
		if (cond1 && cond2) {/// ���ͬʱ��������һ��������
			pDC->MoveTo(MPOlygon[i]);/// ��i�㵽k�㻭��
			pDC->LineTo(MPOlygon[k]);
			for (int t = j; t < pNumbers - 1; t++) {/// ���µ�ǰ�����
				MPOlygon[t] = MPOlygon[t + 1];
			}
			pNumbers--;/// ���¶���εı���
			i = 0;/// ���¸�ֵi��j��k
			j = 1;
			k = 2;
		}
		else {/// ����
			i ++;/// i����һ��
			j = i + 1;
			k = j + 1;
		}
	}

	pDC->SelectObject(poldPen);/// ����pDC

	DWORD dwStop = GetTickCount();/// ��ý���ʱ��
	DWORD dwInterval = dwStop - dwStart;/// �������ʱ��
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();/// ���Docָ��
	pDoc->polygonalTriangualtionRuntime = (double)dwInterval;/// ������д��Doc����
	CString str;/// ������д��polygonalTriangulationInformation���������ʽ��
	str.Format(_T("%.2lf"), pDoc->polygonalTriangualtionRuntime);
	pDoc->polygonalTriangulationInformation += _T("Runtime Consuming : ") + str + _T("ms\r\n");

	pDoc->UpdateAllViews(this);/// ������ͼ
	return TRUE;
}

void CcgWGFillPolyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	CcgWGFillPolyDoc* pDoc = GetDocument();
	pDoc->MHeight = cy;
	pDoc->MWidth = cx;
	// TODO: �ڴ˴������Ϣ����������
}


void CcgWGFillPolyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (pNumbers < N) {/// ��ֹջ���
		MPolygon[pNumbers] = point;/// ����MPolygon����
		pNumbers++;
		mousePoint = point;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CcgWGFillPolyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC = GetDC();
	if (pNumbers > 0) {
		pDC->SetROP2(2);///ȡ����ɫ�ķ���Ĩ����һ����
		pDC->MoveTo(MPolygon[pNumbers - 1]);
		pDC->LineTo(mousePoint);

		mousePoint = point;
		pDC->MoveTo(MPolygon[pNumbers - 1]);
		pDC->LineTo(mousePoint);
	}

	CView::OnMouseMove(nFlags, point);
}

void CcgWGFillPolyView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();/// ��ȡDocָ��
	CDC* pDC = GetDC();/// ��ȡCDCָ��
	pDC->MoveTo(MPolygon[pNumbers-1]);
	pDC->LineTo(MPolygon[0]);/// �����һ����
	MPolygon[pNumbers] = MPolygon[0];/// �ٴ����һ����Ϊ��һ����
	pNumbers++;

	if (pDoc->MDisplayMode == 0) {/// �����ťPointwise��ִ��
		PointwiseFillPolygon(pNumbers, MPolygon, pDC);
	}
	if (pDoc->MDisplayMode == 1) {/// ���SortedEdgeTable��ť��ִ��
		SortedEdgeTableFillPolygon(pNumbers, MPolygon, pDC);
	}
	if (pDoc->MDisplayMode == 2) {/// ���Seed��ť��ִ��
		SeedFillPolygon(pNumbers, MPolygon, pDC);
	}
	if (pDoc->MDisplayMode == 3) {/// ���Comparison��ť��ִ��
		/// ����comparisonInformation���������ʽ��
		pDoc->comparisonInforamtion = "Here is The Comparison information:\r\n";
		pDoc->comparisonInforamtion += _T("\tPointWise\t\tSorted\t\tSeed\r\nTime:\t");
		CString str;/// ����Ϊ���ٴ�ִ���������������Ľ��д��comparisonInformation
		PointwiseFillPolygon(pNumbers, MPolygon, pDC);
		str.Format(_T("%.2lf"), pDoc->pointwiseRunTime);
		pDoc->comparisonInforamtion += str + _T("\t\t");
		SortedEdgeTableFillPolygon(pNumbers, MPolygon, pDC);
		str.Format(_T("%.2lf"), pDoc->sortedEdgeTableTime);
		pDoc->comparisonInforamtion += str + _T("\t\t");
		SeedFillPolygon(pNumbers, MPolygon, pDC);
		str.Format(_T("%.2lf"), pDoc->seedRunTime);
		pDoc->comparisonInforamtion += str + _T("\r\n");

		pDoc->UpdateAllViews(this);/// ������ͼ
	}
	if (pDoc->MDisplayMode == 4) {/// ���PolygonTriangulation��ť��ִ��
		if (!PT(pNumbers, MPolygon, pDC))/// Ҫ��������ʱ�뻭qwq
			MessageBox(_T("The Polygon is illegal!"));
	}
	pNumbers = 0;/// ���¶���εı���
	
	CView::OnLButtonDblClk(nFlags, point);
}

/*double a1 = (MPolygon[1].x - MPolygon[0].x);
		double a2 = (MPolygon[1].y - MPolygon[0].y);
		double b1 = (MPolygon[2].x - MPolygon[0].x);
		double b2 = (MPolygon[2].y - MPolygon[0].y);
		if (a1*b2 > b1*a2) {
			std::stack<CPoint>sta;
			for (int i = 0; i < pNumbers; i++) {
				sta.push(MPolygon[i]);
			}
			int i = 0;
			while (!sta.empty()) {
				MPolygon[i++] = sta.top();
				sta.pop();
			}
		}*/
/// MDisplayMode = 4�� ���Ϻ�˳ʱ��Ҳ��