#pragma once
#include "Piece.h"

CPiece::CPiece()
{
	return;
}


EColour CPiece::GetColour() { return Colour; }
EPiece CPiece::GetPieceType() { return PieceType; }
ERange CPiece::GetRangeType() { return RangeType; }
std::vector<int> CPiece::GetPosition() { return Position; }
sf::Sprite* CPiece::GetSprite() { PointerToSprite = &Sprite; return PointerToSprite; }
// sets the pointer to point to Sprite, and returns the pointer

void CPiece::SetColour(EColour GivenColour) { Colour = GivenColour; return; }
void CPiece::SetPieceType(EPiece GivenPieceType) { PieceType = GivenPieceType; return; }
void CPiece::SetRangeType(ERange GivenRangeType) { RangeType = GivenRangeType; return; }
void CPiece::SetPosition(std::vector<int> GivenPosition) { Position = GivenPosition; return; }

bool CPiece::IsValidMove(std::vector<int>)
{
	return false;
}

void CPiece::Move(std::vector<int>)
{
	return;
}


