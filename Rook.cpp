#include "Rook.h"

CRook::CRook(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::rook);
	SetRangeType(ERange::varies);
}

void CRook::calcDestinations()
{
	Destinations = { std::make_pair(7,2), std::make_pair(7,3), std::make_pair(7,4), std::make_pair(7,5), std::make_pair(7, 6)};
	return;
}

std::vector<std::pair<int, int>> CRook::GetDestinations() { return Destinations; }

bool CRook::IsValidMove(std::vector<int>) { return false; }
void CRook::Move(std::vector<int> MoveVector) { return; }