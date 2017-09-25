#pragma once
#include "ChessGame.h"
#include "BoardData.h"

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
		bool bGameIsOver = false;
		while (!bGameIsOver)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// check different event types
				if (event.type == sf::Event::Closed)
				{
					bGameIsOver = true;
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
						window.setPosition(sf::Vector2i(331, 128));
					}
				}
			}

			window.clear();

			// loop through and draw all spaces on board
			for (int file = to_int(EFile::FileA); file <= to_int(EFile::FileH); file++)
			{
				for (int rank = to_int(ERank::Rank1); rank <= to_int(ERank::Rank8); rank++)
				{
					window.draw(*Game.PassAlongBoardSprite(file, rank)); // draw the background associated with that (file, rank)
					window.draw(*Game.PassAlongPieceSprite(file, rank)); // draw the piece sprite associated with that (file, rank)
					window.draw(*Game.PassAlongTitleTxt()); // draw the title
					window.draw(*Game.PassAlongCurrentTeamTxt()); // display whose turn it is
					window.draw(*Game.PassAlongCreditsTxt()); // draw the credits
					window.draw(*Game.PassAlongStaleOrCheckmateTxt()); // draw a potential checkmate message
					window.draw(*Game.PassAlongWinnerTxt());
					window.draw(*Game.PassAlongResetButton());
					window.draw(*Game.PassAlongResetTxt());
					window.draw(*Game.PassAlongPlayAgainButton());
					window.draw(*Game.PassAlongPlayAgainTxt());
					window.draw(*Game.PassAlongQuitButton());
					window.draw(*Game.PassAlongQuitTxt());
				}
			}

			window.display();
		}
	}

	return;
}