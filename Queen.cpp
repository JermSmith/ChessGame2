#include "Queen.h"

CQueen::CQueen(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::queen);
	SetRangeType(ERange::varies);
}

void CQueen::calcDestinations(CBoard* board)
{
	Destinations = { std::make_pair(3,3), std::make_pair(3,4), std::make_pair(4,3), std::make_pair(4,4) };
	return;
}
