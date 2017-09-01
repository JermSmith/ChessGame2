#include "King.h"

CKing::CKing(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::king);
	SetRangeType(ERange::fixed);
}

void CKing::calcDestinations(CBoard* board)
{
	Destinations = { std::make_pair(2,2), std::make_pair(2,3), std::make_pair(2,4), std::make_pair(2,5), \
		std::make_pair(5,2), std::make_pair(5,3), std::make_pair(5,4), std::make_pair(5,5) };
	return;
}
