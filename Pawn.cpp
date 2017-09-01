#include "Pawn.h"

CPawn::CPawn(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::pawn);
	SetRangeType(ERange::fixed);
}

void CPawn::calcDestinations()
{
	switch (Colour)
	{
	case EColour::empty:
	{
		Destinations = {};
		break;
	}
	case EColour::white:
	{
		Destinations = { std::make_pair(Position.first, Position.second + 1) };
		break;
	}
	case EColour::black:
	{
		Destinations = { std::make_pair(Position.first, Position.second - 1) };
		break;
	}
	}
	//Destinations = { std::make_pair(Position.first, Position.second + to_int(Colour) * -2 + 1)}; // maps 0->1, -1->-1
	return;
}

std::vector<std::pair<int, int>> CPawn::GetDestinations() { return Destinations; }

bool CPawn::IsValidMove(std::vector<int>) { return false; }
void CPawn::Move(std::vector<int> MoveVector) { return; }

