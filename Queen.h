#pragma once
#include "Piece.h"

class CQueen : public CPiece
{
public:
	CQueen(); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CQueen::IsValidMove(std::vector<int>);
	void CQueen::Move(std::vector<int>);

private:
	std::vector<std::pair<int, int>> Destinations;

};