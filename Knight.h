#pragma once
#include "Piece.h"

class CKnight : public CPiece
{
public:
	CKnight(EColour); // constructor

	virtual void calcDestinations(CBoard*);
};
