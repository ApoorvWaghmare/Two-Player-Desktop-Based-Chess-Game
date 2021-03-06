
// ChessUIDoc.h : interface of the CChessUIDoc class
//
#include "ChessLib.h"
#include <iostream>
#include <map>

using namespace std;

#pragma once


class CChessUIDoc : public CDocument
{
//My declarations
private:
	Game *m_game = new Game;
	std::map <Piece*, CBitmap*> m_pieceMap;
	CBitmap m_piecesBitmaps[32];

//My fucntions
public:
	Game* returnGame();
	std::map <Piece*, CBitmap*> retunMap();
	
public: // create from serialization only
	CChessUIDoc();
	DECLARE_DYNCREATE(CChessUIDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CChessUIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
