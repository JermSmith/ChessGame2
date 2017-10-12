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
	if (!font.loadFromFile("LCALLIG.TTF"))
	{
		font.loadFromFile("LCALLIG.TTF");
	}

	TitleTxt.setFont(font);
	TitleTxt.setCharacterSize(36);
	TitleTxt.setFillColor(sf::Color::White);
	TitleTxt.setPosition(sf::Vector2f(PIX_MPL * 8.5625, PIX_MPL * 0.375));
	TitleTxt.setString(sf::String("Chess"));

	CurrentTeamTxt.setFont(font);
	CurrentTeamTxt.setCharacterSize(16);
	CurrentTeamTxt.setFillColor(sf::Color::White);
	CurrentTeamTxt.setPosition(sf::Vector2f(PIX_MPL * 8.25, PIX_MPL * 1.25));
	CurrentTeamTxt.setString(sf::String("It is white's turn"));

	CreditsTxt.setFont(font);
	CreditsTxt.setCharacterSize(14);
	CreditsTxt.setFillColor(sf::Color::White);
	CreditsTxt.setPosition(sf::Vector2f(PIX_MPL * 8.0625, PIX_MPL * 6.625));
	CreditsTxt.setString(sf::String("Programmed by:\n       Jeremy Smith\nUpdated:\n       October 12, 2017"));

	StaleOrCheckmateTxt.setFont(font);
	StaleOrCheckmateTxt.setCharacterSize(24);
	StaleOrCheckmateTxt.setFillColor(sf::Color::White);
	StaleOrCheckmateTxt.setPosition(sf::Vector2f(PIX_MPL * 8.375, PIX_MPL * 4));
	StaleOrCheckmateTxt.setString(sf::String(""));

	WinnerTxt.setFont(font);
	WinnerTxt.setCharacterSize(18);
	WinnerTxt.setFillColor(sf::Color::White);
	WinnerTxt.setPosition(sf::Vector2f(PIX_MPL * 8.375, PIX_MPL * 5));
	WinnerTxt.setString(sf::String(""));

	ResetButton.setSize(ResetButtonSize);
	ResetButton.setFillColor(sf::Color(255, 77, 24));
	ResetButton.setPosition(ResetButtonTopLeft);

	ResetTxt.setFont(font);
	ResetTxt.setCharacterSize(16);
	ResetTxt.setFillColor(sf::Color::Black);
	ResetTxt.setPosition(sf::Vector2f(ResetButtonTopLeft.x + ResetButtonSize.x / 10, \
		ResetButtonTopLeft.y + ResetButtonSize.y / 4));
	ResetTxt.setString(sf::String("Reset Game"));

	PlayAgainButton.setSize(sf::Vector2f(0,0));
	PlayAgainButton.setFillColor(sf::Color::Green);
	PlayAgainButton.setPosition(PlayAgainButtonTopLeft);

	PlayAgainTxt.setFont(font);
	PlayAgainTxt.setCharacterSize(12);
	PlayAgainTxt.setFillColor(sf::Color::Black);
	PlayAgainTxt.setPosition(sf::Vector2f(PlayAgainButtonTopLeft.x + PlayAgainButtonSize.x / 16, \
		PlayAgainButtonTopLeft.y + PlayAgainButtonSize.y / 4));
	PlayAgainTxt.setString(sf::String(""));

	CancelButton.setSize(sf::Vector2f(0,0));
	CancelButton.setFillColor(sf::Color::Red);
	CancelButton.setPosition(CancelButtonTopLeft);

	CancelTxt.setFont(font);
	CancelTxt.setCharacterSize(12);
	CancelTxt.setFillColor(sf::Color::Black);
	CancelTxt.setPosition(sf::Vector2f(CancelButtonTopLeft.x + CancelButtonSize.x / 8, \
		CancelButtonTopLeft.y + CancelButtonSize.y / 4));
	CancelTxt.setString(sf::String(""));

	UndoButton.setSize(sf::Vector2f(UndoButtonSize));
	UndoButton.setFillColor(sf::Color::Magenta);
	UndoButton.setPosition(UndoButtonTopLeft);

	UndoTxt.setFont(font);
	UndoTxt.setCharacterSize(14);
	UndoTxt.setFillColor(sf::Color::Black);
	UndoTxt.setPosition(sf::Vector2f(UndoButtonTopLeft.x + UndoButtonSize.x / 4, \
		UndoButtonTopLeft.y + UndoButtonSize.y / 4));
	UndoTxt.setString(sf::String("Undo"));

	// Pawn Promotion items appear in the pop-up window
	PawnPromotionTxt.setFont(font);
	PawnPromotionTxt.setCharacterSize(20);
	PawnPromotionTxt.setFillColor(sf::Color::White);
	PawnPromotionTxt.setPosition(sf::Vector2f(PIX_MPL * 0.5, PIX_MPL * 0.125));
	PawnPromotionTxt.setString(sf::String(""));

	PPQueenButton.setSize(sf::Vector2f(0, 0));
	PPQueenButton.setFillColor(sf::Color(255, 215, 0, 200));
	PPQueenButton.setPosition(PPQueenButtonTopLeft);

	PPQueenTxt.setFont(font);
	PPQueenTxt.setCharacterSize(16);
	PPQueenTxt.setFillColor(sf::Color::Black);
	PPQueenTxt.setPosition(sf::Vector2f(PPQueenButtonTopLeft.x + PPButtonSize.x / 8, \
		PPQueenButtonTopLeft.y + PPButtonSize.y / 4));
	PPQueenTxt.setString(sf::String(""));

	PPRookButton.setSize(sf::Vector2f(0, 0));
	PPRookButton.setFillColor(sf::Color(255, 215, 0, 200));
	PPRookButton.setPosition(PPRookButtonTopLeft);

	PPRookTxt.setFont(font);
	PPRookTxt.setCharacterSize(16);
	PPRookTxt.setFillColor(sf::Color::Black);
	PPRookTxt.setPosition(sf::Vector2f(PPRookButtonTopLeft.x + PPButtonSize.x / 8, \
		PPRookButtonTopLeft.y + PPButtonSize.y / 4));
	PPRookTxt.setString(sf::String(""));

	PPBishopButton.setSize(sf::Vector2f(0, 0));
	PPBishopButton.setFillColor(sf::Color(255, 215, 0, 200));
	PPBishopButton.setPosition(PPBishopButtonTopLeft);

	PPBishopTxt.setFont(font);
	PPBishopTxt.setCharacterSize(16);
	PPBishopTxt.setFillColor(sf::Color::Black);
	PPBishopTxt.setPosition(sf::Vector2f(PPBishopButtonTopLeft.x + PPButtonSize.x / 8, \
		PPBishopButtonTopLeft.y + PPButtonSize.y / 4));
	PPBishopTxt.setString(sf::String(""));

	PPKnightButton.setSize(sf::Vector2f(0, 0));
	PPKnightButton.setFillColor(sf::Color(255, 215, 0, 200));
	PPKnightButton.setPosition(PPKnightButtonTopLeft);

	PPKnightTxt.setFont(font);
	PPKnightTxt.setCharacterSize(16);
	PPKnightTxt.setFillColor(sf::Color::Black);
	PPKnightTxt.setPosition(sf::Vector2f(PPKnightButtonTopLeft.x + PPButtonSize.x / 8, \
		PPKnightButtonTopLeft.y + PPButtonSize.y / 4));
	PPKnightTxt.setString(sf::String(""));

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

sf::Text* CGame::PassAlongTitleTxt()
{
	ptrTitleTxt = &TitleTxt;
	return ptrTitleTxt;
}

sf::Text * CGame::PassAlongCurrentTeamTxt()
{
	ptrCurrentTeamTxt = &CurrentTeamTxt;
	return ptrCurrentTeamTxt;
}

sf::Text* CGame::PassAlongCreditsTxt()
{
	ptrCreditsTxt = &CreditsTxt;
	return ptrCreditsTxt;
}

sf::Text* CGame::PassAlongStaleOrCheckmateTxt()
{
	ptrStaleOrCheckmateTxt = &StaleOrCheckmateTxt;
	return ptrStaleOrCheckmateTxt;
}

sf::Text* CGame::PassAlongWinnerTxt()
{
	ptrWinnerTxt = &WinnerTxt;
	return ptrWinnerTxt;
}

sf::RectangleShape* CGame::PassAlongResetButton()
{
	ptrResetButton = &ResetButton;
	return ptrResetButton;
}

sf::Text* CGame::PassAlongResetTxt()
{
	ptrResetTxt = &ResetTxt;
	return ptrResetTxt;
}

sf::RectangleShape* CGame::PassAlongPlayAgainButton()
{
	ptrPlayAgainButton = &PlayAgainButton;
	return ptrPlayAgainButton;
}

sf::Text* CGame::PassAlongPlayAgainTxt()
{
	ptrPlayAgainTxt = &PlayAgainTxt;
	return ptrPlayAgainTxt;
}

sf::RectangleShape* CGame::PassAlongCancelButton()
{
	ptrCancelButton = &CancelButton;
	return ptrCancelButton;
}

sf::Text* CGame::PassAlongCancelTxt()
{
	ptrCancelTxt = &CancelTxt;
	return ptrCancelTxt;
}

sf::RectangleShape * CGame::PassAlongUndoButton()
{
	ptrUndoButton = &UndoButton;
	return ptrUndoButton;
}

sf::Text * CGame::PassAlongUndoTxt()
{
	ptrUndoTxt = &UndoTxt;
	return ptrUndoTxt;
}

void CGame::LeftClick(sf::Event event)
{
	// get location (in terms of pixels) of the new click -- modified to reflect file & rank after checking click positions
	std::pair<int, int> newClick = std::make_pair(event.mouseButton.x, event.mouseButton.y);
	
	if (bClickOffBoard(newClick)) // leave the LeftClick function early, if click was off of board
	{
		// set colour of all spaces to white
		for (int File = 0; File <= 7; File++)
		{
			for (int Rank = 0; Rank <= 7; Rank++)
			{
				board.highlightOff(std::make_pair(File, Rank), {});
			}
		}

		if (bClickOnReset(newClick))
		{
			StaleOrCheckmateTxt.setString(sf::String("Are you\n sure?"));

			PlayAgainButton.setSize(PlayAgainButtonSize);
			PlayAgainTxt.setString(sf::String("       Yes"));

			CancelButton.setSize(CancelButtonSize);
			CancelTxt.setString(sf::String("Cancel"));
		}
		else if (bClickOnPlayAgain(newClick))
		{
			ResetGame();
		}
		else if (bClickOnCancel(newClick))
		{
			StaleOrCheckmateTxt.setString(sf::String(""));

			PlayAgainButton.setSize(sf::Vector2f(0, 0));
			PlayAgainTxt.setString(sf::String(""));

			CancelButton.setSize(sf::Vector2f(0, 0));
			CancelTxt.setString(sf::String(""));
		}
		else if (bClickOnUndo(newClick))
		{
			if (!bHasUndone) { UndoPrevMove(); }
		}

		return; // exit the LeftClick function early since the click was not on a piece
	}
	
	// Erase the text and buttons on the side if it says "Are you\n sure?"
	if (StaleOrCheckmateTxt.getString()[0] == sf::String("A"))
	{
		StaleOrCheckmateTxt.setString(sf::String(""));

		PlayAgainButton.setSize(sf::Vector2f(0, 0));
		PlayAgainTxt.setString(sf::String(""));

		CancelButton.setSize(sf::Vector2f(0, 0));
		CancelTxt.setString(sf::String(""));
	}

	// get file & rank from x- and y-location of click
	newClick = std::make_pair(static_cast<int>(floor(newClick.first / PIX_MPL)), \
		7 - static_cast<int>(floor(newClick.second / PIX_MPL)));

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

	bool bIsDestination = false;
	// becomes true if newPiece position matches any of the destinations in DestList.
	for (unsigned int dest = 0; dest < DestList.size(); dest++)
	{
		if (newPiece->GetPosition().first == DestList[dest].first && newPiece->GetPosition().second == DestList[dest].second)
		{
			bIsDestination = true;
			break;
		}
	}

	if (bIsDestination) // clicked on a valid destination, based on DestList
	{
		bHasUndone = false; // enables the undo function

		eliminateCastlingOptions();

		// store a copy of the previous move
		PrevPrevMove = PrevMove;

		// store the move that is currently happening as PrevMove
		PrevMove = { oldPiece->GetPosition(), oldPiece->GetColour(), oldPiece->GetPieceType(), \
			newPiece->GetPosition(), newPiece->GetColour(), newPiece->GetPieceType() };

		board.highlightOff(oldPiece->GetPosition(), DestList);

		board.movePiece(oldPiece->GetPosition(), newPiece->GetPosition());

		DestList = {};

		if (bIsPawnPromotion())
		{
			DoPawnPromotion(newPiece->GetPosition());
		}

		switchTeam(); //switches to the other team before checking checkmate/stalemate, so that currentTeamColour can be used

		CheckIfStaleOrCheckmate();
	}

	// first click was NOT ON our team, second click was ON our team
	else if ((oldPiece->GetColour() != currentTeamColour) && (newPiece->GetColour() == currentTeamColour))
	{
		DestList = ObtainValidDestinationsForAnyPiece(newPiece);
		
		// possibly append king-side castling to the list of destinations for the king
		if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(0))
		{
			DestList.push_back(std::make_pair(newPiece->GetPosition().first + 2, newPiece->GetPosition().second));
		}
		// possibly append queen-side castling to the list of destinations for the king
		if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(1))
		{
			DestList.push_back(std::make_pair(newPiece->GetPosition().first - 2, newPiece->GetPosition().second));
		}
		
		board.highlightOn(newPiece->GetPosition(), DestList);
	}
	
	// first click was ON our team, second click was NOT ON our team (also not a destination, since checked earlier)
	else if ((oldPiece->GetColour() == currentTeamColour) && (newPiece->GetColour() != currentTeamColour))
	{
		board.highlightOff(oldPiece->GetPosition(), DestList);
		
		DestList = {};
	}
	
	// first click was ON our team, second click was ON our team (could be same piece or different)
	else if ((oldPiece->GetColour() == currentTeamColour) && (newPiece->GetColour() == currentTeamColour))
	{
		if (oldPiece->GetPosition() == newPiece->GetPosition()) //clicked on same piece twice in a row
		{
			// update DestList, depending if it is populated or not
			if (DestList.size() == 0) // if CGame's list of destinations is empty...
			{
				// then populate it with destinations for the click provided
				DestList = ObtainValidDestinationsForAnyPiece(newPiece);

				// possibly append king-side castling to the list of destinations for the king
				if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(0))
				{
					DestList.push_back(std::make_pair(newPiece->GetPosition().first + 2, newPiece->GetPosition().second));
				}
				// possibly append queen-side castling to the list of destinations for the king
				if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(1))
				{
					DestList.push_back(std::make_pair(newPiece->GetPosition().first - 2, newPiece->GetPosition().second));
				}

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

			DestList = ObtainValidDestinationsForAnyPiece(newPiece);

			// possibly append king-side castling to the list of destinations for the king
			if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(0))
			{
				DestList.push_back(std::make_pair(newPiece->GetPosition().first + 2, newPiece->GetPosition().second));
			}
			// possibly append queen-side castling to the list of destinations for the king
			if (newPiece->GetPieceType() == EPiece::king && bCanCastleSide(1))
			{
				DestList.push_back(std::make_pair(newPiece->GetPosition().first - 2, newPiece->GetPosition().second));
			}

			board.highlightOn(newPiece->GetPosition(), DestList);
		}
	}
	oldClick = newClick; // newClick is set anew at the start of the function

	return;
}

void CGame::ResetGame()
{
	bWhiteKing_Unmoved = true;
	bBlackKing_Unmoved = true;
	bWRookKSide_Unmoved = true;
	bWRookQSide_Unmoved = true;
	bBRookKSide_Unmoved = true;
	bBRookQSide_Unmoved = true;

	bHasUndone = true;
	PrevMove = { \
		std::make_pair(0, 0), EColour::white, EPiece::rook, std::make_pair(0, 0), EColour::white, EPiece::rook };

	board.ResetBoard();
	currentTeamColour = EColour::white;
	CurrentTeamTxt.setString(sf::String("It is white's turn"));
	StaleOrCheckmateTxt.setString(sf::String(""));
	WinnerTxt.setString(sf::String(""));
	ResetButton.setSize(ResetButtonSize);
	ResetTxt.setString("Reset Game");
	PlayAgainButton.setSize(sf::Vector2f(0, 0));
	PlayAgainTxt.setString(sf::String(""));
	CancelButton.setSize(sf::Vector2f(0, 0));
	CancelTxt.setString(sf::String(""));

	for (int File = 0; File <= 7; File++)
	{
		for (int Rank = 0; Rank <= 7; Rank++)
		{
			board.highlightOff(std::make_pair(File, Rank), {});
		}
	}
}

// all of the click functions for graphics receive clicks in pixel coordinates 

bool CGame::bClickOffBoard(std::pair<int, int> click)
{
	bool bClickOffBoard = false;
	if (click.first < 0 || click.first > PIX_MPL * 8 || click.second < 0 || click.second > PIX_MPL * 8)
	{
		bClickOffBoard = true;
	}
	return bClickOffBoard;
}

bool CGame::bClickOnReset(std::pair<int, int> click)
{
	bool bClickOnReset = false;
	if ((click.first > ResetButtonTopLeft.x) && (click.first < ResetButtonTopLeft.x + ResetButton.getSize().x) && \
		(click.second > ResetButtonTopLeft.y) && (click.second < ResetButtonTopLeft.y + ResetButton.getSize().y))
	{
		bClickOnReset = true;
	}
	return bClickOnReset;
}

bool CGame::bClickOnPlayAgain(std::pair<int, int> click)
{
	bool bClickOnPlayAgain = false;
	if ((click.first > PlayAgainButtonTopLeft.x) && (click.first < PlayAgainButtonTopLeft.x + PlayAgainButton.getSize().x) && \
		(click.second > PlayAgainButtonTopLeft.y) && (click.second < PlayAgainButtonTopLeft.y + PlayAgainButton.getSize().y))
	{
		bClickOnPlayAgain = true;
	}
	return bClickOnPlayAgain;
}

bool CGame::bClickOnCancel(std::pair<int, int> click)
{
	bool bClickOnCancel = false;
	if ((click.first > CancelButtonTopLeft.x) && (click.first < CancelButtonTopLeft.x + CancelButton.getSize().x) && \
		(click.second > CancelButtonTopLeft.y) && (click.second < CancelButtonTopLeft.y + CancelButton.getSize().y))
	{
		bClickOnCancel = true;
	}
	return bClickOnCancel;
}

bool CGame::bClickOnUndo(std::pair<int, int> click)
{
	bool bClickOnUndo = false;
	if ((click.first > UndoButtonTopLeft.x) && (click.first < UndoButtonTopLeft.x + UndoButton.getSize().x) && \
		(click.second > UndoButtonTopLeft.y) && (click.second < UndoButtonTopLeft.y + UndoButton.getSize().y))
	{
		bClickOnUndo = true;
	}
	return bClickOnUndo;
}

bool CGame::bClickOnPPQueen(std::pair<int, int> click)
{
	bool bClickOnPPQueen = false;
	if ((click.first > PPQueenButtonTopLeft.x) && (click.first < PPQueenButtonTopLeft.x + PPQueenButton.getSize().x) && \
		(click.second > PPQueenButtonTopLeft.y) && (click.second < PPQueenButtonTopLeft.y + PPQueenButton.getSize().y))
	{
		bClickOnPPQueen = true;
	}
	return bClickOnPPQueen;
}

bool CGame::bClickOnPPRook(std::pair<int, int> click)
{
	bool bClickOnPPRook = false;
	if ((click.first > PPRookButtonTopLeft.x) && (click.first < PPRookButtonTopLeft.x + PPRookButton.getSize().x) && \
		(click.second > PPRookButtonTopLeft.y) && (click.second < PPRookButtonTopLeft.y + PPRookButton.getSize().y))
	{
		bClickOnPPRook = true;
	}
	return bClickOnPPRook;
}

bool CGame::bClickOnPPBishop(std::pair<int, int> click)
{
	bool bClickOnPPBishop = false;
	if ((click.first > PPBishopButtonTopLeft.x) && (click.first < PPBishopButtonTopLeft.x + PPBishopButton.getSize().x) && \
		(click.second > PPBishopButtonTopLeft.y) && (click.second < PPBishopButtonTopLeft.y + PPBishopButton.getSize().y))
	{
		bClickOnPPBishop = true;
	}
	return bClickOnPPBishop;
}

bool CGame::bClickOnPPKnight(std::pair<int, int> click)
{
	bool bClickOnPPKnight = false;
	if ((click.first > PPKnightButtonTopLeft.x) && (click.first < PPKnightButtonTopLeft.x + PPKnightButton.getSize().x) && \
		(click.second > PPKnightButtonTopLeft.y) && (click.second < PPKnightButtonTopLeft.y + PPKnightButton.getSize().y))
	{
		bClickOnPPKnight = true;
	}
	return bClickOnPPKnight;
}

std::pair<int, int> CGame::findKingPosition(EColour colour)
{
	std::pair<int, int> kingPosition = std::make_pair(0, 0);
	
	for (unsigned int file = 0; file <= 7; file++)
	{
		for (unsigned int rank = 0; rank <= 7; rank++)
		{
			if (board.getPieceType(file, rank) == EPiece::king && board.getTeamColour(file, rank) == colour)
			{
				kingPosition = std::make_pair(file, rank);
				return kingPosition;
			}
		}
	}
	return kingPosition; // never happens, because it is always returned earlier
}

bool CGame::bCheckIfCheck(std::pair<int, int> kingPos, EColour kingColour)
{
	bool bIsCheck = false;
	std::vector<std::pair<int, int>> dir;
	//EColour kingColour = board.getTeamColour(kingPos.first, kingPos.second);

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
				if ((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EPiece::queen) && \
					(board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EPiece::rook) && \
					(board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != EPiece::bishop))
				{
					// piece hit is not a queen, nor a rook, nor a bishop, so no check is (or would be) applied from this direction
					break; // break out of this direction search
				}
				else if (((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::rook) && \
					(abs(dir[i_].first) + abs(dir[i_].second) != 1)) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::bishop) && \
					(abs(dir[i_].first) + abs(dir[i_].second) != 2)))
				{
					// piece hit is a rook along a diagonal or a bishop along an orthogonal, so no check is (or would be) applied from this direction
					break; // break out of this direction search
				}
				else if ((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::queen) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::rook) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 1)) \
					|| \
					((board.getPieceType(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EPiece::bishop) && \
					(abs(dir[i_].first) + abs(dir[i_].second) == 2)))
				{
					// piece hit is a queen, or a rook on an orthogonal, or a bishop on a diagonal, so the king is (or would be) in check
					bIsCheck = true;
					return bIsCheck;
				}
			}

			newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
		}
	}

	// now check for the opposing king imposing check
	// (used when assuming the king moves to a destination adjacent to the opposing king)
	dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		if ((kingPos.first + dir[i_].first) >= 0 && (kingPos.first + dir[i_].first <= 7) && \
			(kingPos.second + dir[i_].second >= 0) && (kingPos.second + dir[i_].second <= 7))
		{
			if (board.getPieceType(kingPos.first + dir[i_].first, kingPos.second + dir[i_].second) == EPiece::king)
			{
				bIsCheck = true;
				return bIsCheck;
			}
		}
	}

	return bIsCheck; // must be false if the function has not returned true by this point.
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

// returns destinations list for a selected piece, excluding destinations that would reveal a check on the king
std::vector<std::pair<int, int>> CGame::GetDestListCheckingForPin(CPiece* piece)
{
	bool bIsPin = false;

	// position of king, used immediately after its determination, specifically for checking pins.
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

	if (Kdir.first == 0 && Kdir.second == 0) // Kdir unchanged -- no valid direction found to encounter king in a line
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
			// a bishop is "pinned" along a diagonal, or a rook along an orthogonal, or a queen in any direction

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
		else if (piece->GetPieceType() == EPiece::pawn)
		{
			if (abs(Kdir.first) + abs(Kdir.second) == 2)
			{
				if ((board.getTeamColour(piece->GetPosition().first + Kdir.first, piece->GetPosition().second + Kdir.second) != \
					EColour::empty) && ((piece->GetColour() == EColour::white && Kdir.second > 0) || \
						piece->GetColour() == EColour::black && Kdir.second < 0))
				{
					// the piece imposing a pin on a pawn along a forward diagonal on an immediately adjacent square is the opposite colour
					pinDestList.push_back(std::make_pair(piece->GetPosition().first + Kdir.first, \
						piece->GetPosition().second + Kdir.second));
				}
				
				// code to add the destination for en passant, if the diagonal for en passant is the same as the pinning direction.

				// at this point, we have clicked on a pawn, and if the circumstances are correct, it can capture diagonally on
				// a space where no piece is present.

				else if (\
					(piece->GetColour() == EColour::white && \
					piece->GetPosition().second == to_int(ERank::Rank5) && \
					std::get<1>(PrevMove) == EColour::black && \
					std::get<2>(PrevMove) == EPiece::pawn && \
					std::get<3>(PrevMove).second == to_int(ERank::Rank5) && \
					std::get<0>(PrevMove).second == to_int(ERank::Rank7) && \
					abs(piece->GetPosition().first - std::get<3>(PrevMove).first) == 1) \
					|| \
					(piece->GetColour() == EColour::black && \
					piece->GetPosition().second == to_int(ERank::Rank4) && \
					std::get<1>(PrevMove) == EColour::white && \
					std::get<2>(PrevMove) == EPiece::pawn && \
					std::get<3>(PrevMove).second == to_int(ERank::Rank4) && \
					std::get<0>(PrevMove).second == to_int(ERank::Rank2) && \
					abs(piece->GetPosition().first - std::get<3>(PrevMove).first) == 1) \
					)
				{
					int pawnForwardDir = to_int(currentTeamColour) * -2 + 1; //maps white->(1), black->(-1)
					int pawnSideDir = std::get<3>(PrevMove).first - piece->GetPosition().first; //decrease file->(-1), increase file->(1)

					// Kdir is the dir from the king to its pinned pawn. If the pawn wants to move along this dir,
					// or in the exact opposite direction, then it can do this.
					if ((Kdir.first == pawnSideDir && Kdir.second == pawnForwardDir) || \
						(Kdir.first == pawnSideDir * -1 && Kdir.second == pawnForwardDir * -1))
					{
						pinDestList.push_back(std::make_pair(piece->GetPosition().first + pawnSideDir, \
							piece->GetPosition().second + pawnForwardDir));
					}
				}
			}
			else if (abs(Kdir.first) == 0 && abs(Kdir.second) == 1)
			{
				// the piece imposing the pin, the pawn and the king are all in the same file
				// code for en passant is omitted in this case

				int pawnForwardDir = to_int(currentTeamColour) * -2 + 1; //maps white->(1), black->(-1)
				
				pinDestList.push_back(std::make_pair(piece->GetPosition().first, \
					piece->GetPosition().second + pawnForwardDir));

				// if the pawn has yet to move and the space is open, allow the pawn to move 2 spaces forward
				if (((piece->GetColour() == EColour::white && piece->GetPosition().second == to_int(ERank::Rank2)) || \
					(piece->GetColour() == EColour::black && piece->GetPosition().second == to_int(ERank::Rank7))) \
					&& \
					(board.getPieceType(piece->GetPosition().first, piece->GetPosition().second + 2*pawnForwardDir) == EPiece::empty))
				{
					pinDestList.push_back(std::make_pair(piece->GetPosition().first, \
						piece->GetPosition().second + 2 * pawnForwardDir));
				}
			}
		}
		else
		{
			pinDestList = {}; // there is a pin, and the pinned piece has no valid moves
		}
	}
	else // there is no pin -- get destinations normally
	{
		pinDestList = piece->GetDestinations();

		// possible add a destination for en passant if the piece is a pawn.
		if (piece->GetPieceType() == EPiece::pawn)
		{
			// at this point, we have clicked on a pawn, and if the circumstances are correct, it can capture diagonally on
			// a space where no piece is present.
			if (\
				(piece->GetColour() == EColour::white && \
				piece->GetPosition().second == to_int(ERank::Rank5) && \
				std::get<1>(PrevMove) == EColour::black && \
				std::get<2>(PrevMove) == EPiece::pawn && \
				std::get<3>(PrevMove).second == to_int(ERank::Rank5) && \
				std::get<0>(PrevMove).second == to_int(ERank::Rank7) && \
				abs(piece->GetPosition().first - std::get<3>(PrevMove).first) == 1) \
				|| \
				(piece->GetColour() == EColour::black && \
				piece->GetPosition().second == to_int(ERank::Rank4) && \
				std::get<1>(PrevMove) == EColour::white && \
				std::get<2>(PrevMove) == EPiece::pawn && \
				std::get<3>(PrevMove).second == to_int(ERank::Rank4) && \
				std::get<0>(PrevMove).second == to_int(ERank::Rank2) && \
				abs(piece->GetPosition().first - std::get<3>(PrevMove).first) == 1) \
				)
			{
				int pawnForwardDir = to_int(currentTeamColour) * -2 + 1; //maps white->(1), black->(-1)
				int pawnSideDir = std::get<3>(PrevMove).first - piece->GetPosition().first; //decrease file->(-1), increase file->(1)

				pinDestList.push_back(std::make_pair(piece->GetPosition().first + pawnSideDir, \
					piece->GetPosition().second + pawnForwardDir));
			}
		}
	}

	return pinDestList;
}

/* a function that receives the original list of king destinations (not considering check), 
and returns the list of king destinations that do not put the king in check. */
std::vector<std::pair<int, int>> CGame::RemoveDestinationsWhereKingInCheck(std::vector<std::pair<int, int>> uncensoredKingDestList)
{
	// the vector to be populated with destinations that will not put the king in check
	std::vector<std::pair<int, int>> censoredKingDestList = {};

	EPiece origDestPiece;
	EColour origDestColour;

	for (unsigned int i_ = 0; i_ < uncensoredKingDestList.size(); i_++)
	{
		// record the original piecetype and colour of the destination space
		origDestPiece = board.getPieceType(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second);
		origDestColour = board.getTeamColour(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second);

		// temporarily set the king's position to be empty when checking for check in a possible destination for the king
		board.setPieceType(kingPosition.first, kingPosition.second, EPiece::empty);
		board.setTeamColour(kingPosition.first, kingPosition.second, EColour::empty);

		// temporarily move king to a possible destination to check for check in each destination.
		board.setPieceType(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second, EPiece::king);
		board.setTeamColour(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second, currentTeamColour);

		if (!bCheckIfCheck(uncensoredKingDestList[i_], currentTeamColour)) // notice the !
		{
			// the king would be out of check in the new destination, so it is a valid destination
			censoredKingDestList.push_back(uncensoredKingDestList[i_]);
		}

		// after checking, put the king back in its original position.
		board.setPieceType(kingPosition.first, kingPosition.second, EPiece::king);
		board.setTeamColour(kingPosition.first, kingPosition.second, currentTeamColour);

		// replace the original piece to the destination that was checked
		board.setPieceType(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second, origDestPiece);
		board.setTeamColour(uncensoredKingDestList[i_].first, uncensoredKingDestList[i_].second, origDestColour);
	}
	return censoredKingDestList;
}

/* A function that wraps all functionality together for calculating and returning the list of valid destinations for
any selected piece. Receives newPiece (type CPiece*) as input, and returns a vector of destinations for newPiece. 
Does not include castling. */
std::vector<std::pair<int, int>> CGame::ObtainValidDestinationsForAnyPiece(CPiece* piece)
{
	std::vector<std::pair<int, int>> destlist;

	bool bIsCheck = false;
	std::vector<std::pair<int, int>> BlockCheckSpots = {};
	std::vector<std::pair<int, int>> UncensoredDestList = {};

	kingPosition = findKingPosition(currentTeamColour);

	bIsCheck = bCheckIfCheck(kingPosition, currentTeamColour);
	
	if (bIsCheck == true)
	{
		BlockCheckSpots = GetBlockCheckSpots(kingPosition);

		if (piece->GetPieceType() != EPiece::king) // newPiece is not a king, but the king is in check
		{
			UncensoredDestList = GetDestListCheckingForPin(piece);
			for (unsigned int i_ = 0; i_ < UncensoredDestList.size(); i_++)
			{
				for (unsigned int j_ = 0; j_ < BlockCheckSpots.size(); j_++)
				{
					if (UncensoredDestList[i_] == BlockCheckSpots[j_])
					{
						destlist.push_back(BlockCheckSpots[j_]);
					}
				}
			}
		}
		else // newPiece is a king, which is in check. need to get valid destinations for the king.
		{
			UncensoredDestList = GetDestListCheckingForPin(piece); // between 0 and 8 (otherwise) valid dests for the king

			destlist = RemoveDestinationsWhereKingInCheck(UncensoredDestList);
		}
	}
	else // not in check
	{
		if (piece->GetPieceType() != EPiece::king) // newPiece is not a king, and king is not in check
		{
			destlist = GetDestListCheckingForPin(piece);
		}
		else // newPiece is a king, which is not in check
		{
			// the king may have destinations removed since it cannot place itself in check
			UncensoredDestList = GetDestListCheckingForPin(piece); // between 0 and 8 (otherwise) valid dests for the king

			destlist = RemoveDestinationsWhereKingInCheck(UncensoredDestList);
		}
	}
	return destlist;
}


bool CGame::bCanCastleSide(int side)
{
	// 0 for Kside, 1 for Qside

	bool bCanCastle = false; // the function returns false unless it is proven that castling is valid

	if ((currentTeamColour == EColour::white && bWhiteKing_Unmoved && side == 0 && bWRookKSide_Unmoved) || \
		(currentTeamColour == EColour::white && bWhiteKing_Unmoved && side == 1 && bWRookQSide_Unmoved) || \
		(currentTeamColour == EColour::black && bBlackKing_Unmoved && side == 0 && bBRookKSide_Unmoved) || \
		(currentTeamColour == EColour::black && bBlackKing_Unmoved && side == 1 && bBRookQSide_Unmoved))

	{
		int dir;
		if (side == 0) { dir = 1; } // king side (dir = 1 since file checked in the increasing direction)
		else { dir = -1; } // queen side (dir = -1 since file checked in the decreasing direction)

		// at this point, we know [at least one of KSide and QSide Rook] and King both have NOT moved, so castling COULD be valid.
		kingPosition = findKingPosition(currentTeamColour);

		// if all spaces between king and k/qside rook are empty...
		if ((board.getPieceType(kingPosition.first + dir, kingPosition.second) == EPiece::empty && \
			board.getPieceType(kingPosition.first + dir * 2, kingPosition.second) == EPiece::empty) && \
			(dir == 1 || (dir == -1 && board.getPieceType(kingPosition.first + dir * 3, kingPosition.second) == EPiece::empty)))
		{
			if (!bCheckIfCheck(std::make_pair(kingPosition.first, kingPosition.second), currentTeamColour)) // notice the !
			{
				// the king is not in check - now check the space it must cross

				// temporarily move the king to check whether it would be in check in the intermediate space when castling
				board.setPieceType(kingPosition.first, kingPosition.second, EPiece::empty);
				board.setTeamColour(kingPosition.first, kingPosition.second, EColour::empty);

				board.setPieceType(kingPosition.first + dir, kingPosition.second, EPiece::king);
				board.setTeamColour(kingPosition.first + dir, kingPosition.second, currentTeamColour);
				
				if (!bCheckIfCheck(std::make_pair(kingPosition.first + dir, kingPosition.second), currentTeamColour)) // notice the !
				{
					// the king would not be in check in the space it must cross - now check the destination space

					// temporarily move the king to its potential castling destination to check if it would be in check there
					board.setPieceType(kingPosition.first + dir, kingPosition.second, EPiece::empty);
					board.setTeamColour(kingPosition.first + dir, kingPosition.second, EColour::empty);

					board.setPieceType(kingPosition.first + 2 * dir, kingPosition.second, EPiece::king);
					board.setTeamColour(kingPosition.first + 2 * dir, kingPosition.second, currentTeamColour);

					if (!bCheckIfCheck(std::make_pair(kingPosition.first + dir * 2, kingPosition.second), currentTeamColour)) // notice the !
					{
						// the king would not be in check in its destination for castling; this castling is valid
						bCanCastle = true;

					} // end of "if" for checking king destination

				} // end of "if" for checking check at space crossed by king

			} // end of "if" for checking check at original king pos

			// after checking, put the king back in its original position.
			// the following 2 are already set to empty if the king would not be in check in the space it must cross
			board.setPieceType(kingPosition.first + dir, kingPosition.second, EPiece::empty);
			board.setTeamColour(kingPosition.first + dir, kingPosition.second, EColour::empty);

			// the following 2 are only changed from empty if the king is not in check in both its original pos and the space it must cross
			board.setPieceType(kingPosition.first + 2 * dir, kingPosition.second, EPiece::empty);
			board.setTeamColour(kingPosition.first + 2 * dir, kingPosition.second, EColour::empty);

			// the following 2 were never changed if the king is in check in its original ("actual") position
			board.setPieceType(kingPosition.first, kingPosition.second, EPiece::king);
			board.setTeamColour(kingPosition.first, kingPosition.second, currentTeamColour);
		
		} // end of "if" for checking if the spaces between king & rook are empty or not

	} // end of "if" checking if both the king and rook have not moved

	return bCanCastle;
}

void CGame::CheckIfStaleOrCheckmate()
{
	// when entering this function, the currentTeamColour has just been changed to the team that didn't just move, to see if they are trapped

	// check if the team that didn't just move has been checkmated, or if there is stalemate, or neither.
	bool bIsCheckmate = false;
	bool bIsStalemate = false;

	// create the king object (we will check if it has any destinations or not)
	CKing tempObj1(currentTeamColour);
	CPiece *otherKingPiece = &tempObj1;

	otherKingPiece->SetPosition(findKingPosition(currentTeamColour).first, findKingPosition(currentTeamColour).second);
	otherKingPiece->calcDestinations(&board);

	int numOtherKingDests = ObtainValidDestinationsForAnyPiece(otherKingPiece).size(); // does not include castling locations
	if (numOtherKingDests == 0)
	{
		// the piece that is used when looping through the board
		CPiece *loopPiece;

		// a running total of the number of destinations for the team
		int NumDestForTeam = 0;

		// king has no destinations - could be checkmate, stalemate, or neither.
		for (int file = 0; file <= 7; file++)
		{
			for (int rank = 0; rank <= 7; rank++)
			{
				if (board.getTeamColour(file, rank) == currentTeamColour)
				{
					// we are investigating a piece of the other team at (file, rank) to see if it has moves

					// assign loopPiece to an object of correct type for the piece
					switch (board.getPieceType(file, rank))
					{
					case EPiece::pawn:
					{
						CPawn tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					case EPiece::rook:
					{
						CRook tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					case EPiece::knight:
					{
						CKnight tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					case EPiece::bishop:
					{
						CBishop tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					case EPiece::queen:
					{
						CQueen tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					case EPiece::king:
					{
						CKing tempObj2(currentTeamColour);
						loopPiece = &tempObj2;
						break;
					}
					default:
						CPiece tempObj2;
						loopPiece = &tempObj2;
						break;
					}

					loopPiece->SetPosition(file, rank);
					loopPiece->calcDestinations(&board);
					NumDestForTeam = NumDestForTeam + ObtainValidDestinationsForAnyPiece(loopPiece).size();

					if (NumDestForTeam != 0)
					{	// at least one piece has a destination, so the game is not checkmate or stalemate
						bIsCheckmate = false;
						bIsStalemate = false;
						// break out of the "rank" for loop if a destination has been found
						break;
					}
				} // end of if
			} // end of "rank" for

			if (NumDestForTeam != 0)
			{	// at least one piece has a destination, so the game is not checkmate or stalemate
				// break out of the "file" for loop if a destination has been found
				break;
			}

		} // end of "file" for

		if (NumDestForTeam == 0) // the other team is either checkmated or the game is stalemated
		{
			// if the other team is in check, it is checkmate
			if (bCheckIfCheck(otherKingPiece->GetPosition(), currentTeamColour))
			{
				bIsCheckmate = true;
				StaleOrCheckmateTxt.setString("Checkmate");

				std::string WinnerString;
				if (currentTeamColour == EColour::white) { WinnerString = " Black"; }
				else { WinnerString = " White"; }

				WinnerTxt.setString(WinnerString + " wins!");
			}

			// the other team is not in check but cannot move, so the game is a stalemate
			else
			{
				bIsStalemate = true;
				StaleOrCheckmateTxt.setString("Stalemate");
			}

			CurrentTeamTxt.setString("");

			PlayAgainButton.setSize(PlayAgainButtonSize);
			PlayAgainTxt.setString(sf::String(" Play Again"));

			ResetButton.setSize(sf::Vector2f(0, 0));
			ResetTxt.setString(sf::String(""));

		}
	}
}

// switches the team whose turn it is to move
void CGame::switchTeam()
{
	if (currentTeamColour == EColour::white)
	{
		currentTeamColour = EColour::black;
		CurrentTeamTxt.setString(sf::String("It is black's turn"));
	}
	else
	{
		currentTeamColour = EColour::white;
		CurrentTeamTxt.setString(sf::String("It is white's turn"));
	}
	return;
}

void CGame::eliminateCastlingOptions()
{
	if (std::get<2>(PrevMove) == EPiece::king) // a king moved last turn, so castling is no longer available for that team
	{
		if (std::get<1>(PrevMove) == EColour::white && currentTeamColour == EColour::black)
		{
			bWhiteKing_Unmoved = false;
		}
		else if (std::get<1>(PrevMove) == EColour::black && currentTeamColour == EColour::white)
		{
			bBlackKing_Unmoved = false;
		}
	}

	else if (std::get<2>(PrevMove) == EPiece::rook) // a rook moved, so castling is no longer available for that team on that side
	{
		if (std::get<0>(PrevMove) == std::make_pair(0, 0) && currentTeamColour == EColour::black) { bWRookQSide_Unmoved = false; }
		else if (std::get<0>(PrevMove) == std::make_pair(7, 0) && currentTeamColour == EColour::black) { bWRookKSide_Unmoved = false; }
		else if (std::get<0>(PrevMove) == std::make_pair(0, 7) && currentTeamColour == EColour::white) { bBRookQSide_Unmoved = false; }
		else if (std::get<0>(PrevMove) == std::make_pair(7, 7) && currentTeamColour == EColour::white) { bBRookKSide_Unmoved = false; }
	}
	
	return;
}

bool CGame::bIsPawnPromotion()
{
	bool bIsPawnPromotion = false;
	int lastRank; // maps white -> 7, black -> 0
	if (currentTeamColour == EColour::white) { lastRank = 7; }
	else { lastRank = 0; }

	for (unsigned int file = 0; file <= 7; file++)
	{
		if (board.getPieceType(file, lastRank) == EPiece::pawn)
		{
			bIsPawnPromotion = true;
			break;
		}
	}
	return bIsPawnPromotion;
}

void CGame::DoPawnPromotion(std::pair<int, int> PPposition)
{
	PawnPromotionTxt.setString(sf::String("Pawn Promotion!\nSelect a piece."));

	PPQueenButton.setSize(PPButtonSize);
	PPQueenTxt.setString("Queen");
	PPRookButton.setSize(PPButtonSize);
	PPRookTxt.setString("Rook");
	PPBishopButton.setSize(PPButtonSize);
	PPBishopTxt.setString("Bishop");
	PPKnightButton.setSize(PPButtonSize);
	PPKnightTxt.setString("Knight");

	sf::RenderWindow PPwindow(sf::VideoMode(PIX_MPL * 9 / 2, PIX_MPL * 3), "Pawn Promotion");
	while (PPwindow.isOpen())
	{
		sf::Event PPevent;
		while (PPwindow.pollEvent(PPevent))
		{
			// check different event types
			if (PPevent.type == sf::Event::MouseButtonReleased)
			{
				if (PPevent.mouseButton.button == sf::Mouse::Left)
				{
					// the click in the new window
					std::pair<int, int> PPClick = std::make_pair(PPevent.mouseButton.x, PPevent.mouseButton.y);

					int file = PPposition.first;
					int rank = PPposition.second;

					if (bClickOnPPQueen(PPClick))
					{
						// do not need to set colour here, because the piece retains its colour and becomes a queen
						board.setPieceType(file, rank, EPiece::queen);
						board.setPieceSprite(file, rank, currentTeamColour, EPiece::queen);
						PPwindow.close();
					}
					else if (bClickOnPPRook(PPClick))
					{
						// do not need to set colour here, because the piece retains its colour and becomes a rook
						board.setPieceType(file, rank, EPiece::rook);
						board.setPieceSprite(file, rank, currentTeamColour, EPiece::rook);
						PPwindow.close();
					}
					else if (bClickOnPPBishop(PPClick))
					{
						// do not need to set colour here, because the piece retains its colour and becomes a bishop
						board.setPieceType(file, rank, EPiece::bishop);
						board.setPieceSprite(file, rank, currentTeamColour, EPiece::bishop);
						PPwindow.close();
					}
					else if (bClickOnPPKnight(PPClick))
					{
						// do not need to set colour here, because the piece retains its colour and becomes a knight
						board.setPieceType(file, rank, EPiece::knight);
						board.setPieceSprite(file, rank, currentTeamColour, EPiece::knight);
						PPwindow.close();
					}
				}
			}
		}
		PPwindow.clear();
		PPwindow.draw(PawnPromotionTxt);
		PPwindow.draw(PPQueenButton);
		PPwindow.draw(PPQueenTxt);
		PPwindow.draw(PPRookButton);
		PPwindow.draw(PPRookTxt);
		PPwindow.draw(PPBishopButton);
		PPwindow.draw(PPBishopTxt);
		PPwindow.draw(PPKnightButton);
		PPwindow.draw(PPKnightTxt);

		PPwindow.display();
	}
	return;
}

void CGame::UndoPrevMove()
{
	bHasUndone = true;

	// moved piece is reset to its original colour and position
	board.setTeamColour(std::get<0>(PrevMove).first, std::get<0>(PrevMove).second, std::get<1>(PrevMove));
	board.setPieceType(std::get<0>(PrevMove).first, std::get<0>(PrevMove).second, std::get<2>(PrevMove));
	board.setPieceSprite(std::get<0>(PrevMove).first, std::get<0>(PrevMove).second, std::get<1>(PrevMove), std::get<2>(PrevMove));

	// destination space is reset
	board.setTeamColour(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second, std::get<4>(PrevMove));
	board.setPieceType(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second, std::get<5>(PrevMove));
	board.setPieceSprite(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second, std::get<4>(PrevMove), std::get<5>(PrevMove));

	// if castling happened, then reset the position of the rook and the castling validity trackers
	if (std::get<2>(PrevMove) == EPiece::king && abs(std::get<3>(PrevMove).first - std::get<0>(PrevMove).first) == 2)
	{
		if (std::get<1>(PrevMove) == EColour::white) // white is the team that castled
		{
			// the king does not have "bColourKing_Unmoved" set to false until the other team makes their move, since
			// eliminateCastlingOptions() uses PrevMove but is called before PrevMove is overwritten (when a destination is clicked)

			if (std::get<3>(PrevMove).first > std::get<0>(PrevMove).first) // ending file > start file, so castling K side
			{
				board.setTeamColour(to_int(EFile::FileH), to_int(ERank::Rank1), EColour::white);
				board.setPieceType(to_int(EFile::FileH), to_int(ERank::Rank1), EPiece::rook);
				board.setPieceSprite(to_int(EFile::FileH), to_int(ERank::Rank1), EColour::white, EPiece::rook);

				board.setTeamColour(to_int(EFile::FileF), to_int(ERank::Rank1), EColour::empty);
				board.setPieceType(to_int(EFile::FileF), to_int(ERank::Rank1), EPiece::empty);
				board.setPieceSprite(to_int(EFile::FileF), to_int(ERank::Rank1), EColour::empty, EPiece::empty);
			}

			else if (std::get<3>(PrevMove).first < std::get<0>(PrevMove).first) // ending file < start file, so castling Q side
			{
				board.setTeamColour(to_int(EFile::FileA), to_int(ERank::Rank1), EColour::white);
				board.setPieceType(to_int(EFile::FileA), to_int(ERank::Rank1), EPiece::rook);
				board.setPieceSprite(to_int(EFile::FileA), to_int(ERank::Rank1), EColour::white, EPiece::rook);

				board.setTeamColour(to_int(EFile::FileD), to_int(ERank::Rank1), EColour::empty);
				board.setPieceType(to_int(EFile::FileD), to_int(ERank::Rank1), EPiece::empty);
				board.setPieceSprite(to_int(EFile::FileD), to_int(ERank::Rank1), EColour::empty, EPiece::empty);
			}

		}
		else if (std::get<1>(PrevMove) == EColour::black) // black is the team that castled
		{
			// the king does not have "bColourKing_Unmoved" set to false until the other team makes their move, since
			// eliminateCastlingOptions() uses PrevMove but is called before PrevMove is overwritten (when a destination is clicked)

			if (std::get<3>(PrevMove).first > std::get<0>(PrevMove).first) // ending file > start file, so castling K side
			{
				board.setTeamColour(to_int(EFile::FileH), to_int(ERank::Rank8), EColour::black);
				board.setPieceType(to_int(EFile::FileH), to_int(ERank::Rank8), EPiece::rook);
				board.setPieceSprite(to_int(EFile::FileH), to_int(ERank::Rank8), EColour::black, EPiece::rook);

				board.setTeamColour(to_int(EFile::FileF), to_int(ERank::Rank8), EColour::empty);
				board.setPieceType(to_int(EFile::FileF), to_int(ERank::Rank8), EPiece::empty);
				board.setPieceSprite(to_int(EFile::FileF), to_int(ERank::Rank8), EColour::empty, EPiece::empty);
			}

			else if (std::get<3>(PrevMove).first < std::get<0>(PrevMove).first) // ending file < start file, so castling Q side
			{
				board.setTeamColour(to_int(EFile::FileA), to_int(ERank::Rank8), EColour::black);
				board.setPieceType(to_int(EFile::FileA), to_int(ERank::Rank8), EPiece::rook);
				board.setPieceSprite(to_int(EFile::FileA), to_int(ERank::Rank8), EColour::black, EPiece::rook);

				board.setTeamColour(to_int(EFile::FileD), to_int(ERank::Rank8), EColour::empty);
				board.setPieceType(to_int(EFile::FileD), to_int(ERank::Rank8), EPiece::empty);
				board.setPieceSprite(to_int(EFile::FileD), to_int(ERank::Rank8), EColour::empty, EPiece::empty);
			}
		}
	}

	// if en passant happened, reset the captured pawn
	else if (std::get<2>(PrevMove) == EPiece::pawn && std::get<5>(PrevMove) == EPiece::empty && \
		std::get<0>(PrevMove).first != std::get<3>(PrevMove).first)
	{
		// at this point, we know a pawn changed files without landing directly on a piece, so en passant happened
		if (std::get<1>(PrevMove) == EColour::white)
		{
			// white moved, so put a black pawn in the rank one smaller than the pawn's original destination
			board.setTeamColour(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second - 1, EColour::black);
			board.setPieceType(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second - 1, EPiece::pawn);
			board.setPieceSprite(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second - 1, EColour::black, EPiece::pawn);
		}
		else if (std::get<1>(PrevMove) == EColour::black)
		{
			// black moved, so put a black pawn in the rank one smaller than the pawn's original destination
			board.setTeamColour(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second + 1, EColour::white);
			board.setPieceType(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second + 1, EPiece::pawn);
			board.setPieceSprite(std::get<3>(PrevMove).first, std::get<3>(PrevMove).second + 1, EColour::white, EPiece::pawn);
		}
	}

	// the group below resets checkmate or stalemate upon undo if it has been activated
	WinnerTxt.setString("");
	PlayAgainButton.setSize(sf::Vector2f(0, 0));
	PlayAgainTxt.setString(sf::String(""));
	CancelButton.setSize(sf::Vector2f(0, 0));
	CancelTxt.setString(sf::String("")); // cancel button is only for if reset button is clicked, followed by undo
	StaleOrCheckmateTxt.setString("");
	ResetButton.setSize(ResetButtonSize);
	ResetTxt.setString("Reset Game");

	PrevMove = PrevPrevMove;
	switchTeam();

	return;
}
