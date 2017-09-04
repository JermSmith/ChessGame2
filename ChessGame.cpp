#pragma once
#include "ChessGame.h"

#include "BoardData.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

CBoard board;

CGame::CGame()
{
	return;
}

sf::Sprite* CGame::PassAlongBoardSprite(int file, int rank)
{
	BoardTileSprite = board.getBoardSprite(file, rank);
	ptrBoardTileSprite = &BoardTileSprite;
	return ptrBoardTileSprite;
}

sf::Sprite* CGame::PassAlongPieceSprite(int file, int rank)
{
	PieceSprite = board.getPieceSprite(file, rank);
	ptrPieceSprite = &PieceSprite;
	return ptrPieceSprite;
}

void CGame::LeftClick(sf::Event event)
{
	std::pair<int, int> newClick = std::make_pair(static_cast<int>(floor(event.mouseButton.x / PIX_MPL)), \
		7 - static_cast<int>(floor(event.mouseButton.y / PIX_MPL))); // get file & rank from x- and y-location of click
	bool bOffBoard = bClickOffBoard(newClick); // leave the LeftClick function early, if click was off of board
	if (bOffBoard) { return; }

	CPiece *oldPiece;
	CPiece *newPiece;
	
	// assign oldPiece to an object of correct type for the piece
	switch (board.getPieceType(oldClick.first, oldClick.second))
	{
	case EPiece::pawn:
	{
		CPawn tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	case EPiece::rook:
	{
		CRook tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	case EPiece::knight:
	{
		CKnight tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	case EPiece::bishop:
	{
		CBishop tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	case EPiece::queen:
	{
		CQueen tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	case EPiece::king:
	{
		CKing tempObj(board.getTeamColour(oldClick.first, oldClick.second));
		oldPiece = &tempObj;
		break;
	}
	default: // accounts for empty
		CPiece tempObj;
		oldPiece = &tempObj;
		break;
	}

	// assign newPiece to an object of correct type for the piece
	switch (board.getPieceType(newClick.first, newClick.second))
	{
	case EPiece::pawn:
	{
		CPawn tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	case EPiece::rook:
	{
		CRook tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	case EPiece::knight:
	{
		CKnight tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	case EPiece::bishop:
	{
		CBishop tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	case EPiece::queen:
	{
		CQueen tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	case EPiece::king:
	{
		CKing tempObj(board.getTeamColour(newClick.first, newClick.second));
		newPiece = &tempObj;
		break;
	}
	default:
		CPiece tempObj;
		newPiece = &tempObj;
		break;
	}

	oldPiece->SetPosition(oldClick.first, oldClick.second);
	newPiece->SetPosition(newClick.first, newClick.second);

	oldPiece->calcDestinations(&board);
	newPiece->calcDestinations(&board);

	if (bIsDestination(newPiece->GetPosition())) // clicked on a valid destination, based on DestList
	{
		board.highlightOff(oldPiece->GetPosition(), oldPiece->GetDestinations());

		board.movePiece(oldPiece->GetPosition(), newPiece->GetPosition());

		DestList = {};

		checkPawnPromotion();

		switchTeam();
	}

	// first click was NOT ON our team, second click was ON our team
	else if ((oldPiece->GetColour() != currentTeam) && (newPiece->GetColour() == currentTeam))
	{
		if (bCheckForPin(newPiece->GetPosition())) { DestList = {std::make_pair(0,0)}; }
		else { DestList = newPiece->GetDestinations(); }
		board.highlightOn(newPiece->GetPosition(), DestList);
	}
	
	// first click was ON our team, second click was NOT ON our team (also not a destination, since checked earlier)
	else if ((oldPiece->GetColour() == currentTeam) && (newPiece->GetColour() != currentTeam))
	{
		board.highlightOff(oldPiece->GetPosition(), DestList);
		DestList = {};
	}
	
	// first click was ON our team, second click was ON our team (could be same piece or different)
	else if ((oldPiece->GetColour() == currentTeam) && (newPiece->GetColour() == currentTeam))
	{
		if (oldPiece->GetPosition() == newPiece->GetPosition()) //clicked on same piece twice in a row
		{
			// update DestList, depending if it is populated or not
			if (DestList == std::vector<std::pair<int, int>> {}) // if CGame's list of destinations is empty...
			{
				// then populate it with destinations for the click provided
				if (bCheckForPin(newPiece->GetPosition())) { DestList = {std::make_pair(0,0)}; }
				else { DestList = newPiece->GetDestinations(); }
				board.highlightToggle(newPiece->GetPosition(), DestList);
			}
			else // CGame's list of destinations already has some destinations in it
			{
				board.highlightToggle(newPiece->GetPosition(), DestList);
				DestList = std::vector<std::pair<int, int>> {};
			}
		}

		else // must have clicked a new piece of our team's colour
		{
			board.highlightOff(oldPiece->GetPosition(), DestList);

			if (bCheckForPin(newPiece->GetPosition())) { DestList = {std::make_pair(0,0)}; }
			else { DestList = newPiece->GetDestinations(); }

			board.highlightOn(newPiece->GetPosition(), DestList);
		}

	}
	
	oldClick = newClick; // newClick is set anew at the start of the function
	return;
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
				board.highlightOff(std::make_pair(File, Rank), {}); // set colour of all spaces to white
			}
		}
	}
	return bClickOffBoard;
}

bool CGame::bIsDestination(std::pair<int, int> click)
{
	bool IsDestination = false;
	// returns true if the inputted position (click) matches any of the destinations in the private property (DestList).
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

bool CGame::bCheckForPin(std::pair<int, int> position)
{
	bool bIsPin = false;

	Kdir = std::make_pair(0, 0); // reset to (0,0) each time bCheckForPin is called

	std::vector<std::pair<int, int>> dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) }; // directions to check for king from piece in question

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		std::pair<int, int> newPos = position; // set newPos to be position of piece in question, before moving along a line
		while ((newPos.first + dir[i_].first) >= 0 && (newPos.first + dir[i_].first <= 7) && \
			(newPos.second + dir[i_].second >= 0) && (newPos.second + dir[i_].second <= 7))
		{
			if (board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::king && \
				board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == \
				board.getTeamColour(position.first, position.second)) // the king of same colour is facing the piece at "position"
			{
				Kpos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
				Kdir = std::make_pair(dir[i_].first * -1, dir[i_].second * -1);
				// ^^ opposite direction than the one moved along from the piece to the king -- Kdir is the direction from
				// the king to the piece. It will be iterated along, starting at the piece in question, to see if the
				// order of pieces in a line is KING -> PIECE IN QUESTION -> PINNING PIECE (i.e. queen, bishop or rook)
				break; // exit the while loop early (moving to each square in a straight line from the piece)
			}
			else if (board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EPiece::empty)
			{
				// space being inspected is occupied by a piece (but not the king of same colour), so no pin can happen in this line
				break; // exit while loop
			}
			else // king is not in the space currently being inspected
			{
				// set newPos to be offset from the previous newPos by the step indicated in "dir"
				newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
			}
		}
		if (Kdir.first != 0 && Kdir.second != 0) { break; }
		// king has been found -- exit the for loop early (going through each possible direction from the piece)
	}

	if (Kdir.first == 0 && Kdir.second == 0) // Kdir unchanged -- no valid direction found for facing king
	{
		bIsPin = false; // the piece in question is not facing the king, so cannot be pinned
	}
	else // the king is facing the piece in question - may be a pin
	{
		std::pair<int, int> newPos = position; // set newPos to be position of piece, before moving along line defined by Kdir
		while ((newPos.first + Kdir.first) >= 0 && (newPos.first + Kdir.first <= 7) && \
			(newPos.second + Kdir.second >= 0) && (newPos.second + Kdir.second <= 7))
		{
			if (board.getTeamColour(newPos.first + Kdir.first, newPos.second + Kdir.second) != \
				board.getTeamColour(position.first, position.second) && \
					board.getTeamColour(newPos.first + Kdir.first, newPos.second + Kdir.second) != EColour::empty)
				// hit a piece of the other team -- now check what type
			{
				if (board.getPieceType(newPos.first + Kdir.first, newPos.second + Kdir.second) == EPiece::queen)
				{
					bIsPin = true; // queen is pinning piece to king
					break; // exit the while loop
				}
				else if (board.getPieceType(newPos.first + Kdir.first, newPos.second + Kdir.second) == EPiece::bishop && \
					abs(Kdir.first) + abs(Kdir.second) == 2) // diagonal direction, so bishop can pin
				{
					bIsPin = true; // bishop is pinning piece to king
					break; // exit the while loop
				}
				else if (board.getPieceType(newPos.first + Kdir.first, newPos.second + Kdir.second) == EPiece::rook && \
					abs(Kdir.first) + abs(Kdir.second) == 1) // orthogonal direction, so rook can pin
				{
					bIsPin = true; // rook is pinning piece to king
					break; // exit the while loop
				}
				else // the other team's piece does not apply a pin, but is in line with the piece in question & king
				{
					bIsPin = false;
					break;
				}
			}
			else if (board.getTeamColour(newPos.first + Kdir.first, newPos.second + Kdir.second) == \
				board.getTeamColour(position.first, position.second)) // hit a piece of same colour, so no pin
			{
				bIsPin = false;
				break; // exit the while loop
			}
			else // hit an empty square, so proceed to check the next square along the line defined by Kdir
			{
				newPos = std::make_pair(newPos.first + Kdir.first, newPos.second + Kdir.second);
			}
		}
	}
	return bIsPin;
}

std::vector<std::pair<int, int>> CGame::getPinDestList()
{
	std::vector<std::pair<int, int>> pinDestList = {};



	return pinDestList;
}

// switches the team whose turn it is to move
void CGame::switchTeam()
{
	if (currentTeam == EColour::white) { currentTeam = EColour::black; }
	else { currentTeam = EColour::white; }
	return;
}

void CGame::checkPawnPromotion()
{
	int lastRank; // maps white -> 7, black -> 0
	if (currentTeam == EColour::white) { lastRank = 7; }
	else { lastRank = 0; }

	for (unsigned int file = 0; file <= 7; file++)
	{
		if (board.getPieceType(file, lastRank) == EPiece::pawn)
		{
			board.setPieceType(file, lastRank, EPiece::queen);
			board.resetPieceSprite(file, lastRank);
			break;
		}
	}
}

