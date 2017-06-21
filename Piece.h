#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

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
};

class CPiece
{
public:
	CPiece(); // constructor

	virtual EColour GetColour();
	virtual EPiece GetPieceType();
	virtual ERange GetRangeType();
	virtual std::vector<int> GetPosition();
	virtual sf::Sprite* GetSprite(); // returns a pointer to an object of type sf::Sprite

	virtual void SetColour(EColour);
	virtual void SetPieceType(EPiece);
	virtual void SetRangeType(ERange);
	virtual void SetPosition(std::vector<int>);

	virtual bool IsValidMove(std::vector<int>);
	virtual void Move(std::vector<int>);

private:
	EColour Colour;
	EPiece PieceType;
	ERange RangeType;
	std::vector<int> Position;

	sf::Texture Texture;
	sf::IntRect TextureRect;
	sf::Sprite Sprite; // actual Sprite
	sf::Sprite* PointerToSprite; // points to Sprite
	sf::Color SpriteColour;

};