#pragma once

class CRook : public CPiece
{
public:
	CRook(); // constructor

	bool CRook::IsValidMove(std::vector<int> ProposedMoveVector)
	{
		return false;
	}

	void CRook::Move(std::vector<int> MoveVector)
	{
		return;
	}

private:

};

////////

class CKnight : public CPiece
{
public:
	CKnight(); // constructor

	bool CKnight::IsValidMove(std::vector<int>)
	{
		return false;
	}

	void CKnight::Move(std::vector<int> MoveVector)
	{
		return;
	}

private:

};

////////

class CBishop : public CPiece
{
public:
	CBishop(); // constructor

	bool CBishop::IsValidMove(std::vector<int>)
	{
		return false;
	}

	void CBishop::Move(std::vector<int> MoveVector)
	{
		return;
	}

private:

};

////////

class CQueen : public CPiece
{
public:
	CQueen(); // constructor

	bool CQueen::IsValidMove(std::vector<int>)
	{
		return false;
	}

	void CQueen::Move(std::vector<int> MoveVector)
	{
		return;
	}

private:

};

////////

class CKing : public CPiece
{
public:
	CKing(); // constructor

	bool CKing::IsValidMove(std::vector<int>)
	{
		return false;
	}

	void CKing::Move(std::vector<int> MoveVector)
	{
		return;
	}

private:

};

///////



class CPawn : public CPiece
{
public:
	CPawn(); // constructor

	//std::vector<std::pair<int, int>> calcDestinations();
	
	void calcDestinations()
	{
		Destinations = { std::make_pair(7,5), std::make_pair(7,3), std::make_pair(7,1) };
	}


	
	bool CPawn::IsValidMove(std::vector<int>)
	{
		return false;
	}

	void CPawn::Move(std::vector<int> MoveVector)
	{
		return;
	}
	

private:

	std::vector<std::pair<int, int>> Destinations;
};
