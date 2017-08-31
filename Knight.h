#pragma once
#include "Piece.h"

class CKnight : public CPiece
{
public:
	CKnight(EColour); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CKnight::IsValidMove(std::vector<int>);
	void CKnight::Move(std::vector<int>);

private:

};