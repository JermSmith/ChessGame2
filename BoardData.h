#pragma once
#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>
//#include "Piece.h"


template<typename EEnumClass>
int to_int(EEnumClass name)
{
	return static_cast<int>(name);
}
constexpr int PIX_MPL = 64;

/* enum classes:
ERank (rank 1=0, rank 8=7)
EFile (file A=0, file H=7)
EColour (team)
EPiece (rook, knight, etc.)
ERangeType (varies or fixed)
*/

enum class ERank : int
{
	Rank1 = 0,
	Rank2 = 1,
	Rank3 = 2,
	Rank4 = 3,
	Rank5 = 4,
	Rank6 = 5,
	Rank7 = 6,
	Rank8 = 7,
};
enum class EFile : int
{
	FileA = 0,
	FileB = 1,
	FileC = 2,
	FileD = 3,
	FileE = 4,
	FileF = 5,
	FileG = 6,
	FileH = 7,
};
enum class EColour : int
{
	white = 0,
	black = 1,
	empty = 9,
};
enum class EPiece : int
{
	rook = 0,
	knight = 1,
	bishop = 2,
	queen = 3,
	king = 4,
	pawn = 5,
	empty = 9,
};
enum class ERange : int
{
	varies = 0,
	fixed = 1,
	empty = 9,
};


class CBoard
{
public:
	CBoard(); // constructor

	void ResetBoard();

	void setTeamColour(int, int, EColour);
	void setPieceType(int, int, EPiece);
	void setPieceSprite(int, int, EColour, EPiece);
	void setBoardSprite(int, int, sf::Sprite);
	
	EColour getTeamColour(int, int);
	EPiece getPieceType(int, int);
	sf::Sprite getPieceSprite(int, int);
	sf::Sprite getBoardSprite(int, int);

	void highlightOff(std::pair<int, int>, std::vector<std::pair<int, int>>);
	void highlightOn(std::pair<int, int>, std::vector<std::pair<int, int>>);
	void highlightToggle(std::pair<int, int>, std::vector<std::pair<int, int>>);

	void movePiece(std::pair<int, int>, std::pair<int, int>);

private:	
	std::vector < std::vector < std::tuple < EColour, EPiece, sf::Sprite, sf::Sprite > > > BoardData;

	sf::Texture BoardTexture;
	sf::Texture PiecesTexture;
};