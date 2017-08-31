#pragma once
#include <tuple>
#include "Piece.h"

class CBoard
{
public:
	CBoard(); // constructor

	void setTeamColour(int, int, EColour);
	void setPieceType(int, int, EPiece);
	void setPieceSprite(int, int, sf::Sprite);
	void setBoardSprite(int, int, sf::Sprite);
	
	EColour getTeamColour(int, int);
	EPiece getPieceType(int, int);
	sf::Sprite getPieceSprite(int, int);
	sf::Sprite getBoardSprite(int, int);

	void highlightOff(std::pair<int, int>, std::vector<std::pair<int, int>>);
	void highlightOn(std::pair<int, int>, std::vector<std::pair<int, int>>);
	void highlightToggle(std::pair<int, int>, std::vector<std::pair<int, int>>);


private:
	std::vector < std::vector < std::tuple < EColour, EPiece, sf::Sprite, sf::Sprite > > > BoardData;

	sf::Texture BoardTexture;
	sf::Texture PiecesTexture;
};