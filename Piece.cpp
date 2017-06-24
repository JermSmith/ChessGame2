#pragma once
#include "Piece.h"

CPiece::CPiece()
{
	SetPieceType(EPiece::empty);
	SetColour(EColour::empty);
	SetRangeType(ERange::empty);
	return;
}

EColour CPiece::GetColour() { return Colour; }
EPiece CPiece::GetPieceType() { return PieceType; }
ERange CPiece::GetRangeType() { return RangeType; }
std::pair<int, int> CPiece::GetPosition() { return Position; }
sf::Sprite* CPiece::GetSprite() { ptrSprite = &Sprite; return ptrSprite; } // sets the pointer to point to Sprite, and returns the pointer
std::vector<std::pair<int, int>> CPiece::GetDestinations() // returns a vector of pairs of all valid destinations
{
	return Destinations;
}

// calculates destinations for the selected piece, and stores them in a vector of pairs, in the private property Destinations
void CPiece::calcDestinations()
{
	Destinations = { std::make_pair(4,4), std::make_pair(4,5), std::make_pair(5,4), std::make_pair(5,5), std::make_pair(6,6), std::make_pair(6,1) };
	return;
}

void CPiece::SetColour(EColour GivenColour) { Colour = GivenColour; return; }
void CPiece::SetPieceType(EPiece GivenPieceType) { PieceType = GivenPieceType; return; }
void CPiece::SetRangeType(ERange GivenRangeType) { RangeType = GivenRangeType; return; }
void CPiece::SetPosition(std::pair<int, int> position) { Position = position; return; }

/*bool CPiece::IsValidDestination(int file, int rank)
{
	return false;
}*/

void CPiece::Move(std::vector<int>)
{
	return;
}


/*void CPiece::highlightOff()
{
	this->ptrSprite->setColor(sf::Color(255, 255, 255));
	for (unsigned int dest = 0; dest < this->Destinations.size(); dest++)
	{
		
	}
}*/


