#include "Bishop.h"

CBishop::CBishop()
{
	SetPieceType(EPiece::bishop);
	SetRangeType(ERange::varies);
}

void CBishop::calcDestinations() { Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) }; }
std::vector<std::pair<int, int>> CBishop::GetDestinations() { return Destinations; }

bool CBishop::IsValidMove(std::vector<int>) { return false; }
void CBishop::Move(std::vector<int> MoveVector) { return; }