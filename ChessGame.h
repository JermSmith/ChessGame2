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
	
private:

	std::vector<std::vector<CPiece>> BoardData;
	CPiece* PointerToBoardData;

	sf::Texture BoardTexture;

	sf::Sprite BoardTileSpr;
	sf::Sprite* PointerToBoardTileSpr;

	sf::Texture PiecesTexture;
};