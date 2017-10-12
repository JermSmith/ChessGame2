#pragma once
#include "BoardData.h"

class CPiece
{
public:
	CPiece(); // constructor
	CPiece(EColour);

	EColour GetColour();
	EPiece GetPieceType();
	std::pair<int, int> GetPosition();

	void SetColour(EColour);
	void SetPieceType(EPiece);
	void SetPosition(int, int);
	void SetDestinations(std::vector<std::pair<int, int>>);

	virtual void calcDestinations(CBoard*);
	virtual std::vector<std::pair<int, int>> GetDestinations();

protected:
	std::vector<std::pair<int, int>> Destinations;
		
	EColour Colour;
	EPiece PieceType;
	std::pair<int, int> Position;
};
