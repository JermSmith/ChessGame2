#pragma once
#include "Piece.h"

class CPawn : public CPiece
{
public:
	CPawn(EColour); // constructor

	void calcDestinations(CBoard*);
};
