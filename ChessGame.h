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
	sf::RectangleShape* PassAlongQuitButton();
	sf::Text* PassAlongQuitTxt();

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
	sf::RectangleShape QuitButton;
	sf::Text QuitTxt;

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
	sf::RectangleShape* ptrQuitButton;
	sf::Text* ptrQuitTxt;

	EColour currentTeamColour = EColour::white;
	
	std::pair<int, int> kingPosition;

	// DestList is only used in the LeftClick function.
	// DestList is declared here so that it is not reset to empty every time LeftClick is called (its contents must be preserved).
	std::vector<std::pair<int, int>> DestList = {};

	std::pair<int, int> oldClick = std::make_pair(0, 0);

	sf::Vector2f ResetButtonTopLeft = { PIX_MPL * 8.5, PIX_MPL * 2 };
	sf::Vector2f ResetButtonSize = { PIX_MPL * 2, PIX_MPL * 0.875 };

	sf::Vector2f PlayAgainButtonTopLeft = { PIX_MPL * 8.125, PIX_MPL * 6 };
	sf::Vector2f PlayAgainButtonSize = { PIX_MPL * 1.5, PIX_MPL * 0.5 };

	sf::Vector2f QuitButtonTopLeft = { PIX_MPL * 9.75, PIX_MPL * 6 };
	sf::Vector2f QuitButtonSize = { PIX_MPL * 1, PIX_MPL * 0.5 };

	void ResetGame();

	bool bClickOffBoard(std::pair<int, int>);
	bool bClickOnReset(std::pair<int, int>);
	bool bClickOnPlayAgain(std::pair<int, int>);
	bool bClickOnQuit(std::pair<int, int>);

	std::pair<int, int> findKingPosition(EColour);

	bool bCheckIfCheck(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetBlockCheckSpots(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetDestListCheckingForPin(CPiece*);

	std::vector<std::pair<int, int>> RemoveDestinationsWhereKingInCheck(std::vector<std::pair<int, int>>);

	std::vector<std::pair<int, int>> ObtainValidDestinationsForAnyPiece(CPiece*);

	void CheckIfStaleOrCheckmate();

	void switchTeam();

	void checkPawnPromotion();

};