#include "Knight.h"

CKnight::CKnight(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::knight);
	SetRangeType(ERange::fixed);
}

void CKnight::calcDestinations(CBoard* board)
{
	std::vector<std::pair<int, int>> dir = { std::make_pair(-1, -2), std::make_pair(-2, -1), \
		std::make_pair(-2, 1), std::make_pair(-1, 2), std::make_pair(1, 2), std::make_pair(2, 1), \
		std::make_pair(2, -1), std::make_pair(1, -2) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		if ((Position.first + dir[i_].first) >= 0 && (Position.first + dir[i_].first <= 7) && \
			(Position.second + dir[i_].second >= 0) && (Position.second + dir[i_].second <= 7))
			if (board->getTeamColour(Position.first + dir[i_].first, Position.second + dir[i_].second) != Colour)
			{
				Destinations.push_back(std::make_pair(Position.first + dir[i_].first, \
					Position.second + dir[i_].second));
			}
	}
	return;
}
