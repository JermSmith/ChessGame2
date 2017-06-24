#pragma once
#include "Piece.h"
#include "PieceDefinitions.h"

template<typename EEnumClass>
int to_int(EEnumClass name)
{
	return static_cast<int>(name);
}
constexpr int PIX_MPL = 64;

class CGame
{
public:
	CGame(); // constructor

	void Reset();

	CPiece* GetBoardData(int, int);

	sf::Sprite* GetBoardTileSpr();

	void LeftClick(sf::Event);
	
private:

	std::vector<std::vector<CPiece>> BoardData;
	CPiece* ptrBoardData;

	sf::Texture BoardTexture;

	sf::Sprite BoardTileSpr;
	sf::Sprite* ptrBoardTileSpr;

	sf::Texture PiecesTexture;

	// used for LeftClick function
	EColour currentTeam = EColour::white;
	std::pair<int, int> oldClick = std::make_pair(0, 0);
	bool bClickOffBoard(std::pair<int, int>);
	std::vector<std::pair<int, int>> DestList = {};
	bool bIsDestination(std::pair<int, int>);
	void HighlightOff(std::pair<int, int>);
	void HighlightOn(std::pair<int, int>);
	void MoveFromTo(std::pair<int, int>, std::pair<int, int>);
	void switchTeam();
};