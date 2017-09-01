#pragma once
#include "Piece.h"

class CKing : public CPiece
{
public:
	CKing(EColour); // constructor

	virtual void calcDestinations(CBoard*);

};