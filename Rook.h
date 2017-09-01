#pragma once
#include "Piece.h"

class CRook : public CPiece
{
public:
	CRook(EColour); // constructor

	virtual void calcDestinations(CBoard*);

};