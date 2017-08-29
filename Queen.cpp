#include "Queen.h"

CQueen::CQueen()
{
	SetPieceType(EPiece::queen);
	SetRangeType(ERange::varies);
}

void CQueen::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CQueen::GetDestinations() { return Destinations; }

bool CQueen::IsValidMove(std::vector<int>) { return false; }
void CQueen::Move(std::vector<int> MoveVector) { return; }