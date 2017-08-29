#pragma once
#include "ChessGame.h"

void PlayGame();

CGame Game;

// main file
int main()
{
	PlayGame();
	return 0;
}

void PlayGame()
{
	sf::RenderWindow window(sf::VideoMode(PIX_MPL * 11, PIX_MPL * 8), "Chess Game");
	//sf::View defaultView(window.getDefaultView());

	while (window.isOpen())
	{
		bool bGameIsWon = false;
		while (!bGameIsWon)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// check different event types
				if (event.type == sf::Event::Closed)
				{
					bGameIsWon = true;
					window.close();
				}

				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						Game.LeftClick(event);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						window.setSize(sf::Vector2u(PIX_MPL * 11, PIX_MPL * 8));
						window.setPosition(sf::Vector2i(127, 127));
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
					window.draw(*Game.GetBoardDataSprite(file, rank)); // draw the Sprite pointed at by GetSprite();
					//window.draw(Game.GetBoardData(file, rank)->Sprite);
				}
			}

			window.display();
		}
	}
	// LOOP:
	//	receive player click (must be for valid team) - highlight piece
	//	determine valid destinations - highlight these squares
	//	receive player click
	//	either restart the loop, or place piece in new location
	return;
}