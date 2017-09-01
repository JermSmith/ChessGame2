#include "Knight.h"

CKnight::CKnight(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::knight);
	SetRangeType(ERange::fixed);
}

void CKnight::calcDestinations()
{
	Destinations = { std::make_pair(0,2), std::make_pair(2,2), std::make_pair(5,2), std::make_pair(7,2), \
		std::make_pair(0,5), std::make_pair(2,5), std::make_pair(5,5), std::make_pair(7,5) };
	return;
}

std::vector<std::pair<int, int>> CKnight::GetDestinations() { return Destinations; }

bool CKnight::IsValidMove(std::vector<int>) { return false; }
void CKnight::Move(std::vector<int> MoveVector) { return; }