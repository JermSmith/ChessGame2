
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
}


std::vector<std::pair<int, int>> CPawn::GetValidDestinations()
{
	return{ std::make_pair(4,4), std::make_pair(5,5) };
}
