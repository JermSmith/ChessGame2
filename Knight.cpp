#include "Knight.h"

CKnight::CKnight()
{
	SetPieceType(EPiece::knight);
	SetRangeType(ERange::fixed);
}

void CKnight::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CKnight::GetDestinations() { return Destinations; }

bool CKnight::IsValidMove(std::vector<int>) { return false; }
void CKnight::Move(std::vector<int> MoveVector) { return; }