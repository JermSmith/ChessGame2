#pragma once
#include "Piece.h"

CPiece::CPiece()
{
	SetColour(EColour::empty);
	SetPieceType(EPiece::empty);
	SetRangeType(ERange::empty);
	return;
}

CPiece::CPiece(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::empty);
	return;
}

EColour CPiece::GetColour() { return Colour; }
EPiece CPiece::GetPieceType() { return PieceType; }
ERange CPiece::GetRangeType() { return RangeType; }
std::pair<int, int> CPiece::GetPosition() { return Position; }

void CPiece::calcDestinations() { return; }

//returns a vector of pairs of all valid destinations
std::vector<std::pair<int, int>> CPiece::GetDestinations() { return Destinations; }

void CPiece::SetColour(EColour GivenColour) { Colour = GivenColour; return; }
void CPiece::SetPieceType(EPiece GivenPieceType) { PieceType = GivenPieceType; return; }
void CPiece::SetRangeType(ERange GivenRangeType) { RangeType = GivenRangeType; return; }
void CPiece::SetPosition(int file, int rank) { Position = std::make_pair(file, rank); return; }
void CPiece::SetDestinations(std::vector<std::pair<int, int>> destlist) { Destinations = destlist; return; }

void CPiece::ToggleDestinations()
{
	if (Destinations != std::vector<std::pair<int, int>> {}) { Destinations = {}; }
	else { calcDestinations(); }
	return;
}

