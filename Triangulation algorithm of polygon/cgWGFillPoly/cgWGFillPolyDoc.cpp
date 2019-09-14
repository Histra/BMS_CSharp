
// cgWGFillPolyDoc.cpp : CcgWGFillPolyDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "cgWGFillPoly.h"
#endif

#include "cgWGFillPolyDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CcgWGFillPolyDoc

IMPLEMENT_DYNCREATE(CcgWGFillPolyDoc, CDocument)

BEGIN_MESSAGE_MAP(CcgWGFillPolyDoc, CDocument)
END_MESSAGE_MAP()


// CcgWGFillPolyDoc ����/����

CcgWGFillPolyDoc::CcgWGFillPolyDoc()
{
	// TODO: �ڴ����һ���Թ������
	MHeight = 0;
	MWidth = 0;

	MDisplayMode = -1;

	sortedEdgeTableInformation = "Here is the SortedEdgeTable information:\r\n";
	pointwiseInformation = "Here is the Pointwise information:\r\n";
	seedInformation = "Here is The Seed information:\r\n";
	comparisonInforamtion = "Here is The Comparison information:\r\n";
	polygonalTriangulationInformation = "Here is The PolygonTriangulation information:\r\n";
	sortedEdgeTableTime = 0;
	pointwiseRunTime = 0;
	seedRunTime = 0;
	polygonalTriangualtionRuntime = 0;
}

CcgWGFillPolyDoc::~CcgWGFillPolyDoc()
{
}

BOOL CcgWGFillPolyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CcgWGFillPolyDoc ���л�

void CcgWGFillPolyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CcgWGFillPolyDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CcgWGFillPolyDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CcgWGFillPolyDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CcgWGFillPolyDoc ���

#ifdef _DEBUG
void CcgWGFillPolyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CcgWGFillPolyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CcgWGFillPolyDoc ����
