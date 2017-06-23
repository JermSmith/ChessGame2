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

	std::pair<int, int> PrevCoord = std::make_pair(0,0); // initial PrevClickCoord can never be clicked
};