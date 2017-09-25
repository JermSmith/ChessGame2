#include "Queen.h"

CQueen::CQueen(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::queen);
}

void CQueen::calcDestinations(CBoard* board)
{
	std::vector<std::pair<int, int>> dir = { std::make_pair(-1, -1), std::make_pair(-1, 0), \
		std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(1, 0), \
		std::make_pair(1, -1), std::make_pair(0, -1) };

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		std::pair<int, int> newPos = Position;

		while ((newPos.first + dir[i_].first) >= 0 && (newPos.first + dir[i_].first <= 7) && \
			(newPos.second + dir[i_].second >= 0) && (newPos.second + dir[i_].second <= 7))
		{
			// next piece in the line is empty, so add the space to Destinations and go to next space in line
			if (board->getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) == EColour::empty)
			{
				Destinations.push_back(std::make_pair(newPos.first + dir[i_].first, \
					newPos.second + dir[i_].second));
			}
			// next piece in the line is not empty but is different team colour
			else if (board->getTeamColour(newPos.first + dir[i_].first, newPos.second + dir[i_].second) != Colour)
			{
				Destinations.push_back(std::make_pair(newPos.first + dir[i_].first, \
					newPos.second + dir[i_].second)); // add this space, then the line is done
				break; // leave the while loop, because that straight line is done
			}
			else // next piece in the line is the same team colour, so done the line
			{
				break;
			}

			newPos = std::make_pair(newPos.first + dir[i_].first, newPos.second + dir[i_].second);
		}
	}
	return;
}
