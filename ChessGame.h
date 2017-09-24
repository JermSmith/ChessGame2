#pragma once
#include "Piece.h"

class CGame
{
public:
	CGame(); // constructor

	sf::Sprite* PassAlongPieceSprite(int, int);
	sf::Sprite* PassAlongBoardSprite(int, int);

	void LeftClick(sf::Event);

private:

	sf::Sprite PieceSprite;
	sf::Sprite BoardTileSprite;
	sf::Sprite* ptrPieceSprite;
	sf::Sprite* ptrBoardTileSprite;

	EColour currentTeamColour = EColour::white;
	
	std::pair<int, int> kingPosition;

	// DestList is only used in the LeftClick function.
	// DestList is declared here so that it is not reset to empty every time LeftClick is called (its contents must be preserved).
	std::vector<std::pair<int, int>> DestList = {};

	std::pair<int, int> oldClick = std::make_pair(0, 0);

	bool bClickOffBoard(std::pair<int, int>);

	std::pair<int, int> findKingPosition(EColour);

	bool bCheckIfCheck(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetBlockCheckSpots(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetDestListCheckingForPin(CPiece*);

	std::vector<std::pair<int, int>> RemoveDestinationsWhereKingInCheck(std::vector<std::pair<int, int>>);

	std::vector<std::pair<int, int>> ObtainValidDestinationsForAnyPiece(CPiece*);

	void switchTeam();

	void checkPawnPromotion();


};