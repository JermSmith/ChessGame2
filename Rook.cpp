#include "Rook.h"

CRook::CRook(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::rook);
	SetRangeType(ERange::varies);
}

void CRook::calcDestinations(CBoard* board)
{
	Destinations = { std::make_pair(7,2), std::make_pair(7,3), std::make_pair(7,4), std::make_pair(7,5), std::make_pair(7, 6), \
		std::make_pair(0,2), std::make_pair(1,2), std::make_pair(2,2), std::make_pair(3,2), std::make_pair(4,2), \
		std::make_pair(5,2), std::make_pair(6,2), std::make_pair(0,5), std::make_pair(1,5), std::make_pair(2,5), \
		std::make_pair(3,5), std::make_pair(4,5), std::make_pair(5,5), std::make_pair(6,5), std::make_pair(3,3), \
		std::make_pair(3,4), std::make_pair(4,3), std::make_pair(4,4) };
	return;
}
