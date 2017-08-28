
#include "Piece.h"
#include "PieceDefinitions.h"

CRook::CRook()
{
	SetPieceType(EPiece::rook);
	SetRangeType(ERange::varies);
}




CKnight::CKnight()
{
	SetPieceType(EPiece::knight);
	SetRangeType(ERange::fixed);
}




CBishop::CBishop()
{
	SetPieceType(EPiece::bishop);
	SetRangeType(ERange::varies);
}




CQueen::CQueen()
{
	SetPieceType(EPiece::queen);
	SetRangeType(ERange::varies);
}




CKing::CKing()
{
	SetPieceType(EPiece::king);
	SetRangeType(ERange::fixed);
}




CPawn::CPawn()
{
	SetPieceType(EPiece::pawn);
	SetRangeType(ERange::fixed);

	/*
	void calcDestinations()
	{
		Destinations = { std::make_pair(6,6), std::make_pair(6,1) };
	}
	*/

}


/*
class CPawn : public CPiece
{
public:

	void calcDestinations()
	{
		Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) };
	}

private:

	std::vector<std::pair<int, int>> Destinations;
};
*/

