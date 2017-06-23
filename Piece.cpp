#pragma once
#include "Piece.h"

CPiece::CPiece()
{
	SetPieceType(EPiece::empty);
	return;
}


EColour CPiece::GetColour() { return Colour; }
EPiece CPiece::GetPieceType() { return PieceType; }
ERange CPiece::GetRangeType() { return RangeType; }
std::pair<int, int> CPiece::GetPosition() { return Position; }
sf::Sprite* CPiece::GetSprite() { ptrSprite = &Sprite; return ptrSprite; } // sets the pointer to point to Sprite, and returns the pointer
std::vector<std::pair<int, int>> CPiece::GetValidDestinations() // returns a vector of pairs of all valid destinations
{
	return{ std::make_pair(0,0), std::make_pair(0,7), std::make_pair(7,0), std::make_pair(7,7) };

}

void CPiece::SetColour(EColour GivenColour) { Colour = GivenColour; return; }
void CPiece::SetPieceType(EPiece GivenPieceType) { PieceType = GivenPieceType; return; }
void CPiece::SetRangeType(ERange GivenRangeType) { RangeType = GivenRangeType; return; }
void CPiece::SetPosition(std::pair<int, int> position) { Position = position; return; }

bool CPiece::IsValidDestination(int file, int rank)
{
	return false;
}

void CPiece::Move(std::vector<int>)
{
	return;
}


