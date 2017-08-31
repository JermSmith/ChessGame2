#include "Pawn.h"

CPawn::CPawn(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::pawn);
	SetRangeType(ERange::fixed);
}

void CPawn::calcDestinations()
{
	Destinations = { std::make_pair(0,2), std::make_pair(1,2), std::make_pair(2,2), std::make_pair(3,2) };
	return;
}

std::vector<std::pair<int, int>> CPawn::GetDestinations() { return Destinations; }

bool CPawn::IsValidMove(std::vector<int>) { return false; }
void CPawn::Move(std::vector<int> MoveVector) { return; }

