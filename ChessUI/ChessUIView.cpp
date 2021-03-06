
// ChessUIView.cpp : implementation of the CChessUIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ChessUI.h"
#endif

#include "ChessUIDoc.h"
#include "ChessUIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChessUIView

IMPLEMENT_DYNCREATE(CChessUIView, CView)

BEGIN_MESSAGE_MAP(CChessUIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChessUIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CChessUIView construction/destruction

CChessUIView::CChessUIView()
{
	// TODO: add construction code here

}

CChessUIView::~CChessUIView()
{
}

BOOL CChessUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CChessUIView drawing

void CChessUIView::OnDraw(CDC* pDC)
{
	CChessUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//ChessBoard Grid
	pDC->Rectangle(CRect(360, 50, 920, 610));

	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 0));
	CBrush *pTempBrush = (CBrush*)pDC->SelectObject(&brush);

	int iStart = 360, jStart = 50, iEnd = 850, jEnd = 540;		
	int increment = 70;

	bool colour = true;
	for (int j = jStart; j < jEnd + 1; j = j + increment)
	{
		colour = !colour;
		for (int i = iStart; i < iEnd + 1; i = i + increment)
		{
			if (colour == true)
			{
				pDC->Rectangle(i, j, i + increment, j + increment);
			}
			colour = !colour;
		}
	}

	pDC->SelectObject(pTempBrush);

	std::map<Piece*, CBitmap*> pieceBitmapMap = GetDocument()->retunMap();
	CDC dcMemory[32];

	for (int i = 0; i < 32; i++)
	{
		Piece *tempPiece = GetDocument()->returnGame()->returnPiece(i);
		CBitmap *MappedBitmap = pieceBitmapMap[tempPiece];
		
		BITMAP bm;
		MappedBitmap->GetBitmap(&bm);
		int bmWidth = bm.bmWidth;
		int bmHeight = bm.bmHeight;

		CPoint point = getPixelCoordinates(tempPiece->getI(), tempPiece->getJ());

		//loading bitmap in this line 
		dcMemory[i].CreateCompatibleDC(pDC);
		dcMemory[i].SelectObject(MappedBitmap);
		pDC->StretchBlt(point.x, point.y, 50, 50, &dcMemory[i], 0, 0, bmWidth, bmHeight, SRCCOPY);
	}
}


// CChessUIView printing


void CChessUIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChessUIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChessUIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChessUIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CChessUIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChessUIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChessUIView diagnostics

#ifdef _DEBUG
void CChessUIView::AssertValid() const
{
	CView::AssertValid();
}

void CChessUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessUIDoc* CChessUIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessUIDoc)));
	return (CChessUIDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessUIView message handlers


void CChessUIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (!(point.y < 609 && point.y > 51 && point.x < 919 && point.x > 361))
		return;

	Game *game = GetDocument()->returnGame();

	if (m_firstSelection == true)
	{
		CPoint tempPoint = convertToBoardPoint(point);
		if (game->isSelectionValid(tempPoint.x, tempPoint.y) == true)
		{
			m_firstPosition = tempPoint;
			m_firstSelection = false;

			/*CString str;// = L"Point: ";
			str.Format(L"Point: %d, %d", m_firstPosition.x, m_firstPosition.y);
			AfxMessageBox(str);*/
		}
	}
	else
	{
		CPoint secondPosition = convertToBoardPoint(point);
		bool moved = game->makeValidMove(m_firstPosition.x, m_firstPosition.y, secondPosition.x, secondPosition.y);

		if (moved)
		{
			Invalidate(TRUE);
		}

		m_firstSelection = true;
		/*CString str;// = L"Point: ";
		str.Format(L"Point: %d, %d", selectedPiece->getI(), selectedPiece->getJ());
		AfxMessageBox(str);
		CView::OnLButtonUp(nFlags, point);*/
	}

	CView::OnLButtonUp(nFlags, point);
}

// My funtions

CPoint CChessUIView::getPixelCoordinates(int i, int j)
{
	CPoint point;

	point.y = 550 - (70 * i);
	point.x = (70 * j) + 370;

	return point;
}

CPoint CChessUIView::convertToBoardPoint(CPoint point)
{
	CPoint boardPoint;

	boardPoint.x = (610 - point.y) / 70;
	boardPoint.y = (point.x - 360) / 70;

	return boardPoint;
}
