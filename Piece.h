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
	empty = 9,
};

class CPiece
{
public:
	CPiece(); // constructor

	EColour GetColour();
	EPiece GetPieceType();
	ERange GetRangeType();
	std::pair<int, int> GetPosition();
	sf::Sprite* GetSprite(); // returns a pointer to an object of type sf::Sprite
	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	void SetColour(EColour);
	void SetPieceType(EPiece);
	void SetRangeType(ERange);
	void SetPosition(std::pair<int, int>);
	void SetSprite(sf::Sprite *);

	void highlightOff();
	void highlightOnP();
	void highlightOnY();
	void highlightToggle();

	//bool IsValidDestination(int, int);
	void Move(std::vector<int>);

	sf::Sprite Sprite; // actual Sprite -- possibly to move to PRIVATE


protected:
	std::vector<std::pair<int, int>> Destinations;
	
	EColour Colour;
	EPiece PieceType;
	ERange RangeType;
	std::pair<int, int> Position;


private:
	sf::Texture Texture;
	sf::IntRect TextureRect;
	sf::Sprite* ptrSprite; // points to Sprite
	
};