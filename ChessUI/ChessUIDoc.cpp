
// ChessUIDoc.cpp : implementation of the CChessUIDoc class
//

#include "stdafx.h"

using namespace std;
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ChessUI.h"
#endif

#include "ChessUIDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChessUIDoc

IMPLEMENT_DYNCREATE(CChessUIDoc, CDocument)

BEGIN_MESSAGE_MAP(CChessUIDoc, CDocument)
END_MESSAGE_MAP()

// CChessUIDoc construction/destruction 

CChessUIDoc::CChessUIDoc()
{
	// TODO: add one-time construction code here

	for (int i = 0; i < 32; i++)
	{
		bool pieceMapped = false;

		Piece *tempPiece = m_game->returnPiece(i);

		if (pieceMapped == false)
		{
			Pawn *pawn = dynamic_cast <Pawn*> (tempPiece);
			if (pawn != nullptr)
			{
				if (pawn->getColour() == true)
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_PAWN);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(pawn, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
				else
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_PAWN);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(pawn, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
			}
		}

		if (pieceMapped == false)
		{
			King *king = dynamic_cast <King*> (tempPiece);
			if (king != nullptr)
			{
				if (king->getColour() == true)
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_KING);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(king, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
				else
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_KING);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(king, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
			}
		}

		if (pieceMapped == false)
		{
			Queen *queen = dynamic_cast <Queen*> (tempPiece);
			if (queen != nullptr)
			{
				if (queen->getColour() == true)
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_QUEEN);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(queen, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
				else
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_QUEEN);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(queen, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
			}
		}

		if (pieceMapped == false)
		{
			Knight *knight = dynamic_cast <Knight*> (tempPiece);
			if (knight != nullptr)
			{
				if (knight->getColour() == true)
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_KNIGHT);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(knight, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
				else
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_KNIGHT);
					m_pieceMap.insert(std::pair < Piece*, CBitmap*>(knight, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
			}
		}

		if (pieceMapped == false)
		{
			Bishop *bishop = dynamic_cast <Bishop*> (tempPiece);
			if (bishop != nullptr)
			{
				if (bishop->getColour() == true)
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_BISHOP);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(bishop, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
				else
				{
					m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_BISHOP);
					m_pieceMap.insert(std::pair<Piece*, CBitmap*>(bishop, &m_piecesBitmaps[i]));
					pieceMapped = true;
				}
			}
		}

		if (pieceMapped == false)
		{
			Rook *rook = dynamic_cast <Rook*> (tempPiece);
			if (rook->getColour() == true)
			{
				m_piecesBitmaps[i].LoadBitmap(IDB_WHITE_ROOK);
				m_pieceMap.insert(std::pair<Piece*, CBitmap*>(rook, &m_piecesBitmaps[i]));
				pieceMapped = true;
			}
			else
			{
				m_piecesBitmaps[i].LoadBitmap(IDB_BLACK_ROOK);
				m_pieceMap.insert(std::pair<Piece*, CBitmap*>(rook, &m_piecesBitmaps[i]));
				pieceMapped = true;
			}
		}
	}
}

CChessUIDoc::~CChessUIDoc()
{
}

BOOL CChessUIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CChessUIDoc serialization

void CChessUIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CChessUIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CChessUIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CChessUIDoc::SetSearchContent(const CString& value)
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

// CChessUIDoc diagnostics

#ifdef _DEBUG
void CChessUIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChessUIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CChessUIDoc commands

// My funtions

Game* CChessUIDoc::returnGame()
{
	return m_game;
}

std::map<Piece*, CBitmap*> CChessUIDoc::retunMap()
{
	return m_pieceMap;
}
