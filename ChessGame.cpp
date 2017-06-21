#pragma once
#include "ChessGame.h"

CGame::CGame() { Reset(); return; }

void CGame::Reset()
{
	// Board Setup & Piece Creation

	CRook Rook1W, Rook2W, Rook1B, Rook2B;
	CKnight Knight1W, Knight2W, Knight1B, Knight2B;
	CBishop Bishop1W, Bishop2W, Bishop1B, Bishop2B;
	CQueen Queen1W, Queen1B;
	CKing King1W, King1B;
	CPawn Pawn1W, Pawn2W, Pawn3W, Pawn4W, Pawn5W, Pawn6W, Pawn7W, Pawn8W, \
		Pawn1B, Pawn2B, Pawn3B, Pawn4B, Pawn5B, Pawn6B, Pawn7B, Pawn8B;

	//vector of vectors for positions on board, where each position is an object of type Piece
	BoardData.resize(8, std::vector<CPiece>(8));

	BoardData[to_int(EFile::FileA)][to_int(ERank::Rank1)] = Rook1W;		// A1, white rook
	BoardData[to_int(EFile::FileB)][to_int(ERank::Rank1)] = Knight1W;	// B1, white knight
	BoardData[to_int(EFile::FileC)][to_int(ERank::Rank1)] = Bishop1W;	// C1, white bishop
	BoardData[to_int(EFile::FileD)][to_int(ERank::Rank1)] = Queen1W;	// D1, white queen
	BoardData[to_int(EFile::FileE)][to_int(ERank::Rank1)] = King1W;		// E1, white king
	BoardData[to_int(EFile::FileF)][to_int(ERank::Rank1)] = Bishop2W;	// F1, white bishop
	BoardData[to_int(EFile::FileG)][to_int(ERank::Rank1)] = Knight2W;	// G1, white knight
	BoardData[to_int(EFile::FileH)][to_int(ERank::Rank1)] = Rook2W;		// H1, white rook
	BoardData[to_int(EFile::FileA)][to_int(ERank::Rank2)] = Pawn1W;		// A2, white pawn
	BoardData[to_int(EFile::FileB)][to_int(ERank::Rank2)] = Pawn2W;		// B2, white pawn
	BoardData[to_int(EFile::FileC)][to_int(ERank::Rank2)] = Pawn3W;		// C2, white pawn
	BoardData[to_int(EFile::FileD)][to_int(ERank::Rank2)] = Pawn4W;		// D2, white pawn
	BoardData[to_int(EFile::FileE)][to_int(ERank::Rank2)] = Pawn5W;		// E2, white pawn
	BoardData[to_int(EFile::FileF)][to_int(ERank::Rank2)] = Pawn6W;		// F2, white pawn
	BoardData[to_int(EFile::FileG)][to_int(ERank::Rank2)] = Pawn7W;		// G2, white pawn
	BoardData[to_int(EFile::FileH)][to_int(ERank::Rank2)] = Pawn8W;		// H2, white pawn

	BoardData[to_int(EFile::FileA)][to_int(ERank::Rank8)] = Rook1B;		// A8, black rook
	BoardData[to_int(EFile::FileB)][to_int(ERank::Rank8)] = Knight1B;	// B8, black knight
	BoardData[to_int(EFile::FileC)][to_int(ERank::Rank8)] = Bishop1B;	// C8, black bishop
	BoardData[to_int(EFile::FileD)][to_int(ERank::Rank8)] = Queen1B;	// D8, black queen
	BoardData[to_int(EFile::FileE)][to_int(ERank::Rank8)] = King1B;		// E8, black king
	BoardData[to_int(EFile::FileF)][to_int(ERank::Rank8)] = Bishop2B;	// F8, black bishop
	BoardData[to_int(EFile::FileG)][to_int(ERank::Rank8)] = Knight2B;	// G8, black knight
	BoardData[to_int(EFile::FileH)][to_int(ERank::Rank8)] = Rook2B;		// H8, black rook
	BoardData[to_int(EFile::FileA)][to_int(ERank::Rank7)] = Pawn1B;		// A7, black pawn
	BoardData[to_int(EFile::FileB)][to_int(ERank::Rank7)] = Pawn2B;		// B7, black pawn
	BoardData[to_int(EFile::FileC)][to_int(ERank::Rank7)] = Pawn3B;		// C7, black pawn
	BoardData[to_int(EFile::FileD)][to_int(ERank::Rank7)] = Pawn4B;		// D7, black pawn
	BoardData[to_int(EFile::FileE)][to_int(ERank::Rank7)] = Pawn5B;		// E7, black pawn
	BoardData[to_int(EFile::FileF)][to_int(ERank::Rank7)] = Pawn6B;		// F7, black pawn
	BoardData[to_int(EFile::FileG)][to_int(ERank::Rank7)] = Pawn7B;		// G7, black pawn
	BoardData[to_int(EFile::FileH)][to_int(ERank::Rank7)] = Pawn8B;		// H7, black pawn

	// A1 through H2
	for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file += 1)
	{
		for (int rank = to_int(ERank::Rank1); rank <= to_int(ERank::Rank2); rank += 1)
		{
			BoardData[file][rank].SetColour(EColour::white);
		}
	}
	// A3 through H6
	for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file += 1)
	{
		for (int rank = to_int(ERank::Rank3); rank <= to_int(ERank::Rank6); rank += 1)
		{
			BoardData[file][rank].SetColour(EColour::empty);	// A3 thru H6, empty
			BoardData[file][rank].SetPieceType(EPiece::empty);	// A3 thru H6, empty
		}
	}
	// A7 through H8
	for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file += 1)
	{
		for (int rank = to_int(ERank::Rank7); rank <= to_int(ERank::Rank8); rank += 1)
		{
			BoardData[file][rank].SetColour(EColour::black);
		}
	}

	//--------------------// Background Texture & Sprites
	BoardTexture.loadFromFile("board_tiles.png");
	BoardTexture.setRepeated(true);
	BoardTileSpr.setTexture(BoardTexture);
	sf::IntRect BoardRectangle(0, 0, PIX_MPL * 8, PIX_MPL * 8);
	BoardTileSpr.setTextureRect(BoardRectangle);
	// --------------------//

	// --------------------// Texture for pieces
	PiecesTexture.loadFromFile("pieces_tiled.png");
	// set the 
	for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file++)
	{
		for (int rank = to_int(ERank::Rank1); rank <= to_int(ERank::Rank8); rank++)
		{
			BoardData[file][rank].GetSprite()->setTexture(PiecesTexture);

			BoardData[file][rank].GetSprite()->setTextureRect(sf::IntRect(PIX_MPL*to_int(BoardData[file][rank].GetPieceType()), \
				PIX_MPL*to_int(BoardData[file][rank].GetColour()), PIX_MPL, PIX_MPL));

			BoardData[file][rank].GetSprite()->setPosition(static_cast<float>(PIX_MPL*file), static_cast<float>(PIX_MPL*(7 - rank)));
		}
	}
	// --------------------//

	return;
}

CPiece* CGame::GetBoardData(int file, int rank)
{
	PointerToBoardData = &BoardData[file][rank];
	return PointerToBoardData;
}

sf::Sprite* CGame::GetBoardTileSpr()
{	
	PointerToBoardTileSpr = &BoardTileSpr;
	return PointerToBoardTileSpr; 
}




