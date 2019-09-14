// SelectControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "cgWGFillPoly.h"
#include "SelectControl.h"
#include "cgWGFillPolyDoc.h"


// SelectControl

IMPLEMENT_DYNCREATE(SelectControl, CFormView)

SelectControl::SelectControl()
	: CFormView(IDD_SELECTCONTROL)
	, Information(_T("Hello, Here is the Second Experiment of\r\nthe Computer Graphics Class!\r\n\r\nThe Application belongs to 16020031075����\r\n"))
{

}

SelectControl::~SelectControl()
{
}

void SelectControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SI, Information);
}

BEGIN_MESSAGE_MAP(SelectControl, CFormView)
	ON_BN_CLICKED(IDC_POINTWISE, &SelectControl::OnBnClickedPointwise)
	ON_BN_CLICKED(IDC_SORTEDEDGETABLE, &SelectControl::OnBnClickedSortededgetable)
	ON_BN_CLICKED(IDC_SEED, &SelectControl::OnBnClickedSeed)
	ON_BN_CLICKED(IDC_COMPARISON, &SelectControl::OnBnClickedComparison)
	ON_BN_CLICKED(IDC_POLYGONALTRIANGULATION, &SelectControl::OnBnClickedPolygonaltriangulation)
END_MESSAGE_MAP()


// SelectControl ���

#ifdef _DEBUG
void SelectControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SelectControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SelectControl ��Ϣ�������


void SelectControl::OnBnClickedPointwise()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	pDoc->MDisplayMode = 0;
	pDoc->UpdateAllViews(this);
}

void SelectControl::OnBnClickedSortededgetable()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	pDoc->MDisplayMode = 1;
	pDoc->UpdateAllViews(this);
}

void SelectControl::OnBnClickedSeed()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	pDoc->MDisplayMode = 2;
	pDoc->UpdateAllViews(this);
}

void SelectControl::OnBnClickedComparison()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	pDoc->MDisplayMode = 3;
	pDoc->UpdateAllViews(this);
}


void SelectControl::OnBnClickedPolygonaltriangulation()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("����ʱ�뻭�㣬��������"));
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	pDoc->MDisplayMode = 4;
	pDoc->UpdateAllViews(this);
}

void SelectControl::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	CcgWGFillPolyDoc* pDoc = (CcgWGFillPolyDoc*)GetDocument();
	if (pDoc->MDisplayMode == 0) {/// ��㷨
		GetDlgItem(IDC_SI)->SetWindowText(pDoc->pointwiseInformation);
	}
	if (pDoc->MDisplayMode == 1) {/// ����߱�
		GetDlgItem(IDC_SI)->SetWindowText(pDoc->sortedEdgeTableInformation);
	}
	if (pDoc->MDisplayMode == 2){/// ���ӷ�
		GetDlgItem(IDC_SI)->SetWindowText(pDoc->seedInformation);
	}
	if (pDoc->MDisplayMode == 3) {/// �������ַ����ıȽ�
		GetDlgItem(IDC_SI)->SetWindowText(pDoc->comparisonInforamtion);
	}
	if (pDoc->MDisplayMode == 4) {/// ����ε������ʷ��㷨
		GetDlgItem(IDC_SI)->SetWindowText(pDoc->polygonalTriangulationInformation);
	}
}


void SelectControl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
}



