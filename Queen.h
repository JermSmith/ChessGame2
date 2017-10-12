#pragma once
#include "Piece.h"

class CQueen : public CPiece
{
public:
	CQueen(EColour); // constructor

	virtual void calcDestinations(CBoard*);
};
