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

	EColour currentTeam = EColour::white;

	std::vector<std::pair<int, int>> DestList = {};

	std::pair<int, int> oldClick = std::make_pair(0, 0);

	bool bClickOffBoard(std::pair<int, int>);

	bool bIsDestination(std::pair<int, int>);

	std::pair<int, int> Kpos; // position of king, used immediately after calculation, specifically for checking pins
	std::pair<int, int> Kdir; // direction away from king to the piece in question which may be pinned
	bool bCheckForPin(std::pair<int, int>);
	std::vector<std::pair<int, int>> getPinDestList();

	void switchTeam();

	void checkPawnPromotion();


};