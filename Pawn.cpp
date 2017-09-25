#include "Pawn.h"

CPawn::CPawn(EColour colour)
{
	SetColour(colour);
	SetPieceType(EPiece::pawn);
}

void CPawn::calcDestinations(CBoard* board)
{
	int one = to_int(Colour)*-2 + 1; // maps 0 (white)-> +1; maps 1 (black)-> -1

	if (Colour == EColour::empty) // calcDestinations called for empty square
	{
		Destinations = {};
	}
	else // calcDestinations called for square with a black or white piece
	{
		if (board->getPieceType(Position.first, Position.second + one) == EPiece::empty) // square directly in front is empty
		{
			Destinations.push_back(std::make_pair(Position.first, Position.second + one)); // add that square to destinations
			switch (Colour) // this switch is to check for 2-space advance on first move
			{
			case EColour::white: //starting rank is 2 for white
			{
				if (Position.second == 1 && \
					board->getPieceType(Position.first, Position.second + one + one) == EPiece::empty)
				{
					Destinations.push_back(std::make_pair(Position.first, Position.second + one + one));
				}
				break;
			}
			case EColour::black: //starting rank is 7 for black
			{
				if (Position.second == 6 && \
					board->getPieceType(Position.first, Position.second + one + one) == EPiece::empty)
				{
					Destinations.push_back(std::make_pair(Position.first, Position.second + one + one));
				}
				break;
			}
			}
		}
		if (Position.first != 0 && Position.first != 7) // pawn not in file A or H, so can check files to left and right for capture
		{
			if (board->getTeamColour(Position.first - 1, Position.second + one) != EColour::empty && \
				board->getTeamColour(Position.first - 1, Position.second + one) != Colour) 
			{
				// left diagonal square neither empty nor same colour (so different colour)
				Destinations.push_back(std::make_pair(Position.first - 1, Position.second + one));
			}
			if (board->getTeamColour(Position.first + 1, Position.second + one) != EColour::empty && \
				board->getTeamColour(Position.first + 1, Position.second + one) != Colour) 
			{
				// right diagonal square neither empty nor same colour (so different colour)
				Destinations.push_back(std::make_pair(Position.first + 1, Position.second + one));
			}
		}
		else if (Position.first == 0) // pawn in file A, so only check file to right
		{
			if (board->getTeamColour(Position.first + 1, Position.second + one) != EColour::empty && \
				board->getTeamColour(Position.first + 1, Position.second + one) != Colour) // see earlier comments
			{
				Destinations.push_back(std::make_pair(Position.first + 1, Position.second + one));
			}
		}
		else //pawn in file H, so only check file to left
		{
			if (board->getTeamColour(Position.first - 1, Position.second + one) != EColour::empty && \
				board->getTeamColour(Position.first - 1, Position.second + one) != Colour) // see earlier comments
			{
				Destinations.push_back(std::make_pair(Position.first - 1, Position.second + one));
			}
		}
	}
	return;
}

//std::vector<std::pair<int, int>> CPawn::GetDestinations() { return Destinations; }

//bool CPawn::IsValidMove(std::vector<int>) { return false; }
//void CPawn::Move(std::vector<int> MoveVector) { return; }

