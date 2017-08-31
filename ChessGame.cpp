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
	default:
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

	oldPiece->calcDestinations();
	newPiece->calcDestinations();

	// NOT YET TROUBLESHOOTED
	if (bIsDestination(newPiece->GetPosition())) // clicked on a valid destination
	{
		board.highlightOff(oldPiece->GetPosition(), oldPiece->GetDestinations());

		DestList = {};
		switchTeam();
	}

	// first click was NOT ON our team, second click was ON our team
	else if ((oldPiece->GetColour() != currentTeam) && (newPiece->GetColour() == currentTeam))
	{
		DestList = newPiece->GetDestinations();
		board.highlightOn(newPiece->GetPosition(), newPiece->GetDestinations());
	}
	
	// first click was ON our team, second click was NOT ON our team (also not a destination, since checked earlier)
	else if ((oldPiece->GetColour() == currentTeam) && (newPiece->GetColour() != currentTeam))
	{
		DestList = {};
		board.highlightOff(oldPiece->GetPosition(), oldPiece->GetDestinations());
	}
	
	// first click was ON our team, second click was ON our team (could be same piece or different)
	else if ((oldPiece->GetColour() == currentTeam) && (newPiece->GetColour() == currentTeam))
	{
		if (oldClick == newClick) //clicked on same piece twice in a row
		{
			// update DestList, depending if it is populated or not
			if (DestList == std::vector<std::pair<int, int>> {}) // if CGame's list of destinations is empty...
			{
				// then populate it with destinations for the click provided
				DestList = newPiece->GetDestinations(); // destinations should have already been calculated for click
			}
			else // CGame's list of destinations already has some destinations in it
			{
				DestList = std::vector<std::pair<int, int>> {};
			}

			board.highlightToggle(newPiece->GetPosition(), newPiece->GetDestinations());
		}

		else // must have clicked a new piece of our team's colour
		{
			DestList = newPiece->GetDestinations();
			board.highlightOff(oldPiece->GetPosition(), oldPiece->GetDestinations());
			board.highlightOn(newPiece->GetPosition(), newPiece->GetDestinations());
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

// switches the team whose turn it is to move
void CGame::switchTeam()
{
	if (currentTeam == EColour::white) { currentTeam = EColour::black; }
	else { currentTeam = EColour::white; }
	return;
}