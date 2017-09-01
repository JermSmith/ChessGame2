#pragma once
/*
#include <iostream>
#include <SFML/Graphics.hpp>
*/
#include "BoardData.h"

/*
template<typename EEnumClass>
int to_int(EEnumClass name)
{
	return static_cast<int>(name);
}
constexpr int PIX_MPL = 64;

//enum classes:
//ERank (rank 1=0, rank 8=7)
//EFile (file A=0, file H=7)
//EColour (team)
//EPiece (rook, knight, etc.)
//ERangeType (varies or fixed)


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
*/

class CPiece
{
public:
	CPiece(); // constructor
	CPiece(EColour);

	EColour GetColour();
	EPiece GetPieceType();
	ERange GetRangeType();
	std::pair<int, int> GetPosition();

	void SetColour(EColour);
	void SetPieceType(EPiece);
	void SetRangeType(ERange);
	void SetPosition(int, int);
	void SetDestinations(std::vector<std::pair<int, int>>);

	virtual void calcDestinations(CBoard*);
	virtual std::vector<std::pair<int, int>> GetDestinations();

protected:
	std::vector<std::pair<int, int>> Destinations;
		
	EColour Colour;
	EPiece PieceType;
	ERange RangeType;
	std::pair<int, int> Position;

private:


};