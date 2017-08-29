#include "Pawn.h"

CPawn::CPawn()
{
	SetPieceType(EPiece::pawn);
	SetRangeType(ERange::fixed);
}

void CPawn::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CPawn::GetDestinations() { return Destinations; }

bool CPawn::IsValidMove(std::vector<int>) { return false; }
void CPawn::Move(std::vector<int> MoveVector) { return; }

