#pragma once
#include "BoardData.h"

CBoard::CBoard()
{
	ResetBoard();
}

// these functions receive coordinates in file & rank
void CBoard::setTeamColour(int file, int rank, EColour colour) { std::get<0>(BoardData[file][rank]) = colour; return; }
void CBoard::setPieceType(int file, int rank, EPiece piecetype) { std::get<1>(BoardData[file][rank]) = piecetype; return; }
void CBoard::setPieceSprite(int file, int rank, EColour colour, EPiece piecetype)
{
	std::get<2>(BoardData[file][rank]).setTextureRect(sf::IntRect(PIX_MPL*to_int(piecetype), \
		PIX_MPL*to_int(colour), PIX_MPL, PIX_MPL));
	return;
}
void CBoard::setBoardSprite(int file, int rank, sf::Sprite boardsprite) { std::get<3>(BoardData[file][rank]) = boardsprite; return; }

EColour CBoard::getTeamColour(int file, int rank) { return std::get<0>(BoardData[file][rank]); }
EPiece CBoard::getPieceType(int file, int rank) { return std::get<1>(BoardData[file][rank]); }
sf::Sprite CBoard::getPieceSprite(int file, int rank) { return std::get<2>(BoardData[file][rank]); }
sf::Sprite CBoard::getBoardSprite(int file, int rank) { return std::get<3>(BoardData[file][rank]); }

void CBoard::highlightOff(std::pair<int, int> position, std::vector<std::pair<int, int>> destlist)
{
	std::get<3>(BoardData[position.first][position.second]).setColor(sf::Color(255, 255, 255));

	for (unsigned int dest = 0; dest < destlist.size(); dest++)
	{
		std::get<3>(BoardData[destlist[dest].first][destlist[dest].second]).setColor(sf::Color(255, 255, 255));
	}

	return;
}

void CBoard::highlightOn(std::pair<int, int> position, std::vector<std::pair<int, int>> destlist)
{
	std::get<3>(BoardData[position.first][position.second]).setColor(sf::Color(255, 0, 255));

	for (unsigned int dest = 0; dest < destlist.size(); dest++)
	{
		std::get<3>(BoardData[destlist[dest].first][destlist[dest].second]).setColor(sf::Color(0, 127, 0));
	}

	return;
}

void CBoard::highlightToggle(std::pair<int, int> position, std::vector<std::pair<int, int>> destlist)
{
	if (std::get<3>(BoardData[position.first][position.second]).getColor() == sf::Color(255, 255, 255))
	{
		highlightOn(position, destlist);
	}
	else
	{
		highlightOff(position, destlist);
	}
	return;
}

void CBoard::movePiece(std::pair<int, int> oldposition, std::pair<int, int> newposition)
{
	int nfile = newposition.first;
	int nrank = newposition.second;
	int ofile = oldposition.first;
	int orank = oldposition.second;

	// if castling is happening...
	if (std::get<1>(BoardData[ofile][orank]) == EPiece::king && (abs(nfile - ofile) == 2))
	{
		// move the rook
		int Rnfile; // Rnrank is the same as nrank
		int Rofile; // Rorank is the same as orank
		if (nfile > ofile) // castling king side - place the rook one space to the left of king
		{
			Rofile = 7;
			Rnfile = nfile - 1;
		} 
		else // castling queen side - place the rook one space to the right of king
		{
			Rofile = 0;
			Rnfile = nfile + 1;
		}

		std::get<0>(BoardData[Rnfile][nrank]) = std::get<0>(BoardData[Rofile][orank]); // new piece colour becomes old piece colour
		std::get<0>(BoardData[Rofile][orank]) = EColour::empty; // old piece colour becomes empty


		std::get<1>(BoardData[Rnfile][nrank]) = std::get<1>(BoardData[Rofile][orank]); // new piece type becomes old piece type (rook)
		std::get<1>(BoardData[Rofile][orank]) = EPiece::empty; // old piece type becomes empty


		std::get<2>(BoardData[Rnfile][nrank]) = std::get<2>(BoardData[Rofile][orank]); // new piece sprite becomes old piece sprite (rook)
																					 // new piece sprite has location set to same as new piece itself
		std::get<2>(BoardData[Rnfile][nrank]).setPosition(static_cast<float>(PIX_MPL*Rnfile), static_cast<float>(PIX_MPL*(7 - nrank)));

		// old piece sprite has its sub-square in the texture set outside of the texture size (since empty = 9), so non-existent
		// Note that the line below could also use std::get<1>(BoardData[ofile][orank]) for PieceType, and get<0> for TeamColour.
		std::get<2>(BoardData[Rofile][orank]).setTextureRect(sf::IntRect(PIX_MPL*to_int(getPieceType(Rofile, orank)), \
			PIX_MPL*to_int(getTeamColour(Rofile, orank)), PIX_MPL, PIX_MPL));
	}
	// or if en passant is happening... i.e. moving piece is a pawn on a diagonal, but there is no piece in the destination
	else if (std::get<1>(BoardData[ofile][orank]) == EPiece::pawn && \
		std::get<1>(BoardData[nfile][nrank]) == EPiece::empty && ofile != nfile)
	{
		// then clear the data for the piece being captured by en passant
		
		if (std::get<0>(BoardData[ofile][orank]) == EColour::white) // moving piece is white
		{
			// Checking the colour of (ofile,orank) works because the data at the original position of the moving piece has not changed yet.
			// The data gets cleared in the "this always happens" section below.

			std::get<0>(BoardData[nfile][nrank - 1]) = EColour::empty;
			std::get<1>(BoardData[nfile][nrank - 1]) = EPiece::empty;
			std::get<2>(BoardData[nfile][nrank - 1]).setTextureRect(sf::IntRect(PIX_MPL*to_int(getPieceType(nfile, nrank - 1)), \
				PIX_MPL*to_int(getTeamColour(nfile, nrank - 1)), PIX_MPL, PIX_MPL));
		}
		else if (std::get<0>(BoardData[ofile][orank]) == EColour::black) // moving piece is black
		{
			std::get<0>(BoardData[nfile][nrank + 1]) = EColour::empty;
			std::get<1>(BoardData[nfile][nrank + 1]) = EPiece::empty;
			std::get<2>(BoardData[nfile][nrank + 1]).setTextureRect(sf::IntRect(PIX_MPL*to_int(getPieceType(nfile, nrank + 1)), \
				PIX_MPL*to_int(getTeamColour(nfile, nrank + 1)), PIX_MPL, PIX_MPL));
		}
	}

	// this always happens: move the piece data to the new position, and clear the original position

	std::get<0>(BoardData[nfile][nrank]) = std::get<0>(BoardData[ofile][orank]); // new piece colour becomes old piece colour
	std::get<0>(BoardData[ofile][orank]) = EColour::empty; // old piece colour becomes empty


	std::get<1>(BoardData[nfile][nrank]) = std::get<1>(BoardData[ofile][orank]); // new piece type becomes old piece type
	std::get<1>(BoardData[ofile][orank]) = EPiece::empty; // old piece type becomes empty


	std::get<2>(BoardData[nfile][nrank]) = std::get<2>(BoardData[ofile][orank]); // new piece sprite becomes old piece sprite
	// new piece sprite has location set to same as new piece itself
	std::get<2>(BoardData[nfile][nrank]).setPosition(static_cast<float>(PIX_MPL*nfile), static_cast<float>(PIX_MPL*(7 - nrank)));

	// old piece sprite has its sub-square in the texture set outside of the texture size (since empty = 9), so non-existent.
	// Note that the line below could also use std::get<1>(BoardData[ofile][orank]) for PieceType, and get<0> for TeamColour.
	std::get<2>(BoardData[ofile][orank]).setTextureRect(sf::IntRect(PIX_MPL*to_int(getPieceType(ofile, orank)), \
		PIX_MPL*to_int(getTeamColour(ofile, orank)), PIX_MPL, PIX_MPL));
}

void CBoard::ResetBoard()
{
	BoardData.resize(8, std::vector < std::tuple < EColour, EPiece, sf::Sprite, sf::Sprite > >(8));

	BoardTexture.loadFromFile("board_tiles.png");
	PiecesTexture.loadFromFile("pieces_tiled.png");

	// set starting colours, piece types and sprites for each space on the board
	for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file += 1)
	{
		for (int rank = to_int(ERank::Rank1); rank <= to_int(ERank::Rank8); rank += 1)
		{
			// colours
			if (rank <= 1) { std::get<0>(BoardData[file][rank]) = EColour::white; }
			else if (rank >= 6) { std::get<0>(BoardData[file][rank]) = EColour::black; }
			else { std::get<0>(BoardData[file][rank]) = EColour::empty; }

			// piece types
			if (rank == 0 || rank == 7)
			{
				if (file == 0 || file == 7) { std::get<1>(BoardData[file][rank]) = EPiece::rook; }
				else if (file == 1 || file == 6) { std::get<1>(BoardData[file][rank]) = EPiece::knight; }
				else if (file == 2 || file == 5) { std::get<1>(BoardData[file][rank]) = EPiece::bishop; }
				else if (file == 3) { std::get<1>(BoardData[file][rank]) = EPiece::queen; }
				else { std::get<1>(BoardData[file][rank]) = EPiece::king; }
			}
			else if (rank == 1 || rank == 6) { std::get<1>(BoardData[file][rank]) = EPiece::pawn; }
			else { std::get<1>(BoardData[file][rank]) = EPiece::empty; }

			// sprites for pieces
			std::get<2>(BoardData[file][rank]).setTexture(PiecesTexture);
			std::get<2>(BoardData[file][rank]).setTextureRect(sf::IntRect(PIX_MPL*to_int(getPieceType(file, rank)), \
				PIX_MPL*to_int(getTeamColour(file, rank)), PIX_MPL, PIX_MPL));
			std::get<2>(BoardData[file][rank]).setPosition(static_cast<float>(PIX_MPL*file), static_cast<float>(PIX_MPL*(7 - rank)));
			//** any empty space has its sprite's sub-square in the texture set outside of the texture size, so non-existent

			// sprites for board
			std::get<3>(BoardData[file][rank]).setTexture(BoardTexture); ////THERE IS NO ACTUAL OBJECT FOR THE BOARD SPRITE, ONLY A CONTAINER
																		 // dark square
			if ((file + rank) % 2 == 0)
			{
				std::get<3>(BoardData[file][rank]).setTextureRect(sf::IntRect(PIX_MPL, 0, PIX_MPL, PIX_MPL));
			}
			// light square
			else
			{
				std::get<3>(BoardData[file][rank]).setTextureRect(sf::IntRect(0, 0, PIX_MPL, PIX_MPL));
			}
			std::get<3>(BoardData[file][rank]).setPosition(static_cast<float>(PIX_MPL*file), static_cast<float>(PIX_MPL*(7 - rank)));
		}
	}
	return;
}
