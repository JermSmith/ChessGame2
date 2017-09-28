#pragma once
#include "Piece.h"

class CGame
{
public:
	CGame(); // constructor

	sf::Sprite* PassAlongPieceSprite(int, int);
	sf::Sprite* PassAlongBoardSprite(int, int);

	sf::Text* PassAlongTitleTxt();
	sf::Text* PassAlongCurrentTeamTxt();
	sf::Text* PassAlongCreditsTxt();
	sf::Text* PassAlongStaleOrCheckmateTxt();
	sf::Text* PassAlongWinnerTxt();
	sf::RectangleShape* PassAlongResetButton();
	sf::Text* PassAlongResetTxt();
	sf::RectangleShape* PassAlongPlayAgainButton();
	sf::Text* PassAlongPlayAgainTxt();
	sf::RectangleShape* PassAlongCancelButton();
	sf::Text* PassAlongCancelTxt();

	sf::Text* PassAlongPawnPromotionTxt();
	sf::RectangleShape* PassAlongPPQueenButton();
	sf::Text* PassAlongPPQueenTxt();
	sf::RectangleShape* PassAlongPPRookButton();
	sf::Text* PassAlongPPRookTxt();
	sf::RectangleShape* PassAlongPPBishopButton();
	sf::Text* PassAlongPPBishopTxt();
	sf::RectangleShape* PassAlongPPKnightButton();
	sf::Text* PassAlongPPKnightTxt();

	void LeftClick(sf::Event);

private:

	sf::Font font;

	sf::Sprite PieceSprite;
	sf::Sprite BoardTileSprite;
	sf::Text TitleTxt;
	sf::Text CurrentTeamTxt;
	sf::Text CreditsTxt;
	sf::Text StaleOrCheckmateTxt;
	sf::Text WinnerTxt;
	sf::RectangleShape ResetButton;
	sf::Text ResetTxt;
	sf::RectangleShape PlayAgainButton;
	sf::Text PlayAgainTxt;
	sf::RectangleShape CancelButton;
	sf::Text CancelTxt;
	// Pawn promotion GUI items
	sf::Text PawnPromotionTxt;
	sf::RectangleShape PPQueenButton;
	sf::Text PPQueenTxt;
	sf::RectangleShape PPRookButton;
	sf::Text PPRookTxt;
	sf::RectangleShape PPBishopButton;
	sf::Text PPBishopTxt;
	sf::RectangleShape PPKnightButton;
	sf::Text PPKnightTxt;

	sf::Sprite* ptrPieceSprite;
	sf::Sprite* ptrBoardTileSprite;
	sf::Text* ptrTitleTxt;
	sf::Text* ptrCurrentTeamTxt;
	sf::Text* ptrCreditsTxt;
	sf::Text* ptrStaleOrCheckmateTxt;
	sf::Text* ptrWinnerTxt;
	sf::RectangleShape* ptrResetButton;
	sf::Text* ptrResetTxt;
	sf::RectangleShape* ptrPlayAgainButton;
	sf::Text* ptrPlayAgainTxt;
	sf::RectangleShape* ptrCancelButton;
	sf::Text* ptrCancelTxt;
	// Pawn Promotion pointers for GUI
	sf::Text* ptrPawnPromotionTxt;
	sf::RectangleShape* ptrPPQueenButton;
	sf::Text* ptrPPQueenTxt;
	sf::RectangleShape* ptrPPRookButton;
	sf::Text* ptrPPRookTxt;
	sf::RectangleShape* ptrPPBishopButton;
	sf::Text* ptrPPBishopTxt;
	sf::RectangleShape* ptrPPKnightButton;
	sf::Text* ptrPPKnightTxt;

	EColour currentTeamColour = EColour::white;

	bool bCouldCastle_WhiteKSide = true;
	bool bCouldCastle_WhiteQSide = true;
	bool bCouldCastle_BlackKSide = true;
	bool bCouldCastle_BlackQSide = true;
	
	std::pair<int, int> kingPosition;

	// DestList is only used in the LeftClick function.
	// DestList is declared here so that it is not reset to empty every time LeftClick is called (its contents must be preserved).
	std::vector<std::pair<int, int>> DestList = {};

	std::pair<int, int> oldClick = std::make_pair(0, 0);

	sf::Vector2f ResetButtonTopLeft = { PIX_MPL * 8.5, PIX_MPL * 2 };
	sf::Vector2f ResetButtonSize = { PIX_MPL * 2, PIX_MPL * 0.875 };

	sf::Vector2f PlayAgainButtonTopLeft = { PIX_MPL * 8.125, PIX_MPL * 6 };
	sf::Vector2f PlayAgainButtonSize = { PIX_MPL * 1.5, PIX_MPL * 0.5 };

	sf::Vector2f CancelButtonTopLeft = { PIX_MPL * 9.75, PIX_MPL * 6 };
	sf::Vector2f CancelButtonSize = { PIX_MPL * 1, PIX_MPL * 0.5 };

	sf::Vector2f PPQueenButtonTopLeft = { PIX_MPL * 8.375, PIX_MPL * 5 };
	sf::Vector2f PPRookButtonTopLeft = { PIX_MPL * 9.625, PIX_MPL * 5 };
	sf::Vector2f PPBishopButtonTopLeft = { PIX_MPL * 8.375, PIX_MPL * 5.75 };
	sf::Vector2f PPKnightButtonTopLeft = { PIX_MPL * 9.625, PIX_MPL * 5.75 };
	sf::Vector2f PPButtonSize = { PIX_MPL * 1, PIX_MPL * 0.5 };

	void ResetGame();

	bool bClickOffBoard(std::pair<int, int>);
	bool bClickOnReset(std::pair<int, int>);
	bool bClickOnPlayAgain(std::pair<int, int>);
	bool bClickOnCancel(std::pair<int, int>);

	std::pair<int, int> findKingPosition(EColour);

	bool bCheckIfCheck(std::pair<int, int>, EColour);

	std::vector<std::pair<int, int>> GetBlockCheckSpots(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetDestListCheckingForPin(CPiece*);

	std::vector<std::pair<int, int>> RemoveDestinationsWhereKingInCheck(std::vector<std::pair<int, int>>);

	std::vector<std::pair<int, int>> ObtainValidDestinationsForAnyPiece(CPiece*);

	bool bCanCastleSide(int);

	void CheckIfStaleOrCheckmate();

	void switchTeam();

	void eliminateCastlingOptions(EPiece, std::pair<int, int>);

	void checkPawnPromotion();

};