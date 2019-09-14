
// DrawHeartView.cpp : CDrawHeartView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DrawHeart.h"
#endif

#include "DrawHeartDoc.h"
#include "DrawHeartView.h"
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawHeartView

IMPLEMENT_DYNCREATE(CDrawHeartView, CView)

BEGIN_MESSAGE_MAP(CDrawHeartView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CDrawHeartView ����/����

CDrawHeartView::CDrawHeartView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawHeartView::~CDrawHeartView()
{
}

BOOL CDrawHeartView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

void CDrawHeartView::Define_OriginalPoint(CDC *pDC) {
	CDrawHeartDoc *pDoc = GetDocument();// ��ȡ�ĵ���CcgWGDrawLineDoc��ָ��
	CRect rect;
	GetClientRect(&rect);// ��ô��ڵĵ�ǰ�Ŀͻ���
	pDC->SetMapMode(MM_ANISOTROPIC);// ����ָ���豸������ӳ�䷽ʽ
									/// �߼�������߼������ת��
	pDC->SetViewportOrg(rect.right / 2, rect.bottom / 2);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(pDoc->MWidth, -pDoc->MHeight);
}


// CDrawHeartView ����

void CDrawHeartView::OnDraw(CDC* /*pDC*/)
{
	CDrawHeartDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC* pDC = GetDC();
	Define_OriginalPoint(pDC);
	
	/*const double pi = 3.141592654;
	double b = 300;
	const int time = 100000;
	int lim = 1.82*time;
	for (int i = -lim; i < lim; i++) {
		double x = i / double(time);
		//double y = pow(x*x, 1 / 3.0) + 0.9*sqrt(3.3 - x*x)*sin(b*x*pi);
		double y = pow(x*x, 1 / 3.0) + 0.7*sqrt(3.3 - x*x)*sin(b*x*pi);
		pDC->SetPixel(x * 50, y * 50, RGB(255, 0, 0));
		//pDC->SetPixel((x+0.01)*50, (y+0.01)*50, RGB(0, 255, 0));
	}*/
	const double pi = 3.141592654;
	double b = 320;
	const int tim = 10000;
	int lim = 1.82*tim;
	int coun = 99;
	srand(unsigned(time(NULL)));
	for (int i = -lim; i < lim; i++) {
		double x = i / double(tim);
		double y = pow(x*x, 1 / 3.0) + 0.7*sqrt(3.3 - x*x)*sin(b*x*pi);
		pDC->SetPixel(x * 50, y * 50, RGB(255, 0, 0));
	}
	while (coun--) {
		int xt = rand() % 150;
		int yt = rand() % 150;
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		int xsign = rand() % 2;
		int ysign = rand() % 2;
		int size = rand() % 35 + 16;
		for (int i = -lim; i < lim; i++) {
			double x = i / double(tim);
			double y = pow(x*x, 1 / 3.0) + 0.7*sqrt(3.3 - x*x)*sin(b*x*pi);
			x += xt / 10.0;
			y += yt / 10.0;
			if (xsign == 0)
				x = -x;
			if (ysign == 0)
				y = -y;
			pDC->SetPixel(x * size, y * size, RGB(r, g, b));
		}
	}
	MessageBox(_T("�������Ҹ����99���ģ���ϲ���㣡"));

	
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawHeartView ��ӡ

BOOL CDrawHeartView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawHeartView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawHeartView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawHeartView ���

#ifdef _DEBUG
void CDrawHeartView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawHeartView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawHeartDoc* CDrawHeartView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawHeartDoc)));
	return (CDrawHeartDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawHeartView ��Ϣ�������


void CDrawHeartView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	CDrawHeartDoc *pDoc = GetDocument();
	pDoc->MWidth = cx;
	pDoc->MHeight = cy;
	// TODO: �ڴ˴������Ϣ����������
}
