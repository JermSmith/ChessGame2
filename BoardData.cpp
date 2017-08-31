#pragma once
#include "BoardData.h"

CBoard::CBoard()
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

			// sprites for board
			std::get<3>(BoardData[file][rank]).setTexture(BoardTexture); ////THERE IS NO ACTUAL OBJECT FOR THE BOARD SPRITE, ONLY A CONTAINER
			if ((file + rank) % 2 == 0) {
				std::get<3>(BoardData[file][rank]).setTextureRect(sf::IntRect(PIX_MPL, 0, PIX_MPL, PIX_MPL));
			} // dark square
			else { std::get<3>(BoardData[file][rank]).setTextureRect(sf::IntRect(0, 0, PIX_MPL, PIX_MPL)); } // light square
			std::get<3>(BoardData[file][rank]).setPosition(static_cast<float>(PIX_MPL*file), static_cast<float>(PIX_MPL*(7 - rank)));
			
		}
	}
}

void CBoard::setTeamColour(int file, int rank, EColour colour) { std::get<0>(BoardData[file][rank]) = colour; return; }
void CBoard::setPieceType(int file, int rank, EPiece piecetype) { std::get<1>(BoardData[file][rank]) = piecetype; return; }
void CBoard::setPieceSprite(int file, int rank, sf::Sprite piecesprite) { std::get<2>(BoardData[file][rank]) = piecesprite; }
void CBoard::setBoardSprite(int file, int rank, sf::Sprite boardsprite) { std::get<3>(BoardData[file][rank]) = boardsprite; }

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
		std::get<3>(BoardData[destlist[dest].first][destlist[dest].second]).setColor(sf::Color(255, 255, 0));
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

