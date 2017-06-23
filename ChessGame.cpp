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
	ptrBoardData = &BoardData[file][rank];
	return ptrBoardData;
}

sf::Sprite* CGame::GetBoardTileSpr()
{	
	ptrBoardTileSpr = &BoardTileSpr;
	return ptrBoardTileSpr; 
}

void CGame::LeftClick(sf::Event event)
{
	int file = static_cast<int>(floor(event.mouseButton.x / PIX_MPL)); // get file from x-location of click
	int rank = 7 - static_cast<int>(floor(event.mouseButton.y / PIX_MPL)); // get rank from y-location of click

	// leave the LeftClick function early, if click was off of board, or on a blank spot
	if ((file < 0 || file > 7 || rank < 0 || rank > 7) || (BoardData[PrevCoord.first][PrevCoord.second].GetPieceType() == EPiece::empty))
	{
		for (int File = 0; File <= 7; File++)
		{
			for (int Rank = 0; Rank <= 7; Rank++)
			{
				BoardData[File][Rank].GetSprite()->setColor(sf::Color(255, 255, 255)); // set colour of all spaces to white
			}
		}
		PrevCoord.first = 0;
		PrevCoord.second = 0;
	return;
	}

	std::vector<std::pair<int, int>> CurrDest = BoardData[file][rank].GetValidDestinations();
	std::vector<std::pair<int, int>> PrevDest = BoardData[PrevCoord.first][PrevCoord.second].GetValidDestinations();

	// bool destFound = false;
	// loop through previous destinations
	//		if found, set destFound = true;
	//		move the piece from original spot to new spot
	//		set old spot to empty
	//		break loop;
	// if (!destFound) {
	//		if clicked same space again {
	//			set colour of space to white
	//			set colour of dest's to white
	//

	if ((file == PrevCoord.first) && (rank == PrevCoord.second)) // clicked the same space again
	{
		BoardData[file][rank].GetSprite()->setColor(sf::Color(255, 255, 255)); // set colour of clicked space to white
		for (unsigned int dnum = 0; dnum < CurrDest.size(); dnum++)
		{
			BoardData[CurrDest[dnum].first][CurrDest[dnum].second].GetSprite()->setColor(sf::Color(255, 255, 255)); // set colour of dest's to white
		}
		PrevCoord.first = 0;
		PrevCoord.second = 0; // these can never be clicked, so 3 consecutive clicks on a space will work
	}
	else // clicked a space that was not the previously-clicked space
	{
		bool DestFound = false;
		for (unsigned int dnum1 = 0; dnum1 < PrevDest.size(); dnum1++) // check all dest's from prev space for current click
		{
			if ((file == PrevDest[dnum1].first) && (rank == PrevDest[dnum1].second)) // clicked a valid destination
			{
				DestFound = true;
				BoardData[file][rank] = BoardData[PrevCoord.first][PrevCoord.second]; // clicked spot obtains piece from previous clicked spot
				BoardData[PrevCoord.first][PrevCoord.second].SetPieceType(EPiece::empty);
				EPiece newspot = BoardData[file][rank].GetPieceType();
				EPiece oldspot = BoardData[PrevCoord.first][PrevCoord.second].GetPieceType();
				for (unsigned int dnum2 = 0; dnum2 < PrevDest.size(); dnum2++)
				{
					BoardData[PrevDest[dnum2].first][PrevDest[dnum2].second]; // colour all previous destinations white
				}
				break;
			}
		}
		if (!DestFound)
		{
			// did not click same square, and clicked a non-destination space
			BoardData[PrevCoord.first][PrevCoord.second].GetSprite()->setColor(sf::Color(255, 255, 255)); // prev clicked space set white
			for (unsigned int dnum3 = 0; dnum3 < CurrDest.size(); dnum3++)
			{
				BoardData[PrevDest[dnum3].first][PrevDest[dnum3].second].GetSprite()->setColor(sf::Color(255, 255, 255)); // prev dest's white
			}

			if (BoardData[file][rank].GetPieceType() != EPiece::empty) // did not click an empty space (clicked space has a piece)
			{
				BoardData[file][rank].GetSprite()->setColor(sf::Color(255, 255, 0)); // new clicked space set yellow
				for (unsigned int dnum4 = 0; dnum4 < CurrDest.size(); dnum4++)
				{
					BoardData[CurrDest[dnum4].first][CurrDest[dnum4].second].GetSprite()->setColor(sf::Color(170, 100, 240)); // new destinations purple
				}
			}
			// else, clicked an empty, non-destination space
		}
		PrevCoord.first = file;
		PrevCoord.second = rank;
	}
	return;
}



