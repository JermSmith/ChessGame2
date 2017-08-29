#include "Rook.h"

CRook::CRook()
{
	SetPieceType(EPiece::rook);
	SetRangeType(ERange::varies);
}

void CRook::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CRook::GetDestinations() { return Destinations; }

bool CRook::IsValidMove(std::vector<int>) { return false; }
void CRook::Move(std::vector<int> MoveVector) { return; }