#pragma once
#include "Piece.h"

class CRook : public CPiece
{
public:
	CRook(EColour); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CRook::IsValidMove(std::vector<int>);
	void CRook::Move(std::vector<int>);

private:

};