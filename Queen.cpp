#include "Queen.h"

CQueen::CQueen(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::queen);
	SetRangeType(ERange::varies);
}

void CQueen::calcDestinations()
{
	Destinations = { std::make_pair(3,3), std::make_pair(3,4), std::make_pair(4,3), std::make_pair(4,4) };
	return;
}

std::vector<std::pair<int, int>> CQueen::GetDestinations() { return Destinations; }

bool CQueen::IsValidMove(std::vector<int>) { return false; }
void CQueen::Move(std::vector<int> MoveVector) { return; }