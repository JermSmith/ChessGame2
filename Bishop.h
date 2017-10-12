#pragma once
#include "Piece.h"

class CBishop : public CPiece
{
public:
	CBishop(EColour); // constructor

	virtual void calcDestinations(CBoard*);
};
