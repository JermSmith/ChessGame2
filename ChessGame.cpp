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

sf::Sprite *CGame::GetBoardDataSprite(int file, int rank)
{
	ptrBoardDataSpr = BoardData[file][rank].GetSprite();
	return ptrBoardDataSpr;
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
	std::pair<int, int> newClick = std::make_pair(static_cast<int>(floor(event.mouseButton.x / PIX_MPL)), \
		7 - static_cast<int>(floor(event.mouseButton.y / PIX_MPL))); // get file & rank from x- and y-location of click

	// leave the LeftClick function early, if click was off of board
	bool bOffBoard = bClickOffBoard(newClick);
	if (bOffBoard) {
		return;
	}
	
	// NOT YET TROUBLESHOOTED
	if (bIsDestination(newClick)) // clicked on a valid destination (also accounts for castling)
	{
		PieceAt(oldClick)->highlightOff();
		for (unsigned int dest = 0; dest < DestList.size(); dest++)
		{
			PieceAt(std::make_pair(DestList[dest].first, DestList[dest].second))->highlightOff();
		}
		MoveFromTo(oldClick, newClick);
		oldClick = { std::make_pair(0,4) };
		newClick = { std::make_pair(0,5) };
		DestList = {};
		switchTeam();
	}

	//VALIDATED
	// first click was NOT ON our team, second click was ON our team
	else if ((PieceAt(oldClick)->GetColour() != currentTeam) && (PieceAt(newClick)->GetColour() == currentTeam))
	{
		PieceAt(newClick)->calcDestinations();
		DestList = PieceAt(newClick)->GetDestinations();

		//PieceAndDestHighlightOn(newClick);
			PieceAt(newClick)->highlightOnP();
			//DestinationHighlightMatch(newClick);
			DestinationHighlightOn(newClick);
	}

	//VALIDATED
	// first click was ON our team, second click was NOT ON our team (also not a destination, since checked earlier)
	else if ((PieceAt(oldClick)->GetColour() == currentTeam) && (PieceAt(newClick)->GetColour() != currentTeam))
	{
		DestList = {};

		//PieceAndDestHighlightOff(oldClick);
			PieceAt(oldClick)->highlightOff();
			//DestinationHighlightMatch(oldClick);
			DestinationHighlightOff(oldClick);
	}

	//VALIDATED
	// first click was ON our team, second click was ON our team (could be same piece or different)
	else if ((PieceAt(oldClick)->GetColour() == currentTeam) && (PieceAt(newClick)->GetColour() == currentTeam))
	{

		//VALIDATED
		if (oldClick == newClick) //clicked on same piece twice in a row
		{
			DestListToggle(newClick); //updates DestList. Kind of want this line to be "DestList = DestListToggle(newClick);" ...

			//PieceAndDestHighlightToggle(newClick);
				PieceAt(newClick)->highlightToggle();
				DestinationHighlightMatch(newClick); //matches highlight states of destinations to newClick, after its highlight is toggled
		}

		//VALIDATED
		else // must have clicked a new piece of our team's colour
		{
			PieceAt(newClick)->calcDestinations();
			// overwrite CGame's list of destinations with that of the most recent click
			DestList = BoardData[newClick.first][newClick.second].GetDestinations();

			//PieceAndDestHighlightOff(oldClick);
				PieceAt(oldClick)->highlightOff();

			//PieceAndDestHighlightOn(newClick);
				PieceAt(newClick)->highlightOnP();
				DestinationHighlightMatch(newClick);
		}

	}
	oldClick = newClick;
	
	return;
}

//VALIDATED
CPiece *CGame::PieceAt(std::pair<int, int> click)
{
	return &BoardData[click.first][click.second];
}

bool CGame::bClickOffBoard(std::pair<int, int> click)
{
	bool bClickOffBoard = false;
	if (click.first < 0 || click.first > 7 || click.second < 0 || click.second > 7)
	{
		bClickOffBoard = true;
		for (int File = 0; File <= 7; File++)
		{
			for (int Rank = 0; Rank <= 7; Rank++)
			{
				PieceAt(std::make_pair(File, Rank))->GetSprite()->setColor(sf::Color(255, 255, 255)); // set colour of all spaces to white
			}
		}
	}
	return bClickOffBoard;
}

bool CGame::bIsDestination(std::pair<int, int> click)
{
	bool IsDestination = false;
	// returns true if the inputted click matches any of the destinations in the private property, DestList.
	for (unsigned int dest = 0; dest < DestList.size(); dest++)
	{
		if (click.first == DestList[dest].first && click.second == DestList[dest].second)
		{
			IsDestination = true;
			break;
		}
	}
	return IsDestination;
}

// loops through all destinations of piece at location "click" and highlights them
void CGame::DestinationHighlightOn(std::pair<int, int> click)
{
	for (unsigned int dest = 0; dest < PieceAt(click)->GetDestinations().size(); dest++)
	{
		PieceAt(std::make_pair(PieceAt(click)->GetDestinations()[dest].first, PieceAt(click)->GetDestinations()[dest].second))->highlightOnY();
	}
	return;
}

// loops through all destinations of piece at location "click" and turns off highlight
void CGame::DestinationHighlightOff(std::pair<int, int> click)
{
	for (unsigned int dest = 0; dest < PieceAt(click)->GetDestinations().size(); dest++)
	{
		PieceAt(std::make_pair(PieceAt(click)->GetDestinations()[dest].first, PieceAt(click)->GetDestinations()[dest].second))->highlightOff();
	}
	return;
}

// matches destination highlight states to that of clicked piece at instant function is called
void CGame::DestinationHighlightMatch(std::pair<int, int> click)
{
	if (PieceAt(click)->GetSprite()->getColor() == sf::Color(255, 255, 255)) { DestinationHighlightOff(click); }
	else { DestinationHighlightOn(click); }
	return;
}

// places a copy of the original piece in the new location, and destroys the original piece.
void CGame::MoveFromTo(std::pair<int, int> olddClick, std::pair<int, int> newClick)
{
	//PieceAt(newClick) = PieceAt(oldClick);
	//BoardData[newClick.first][newClick.second].SetSprite(BoardData[oldClick.first][oldClick.second].GetSprite());
	//BoardData[newClick.first][newClick.second].SetSprite(BoardData[0][3].GetSprite());
	//BoardData[olddClick.first].erase(BoardData[olddClick.first].begin() + olddClick.second);

	//BoardData[olddClick.first].emplace(BoardData[olddClick.first].begin() + olddClick.second);

	return;
}

//VALIDATED
void CGame::DestListToggle(std::pair<int, int> click)
{
	if (DestList == std::vector<std::pair<int, int>> {}) // if CGame's list of destinations is empty
	{
		// then populate it with destinations for the click provided
		PieceAt(click)->calcDestinations(); //perhaps not necessary, but doesn't hurt...
		DestList = PieceAt(click)->GetDestinations(); // destinations should have already been calculated for click
	}
	else // CGame's list of destinations already has some destinations in it
	{
		DestList = std::vector<std::pair<int, int>> {};
	}
	return;
}

// switches the team whose turn it is to move
void CGame::switchTeam()
{
	if (currentTeam == EColour::white) { currentTeam = EColour::black; }
	else { currentTeam = EColour::white; }
	return;
}

