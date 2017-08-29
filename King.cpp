#include "King.h"

CKing::CKing()
{
	SetPieceType(EPiece::king);
	SetRangeType(ERange::fixed);
}

void CKing::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CKing::GetDestinations() { return Destinations; }

bool CKing::IsValidMove(std::vector<int>) { return false; }
void CKing::Move(std::vector<int> MoveVector) { return; }