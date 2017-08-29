#pragma once
#include "Piece.h"

class CBishop : public CPiece
{
public:
	CBishop(); // constructor

	virtual void calcDestinations();
	virtual std::vector<std::pair<int, int>> GetDestinations();

	bool CBishop::IsValidMove(std::vector<int>);
	void CBishop::Move(std::vector<int>);

private:
	std::vector<std::pair<int, int>> Destinations;

};