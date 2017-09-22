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
		bool bIsCheck = false;
		std::vector<std::pair<int, int>> BlockCheckSpots = {};
		std::vector<std::pair<int, int>> PreCheckDestList = {};
		
		std::pair<int, int> kingLocation = findKingLocation(currentTeam);

		bIsCheck = bCheckIfCheck(kingLocation);
		
		if (bIsCheck == true) // game says king is in check, when this is not true. must investigate.
		{
			BlockCheckSpots = GetBlockCheckSpots(kingLocation);
			
			if (newPiece->GetPieceType() != EPiece::king)
			{
				PreCheckDestList = GetDestListCheckingForPin(newPiece);
				for (unsigned int i_ = 0; i_ < PreCheckDestList.size(); i_++)
				{
					for (unsigned int j_ = 0; j_ < BlockCheckSpots.size(); j_++)
					{
						if (PreCheckDestList[i_] == BlockCheckSpots[j_])
						{
							DestList.push_back(BlockCheckSpots[j_]);
						}
					}
				}
			}
			else // newPiece is a king, which is in check. need to get valid destinations for the king.
			{
				PreCheckDestList = GetDestListCheckingForPin(newPiece); // between 0 and 8 (otherwise) valid dests for the king
				for (unsigned int i_ = 0; i_ < PreCheckDestList.size(); i_++)
				{
					if (bCheckIfCheck(PreCheckDestList[i_]) == false) // ***need to remove the stop if it hits king of same colour
					{
						DestList.push_back(PreCheckDestList[i_]);
						int a1 = 1;
					}
				}
			}
		}
		else
		{
			DestList = GetDestListCheckingForPin(newPiece);
			board.highlightOn(newPiece->GetPosition(), DestList);
		}
		/*
		////
		ALSO, TO GO AT BOTTOM OF LEFT CLICK FUNCTION:
		BlockCheckSpots = GetBlockCheckSpots(kingLocation);
		CheckForCheckmate(kingLocation, BlockCheckSpots);
		--^^[[if king has no valid destinations && for each piece_, GetDestListCheckingForPiece(piece_)[i_] != BlockCheckSpots[j_], then checkmate.]]
		*/

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
			if (DestList.size() == 0) // if CGame's list of destinations is empty...
			{
				// then populate it with destinations for the click provided
				DestList = GetDestListCheckingForPin(newPiece);

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

			DestList = GetDestListCheckingForPin(newPiece);

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

std::pair<int, int> CGame::findKingLocation(EColour colour)
{
	std::pair<int, int> kingLocation = std::make_pair(0, 0);
	
	for (unsigned int file = 0; file <= 7; file++)
	{
		for (unsigned int rank = 0; rank <= 7; rank++)
		{
			if (board.getPieceType(file, rank) == EPiece::king && board.getTeamColour(file, rank) == colour)
			{
				kingLocation = std::make_pair(file, rank);
				return kingLocation;
			}
		}
	}
	return kingLocation; // never happens, because it is always returned earlier
}

bool CGame::bCheckIfCheck(std::pair<int, int> kingPos)
{
	bool bIsCheck = false;
	std::vector<std::pair<int, int>> dir;
	EColour kingColour = board.getTeamColour(kingPos.first, kingPos.second);

	// first check if there is a pawn imposing check
	int pawnForwardDir = to_int(kingColour)*2 - 1; //maps white->(-1), black->(1), since on white's turn black pawns are moving

	if ((kingPos.first + 1 <= 7) && \
		(kingPos.second - pawnForwardDir >= 0) && (kingPos.second - pawnForwardDir <= 7))
	{
		if ((board.getPieceType(kingPos.first + 1, kingPos.second - pawnForwardDir) == EPiece::pawn) && \
			(board.getTeamColour(kingPos.first + 1, kingPos.second - pawnForwardDir) != kingColour))
			// don't need to check for EColour::empty, because EPiece::pawn will be either black or white
		{
			bIsCheck = true;
			return bIsCheck;
		}
	}
	if ((kingPos.first - 1 >= 0) && \
		(kingPos.second - pawnForwardDir >= 0) && (kingPos.second - pawnForwardDir <= 7))
	{
		if ((board.getPieceType(kingPos.first - 1, kingPos.second - pawnForwardDir) == EPiece::pawn) && \
			(board.getTeamColour(kingPos.first - 1, kingPos.second - pawnForwardDir) != kingColour))
			// don't need to check for EColour::empty, because EPiece::pawn will be either black or white
		{
			bIsCheck = true;
			return bIsCheck;
		}
	}

	// now check for knights imposing check
	dir = { std::make_pair(-1, -2), std::make_pair(-2, -1), \
		std::make_pair(-2, 1), std::make_pair(-1, 2), std::make_pair(1, 2), std::make_pair(2, 1), \
		std::make_pair(2, -1), std::make_pair(1, -2) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		if ((kingPos.first + dir[i_].first) >= 0 && (kingPos.first + dir[i_].first <= 7) && \
			(kingPos.second + dir[i_].second >= 0) && (kingPos.second + dir[i_].second <= 7))
			if ((board.getPieceType(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second) == EPiece::knight) && \
				(board.getTeamColour(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second) != kingColour))
				// don't need to check for EColour::empty, because EPiece::knight will be either black or white
			{
				bIsCheck = true;
				return bIsCheck;
			}
	}

	// now check for queens, rooks or bishops imposing check
	dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) };
	
	std::pair<int, int> newPos;

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		newPos = kingPos;
		while ((newPos.first + dir[i_].first) >= 0 && (newPos.first + dir[i_].first <= 7) && \
			(newPos.second + dir[i_].second >= 0) && (newPos.second + dir[i_].second <= 7))
		{
			if (board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == kingColour)
			{
				// piece hit is the same team, so no check applied on this line. break out of this direction search.
				break;
			}
			else if ((board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != kingColour) && \
				(board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EColour::empty))
			{
				// piece hit is the opposite colour. Now check if it is a queen, or a rook or bishop depending on the direction search.
				if ((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::queen) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::rook) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 1)) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::bishop) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 2)))
				{
					// piece hit is a queen, or a rook on an orthogonal, or a bishop on a diagonal, so the king is in check
					bIsCheck = true;
					return bIsCheck;
				}
			}

			newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
		}
	}

	return bIsCheck; // will be false if the function has not returned true by this point.
}

std::vector<std::pair<int, int>> CGame::GetBlockCheckSpots(std::pair<int, int> kingPos)
{
	// Note: it is assumed entering this function that the king is in check.
	// The list of spaces on the board that could block a check starts empty, and gets populated.
	std::vector<std::pair<int, int>> blockCheckSpots = {};
	
	// the number of pieces imposing a check on the king. Does not apply for pawns, as if a pawn imposes check, it is the only piece.
	int NumAttackingPieces = 0;

	std::vector<std::pair<int, int>> dir;
	EColour kingColour = board.getTeamColour(kingPos.first, kingPos.second);

	// look for the position of a pawn imposing check.
	int pawnForwardDir = to_int(kingColour)*2 - 1; //maps white->(-1), black->(1), since on white's turn black pawns are moving

	if ((kingPos.first + 1) <= 7 && \
		(kingPos.second - pawnForwardDir >= 0) && (kingPos.second - pawnForwardDir <= 7))
	{
		if ((board.getPieceType(kingPos.first + 1, kingPos.second - pawnForwardDir) == EPiece::pawn) && \
			(board.getTeamColour(kingPos.first + 1, kingPos.second - pawnForwardDir) != kingColour))
			// don't need to check for EColour::empty, because EPiece::pawn will be either black or white
		{
			// add the location of the pawn imposing check to blockCheckSpots
			blockCheckSpots.push_back(std::make_pair(kingPos.first + 1, kingPos.second - pawnForwardDir));
			
			// do not need to do NumAttackingPieces for pawns, since if a pawn is attacking, it must be the only piece attacking
		}
	}
	if ((kingPos.first - 1) >= 0 && \
		(kingPos.second - pawnForwardDir >= 0) && (kingPos.second - pawnForwardDir <= 7))
	{
		if	((board.getPieceType(kingPos.first - 1, kingPos.second - pawnForwardDir) == EPiece::pawn) && \
			(board.getTeamColour(kingPos.first - 1, kingPos.second - pawnForwardDir) != kingColour))
			// don't need to check for EColour::empty, because EPiece::pawn will be either black or white
		{
			// add the location of the pawn imposing check to blockCheckSpots
			blockCheckSpots.push_back(std::make_pair(kingPos.first - 1, kingPos.second - pawnForwardDir));
			
			// do not need to do NumAttackingPieces for pawns, since if a pawn is attacking, it must be the only piece attacking
		}
	}

	// if a pawn is imposing check, it must be the only piece imposing check, so we can leave early.
	// here, blockCheckSpots contains only the one location of the pawn imposing check.
	if (blockCheckSpots.size() != 0) { return blockCheckSpots; }
	
	// look for the position of a knight imposing check. Only one knight may impose check at once.
	dir = { std::make_pair(-1, -2), std::make_pair(-2, -1), \
		std::make_pair(-2, 1), std::make_pair(-1, 2), std::make_pair(1, 2), std::make_pair(2, 1), \
		std::make_pair(2, -1), std::make_pair(1, -2) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		if ((kingPos.first + dir[i_].first) >= 0 && (kingPos.first + dir[i_].first <= 7) && \
			(kingPos.second + dir[i_].second >= 0) && (kingPos.second + dir[i_].second <= 7))
			if ((board.getPieceType(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second) == EPiece::knight) && \
				(board.getTeamColour(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second) != kingColour))
				// don't need to check for EColour::empty, because EPiece::knight will be either black or white
			{
				// add the location of attacking knight to blockCheckSpots
				blockCheckSpots.push_back(std::make_pair(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second));
				// increment NumAttackingPieces by 1
				NumAttackingPieces = NumAttackingPieces + 1;
				break; // can exit the knight searching loop, since we found one knight imposing check so there can be no other knights
			}
	}

	// look for the position of queens, rooks or bishops imposing check.
	dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) };

	std::pair<int, int> newPos;

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		newPos = kingPos;
		while ((newPos.first + dir[i_].first) >= 0 && (newPos.first + dir[i_].first <= 7) && \
			(newPos.second + dir[i_].second >= 0) && (newPos.second + dir[i_].second <= 7))
		{
			if (board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == kingColour)
			{
				// piece hit is the same team, so no check applied on this line. break out of this direction search.
				break;
			}
			else if ((board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != kingColour) && \
				(board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EColour::empty))
			{
				// piece hit is the opposite colour. Now check if it is a queen, or a rook or bishop depending on the direction search.
				if ((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::queen) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::rook) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 1)) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::bishop) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 2)))
				{
					// piece hit is a queen, or a rook on an orthogonal, or a bishop on a diagonal, so the king is in check.
					// now add all spaces from attacking piece up to (not including) king into blockCheckSpots.
					// newPos initially becomes the position of the attacking piece.
					newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
					
					// increment NumAttackingPieces by 1
					NumAttackingPieces = NumAttackingPieces + 1;
					
					while (newPos != kingPos)
					{
						blockCheckSpots.push_back(std::make_pair(newPos.first, newPos.second));
						
						// move from the attacking piece back to the king
						newPos = std::make_pair(newPos.first - dir[i_].first, newPos.second - dir[i_].second);
					}
					break; // this searching direction is completed. proceed to the next direction.
				}
			}

			newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
		}
	}

	// if more than one piece attacking: check cannot be blocked (king must move) --> BlockCheckSpots = {}
	if (NumAttackingPieces > 1) { blockCheckSpots = {}; }
	// 	else: BlockCheckSpots = {regularly populated vector}

	return blockCheckSpots;
}

// returns dest list for a selected piece, excluding destinations that would reveal a check on the king
std::vector<std::pair<int, int>> CGame::GetDestListCheckingForPin(CPiece* piece)
{
	bool bIsPin = false;

	// position of king, used immediately after calculation, specifically for checking pins
	std::pair<int, int> Kpos;
	// direction away from king to the piece in question which may be pinned -- reset to (0,0) 
	std::pair<int, int> Kdir = std::make_pair(0,0); 

	std::vector<std::pair<int, int>> dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) }; // directions to check for king from piece in question

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		// set newPos to be position of piece in question, before moving along a line
		std::pair<int, int> newPos = piece->GetPosition(); 
		while ((newPos.first + dir[i_].first) >= 0 && (newPos.first + dir[i_].first <= 7) && \
			(newPos.second + dir[i_].second >= 0) && (newPos.second + dir[i_].second <= 7))
		{
			if (board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::king && \
				board.getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == \
				board.getTeamColour(piece->GetPosition().first, piece->GetPosition().second))
				// the king of same colour is facing piece in a line
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
		// set newPos to be position of piece, before moving along line defined by Kdir
		std::pair<int, int> newPos = piece->GetPosition(); 
		while ((newPos.first + Kdir.first) >= 0 && (newPos.first + Kdir.first <= 7) && \
			(newPos.second + Kdir.second >= 0) && (newPos.second + Kdir.second <= 7))
		{
			if (board.getTeamColour(newPos.first + Kdir.first, newPos.second + Kdir.second) != \
				board.getTeamColour(piece->GetPosition().first, piece->GetPosition().second) && \
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
				board.getTeamColour(piece->GetPosition().first, piece->GetPosition().second)) // hit a piece of same colour, so no pin
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
	
	std::vector<std::pair<int, int>> pinDestList = {};

	if (bIsPin)
	{
		if ((piece->GetPieceType() == EPiece::bishop && (abs(Kdir.first) + abs(Kdir.second) == 2)) || \
			(piece->GetPieceType() == EPiece::rook && (abs(Kdir.first) + abs(Kdir.second) == 1)) || \
			(piece->GetPieceType() == EPiece::queen))
		{
			std::pair<int, int> newPos = std::make_pair(Kpos.first + Kdir.first, Kpos.second + Kdir.second);

			while ((board.getTeamColour(newPos.first, newPos.second) == piece->GetColour()) || \
				(board.getTeamColour(newPos.first, newPos.second) == EColour::empty))
			{
				if (newPos != piece->GetPosition())
				{
					pinDestList.push_back(newPos);
				}
				newPos = std::make_pair(newPos.first + Kdir.first, newPos.second + Kdir.second);
			}
			pinDestList.push_back(newPos); // append the position of the attacking (pinning) piece to DestList
		}
		else if (piece->GetPieceType() == EPiece::pawn && (abs(Kdir.first) + abs(Kdir.second) == 2))
		{
			if ((board.getTeamColour(piece->GetPosition().first + Kdir.first, piece->GetPosition().second + Kdir.second) != \
				EColour::empty) && ((piece->GetColour() == EColour::white && Kdir.second > 0) || \
					piece->GetColour() == EColour::black && Kdir.second < 0))
			{
				// the piece imposing a pin on a pawn along a forward diagonal on an immediately adjacent square is the opposite colour
				pinDestList.push_back(std::make_pair(piece->GetPosition().first + Kdir.first, \
					piece->GetPosition().second + Kdir.second));
			}
		}
		else
		{
			pinDestList = {}; // there is a pin, and the pinned piece cannot move
		}

	}
	else
	{
		pinDestList = piece->GetDestinations(); // there is no pin -- get destinations normally
	}

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

