#pragma once
#include "ChessGame.h"

// main file
int main()
{
	CGame Game;

	sf::RenderWindow window(sf::VideoMode(PIX_MPL * 11, PIX_MPL * 8), "Chess Game");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int xCoord = event.mouseButton.x;
					int yCoord = event.mouseButton.y;
					int file = static_cast<int>(floor(xCoord / PIX_MPL));
					int rank = 7 - static_cast<int>(floor(yCoord / PIX_MPL));
					int selectedTeam = to_int(Game.GetBoardData(file, rank)->GetColour());
					int selectedPiece = to_int(Game.GetBoardData(file, rank)->GetPieceType());

					sf::Color OriginalShade = Game.GetBoardData(file, rank)->GetSprite()->getColor();
					if (OriginalShade == sf::Color(255, 255, 255)) //white
					{
						Game.GetBoardData(file, rank)->GetSprite()->setColor(sf::Color(255, 255, 0)); //yellow
					}
					else
					{
						Game.GetBoardData(file, rank)->GetSprite()->setColor(sf::Color(255, 255, 255)); //white
					}
				}
			}
		}

		window.clear();
		window.draw(*Game.GetBoardTileSpr()); //draw checkered background

		// loop through and draw all spaces on board
		for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file++)
		{
			for (int rank = to_int(ERank::Rank1); rank <= to_int(ERank::Rank8); rank++)
			{
				window.draw(*Game.GetBoardData(file, rank)->GetSprite()); // draw the Sprite pointed at by GetSprite();
			}
		}

		window.display();
	}

	return 0;
}
