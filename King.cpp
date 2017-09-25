#include "King.h"

CKing::CKing(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::king);
}

void CKing::calcDestinations(CBoard* board)
{
	std::vector<std::pair<int, int>> dir = { std::make_pair(0, -1), std::make_pair(-1, -1), \
	std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), \
	std::make_pair(1, 0), std::make_pair(1, -1) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		// ensure the possible destination is on the chess board
		if ((Position.first + dir[i_].first >= 0) && (Position.first + dir[i_].first <= 7) && \
			(Position.second + dir[i_].second >= 0) && (Position.second + dir[i_].second <= 7))
		{
			if (board->getTeamColour(Position.first + dir[i_].first, Position.second + dir[i_].second) != Colour)
			{
				Destinations.push_back(std::make_pair(Position.first + dir[i_].first, Position.second + dir[i_].second));
			}
		}
	}

	return;
}
