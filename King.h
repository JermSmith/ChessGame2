#pragma once
#include "Piece.h"

class CKing : public CPiece
{
public:
	CKing(); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CKing::IsValidMove(std::vector<int>);
	void CKing::Move(std::vector<int>);

private:
	std::vector<std::pair<int, int>> Destinations;

};