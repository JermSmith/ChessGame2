#include "Bishop.h"

CBishop::CBishop(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::bishop);
	SetRangeType(ERange::varies);
}

void CBishop::calcDestinations()
{
	Destinations = { std::make_pair(6,1), std::make_pair(7,2), std::make_pair(4,1), std::make_pair(3,2), std::make_pair(2,3), \
		std::make_pair(1,4), std::make_pair(0,5) };
	return; 
}

std::vector<std::pair<int, int>> CBishop::GetDestinations() { return Destinations; }

bool CBishop::IsValidMove(std::vector<int>) { return false; }
void CBishop::Move(std::vector<int> MoveVector) { return; }