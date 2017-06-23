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
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// check different event types
			if (event.type == sf::Event::Closed) { window.close(); }

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Game.LeftClick(event);
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

	// LOOP:
	//	receive player click (must be for valid team) - highlight piece
	//	determine valid destinations - highlight these squares
	//	receive player click
	//	either restart the loop, or place piece in new location
	return;
}