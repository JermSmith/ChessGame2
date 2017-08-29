#pragma once
#include "Piece.h"

class CPawn : public CPiece
{
public:
	CPawn(); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CPawn::IsValidMove(std::vector<int>);
	void CPawn::Move(std::vector<int>);

private:
	std::vector<std::pair<int, int>> Destinations;

};