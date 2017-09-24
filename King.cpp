#include "King.h"

CKing::CKing(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::king);
	SetRangeType(ERange::fixed);
}

void CKing::calcDestinations(CBoard* board)
{
	std::vector<std::pair<int, int>> dir = { std::make_pair(0, -1), std::make_pair(-1, -1), \
	std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1), \
	std::make_pair(1, 0), std::make_pair(1, -1) };
	
	std::pair<int, int> possibleDest;
	bool bOpposingKingBlocking; // reset for checking each destination.
	// (set to true if the opposing king is stopping this king from moving to the dest.)

	for (unsigned int i_ = 0; i_ < dir.size(); i_++)
	{
		bOpposingKingBlocking = false; // assume the opposing king does not restrict a destination.
		// (set to true if the opposing king does restrict a destination).
		
		// a location that could actually be a destination
		possibleDest = std::make_pair(Position.first + dir[i_].first, Position.second + dir[i_].second);

		// ensure the possible destination is on the chess board
		if ((possibleDest.first) >= 0 && (possibleDest.first <= 7) && \
			(possibleDest.second >= 0) && (possibleDest.second <= 7))
		{
			// ensure the possible destination does not contain a piece of the same colour
			if (board->getTeamColour(possibleDest.first, possibleDest.second) != Colour)
			{
				// a loop to check the 8 spaces adjacent to the possible destination
				for (unsigned int j_ = 0; j_ < dir.size(); j_++)
				{
					// ensure the space adjacent to the possible destination is on the chess board
					if ((possibleDest.first + dir[j_].first >= 0) && (possibleDest.first + dir[j_].first <= 7) && \
						(possibleDest.second + dir[j_].second >= 0) && (possibleDest.second + dir[j_].second <= 7))
					{
						if (board->getPieceType(possibleDest.first + dir[j_].first, possibleDest.second + dir[j_].second) == EPiece::king && \
							board->getTeamColour(possibleDest.first + dir[j_].first, possibleDest.second + dir[j_].second) != Colour)
						{
							// there is a king of the opposite colour adjacent to the proposed destination.
							bOpposingKingBlocking = true;
							break;
						}
					}
				}
				if (bOpposingKingBlocking == false) // the opposing king is not blocking this king from moving to the dest
				{
					Destinations.push_back(std::make_pair(possibleDest.first, possibleDest.second));
				}
			}
		}
	}
	return;
}
