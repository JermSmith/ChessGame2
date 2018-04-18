#pragma once
#include "Piece.h"

class CGame
{
public:
	CGame(); // constructor

	sf::Sprite* PassAlongPieceSprite(int, int);
	sf::Sprite* PassAlongBoardSprite(int, int);

	sf::Text* PassAlongTitleTxt();
	sf::Text* PassAlongCurrentTeamTxt();
	sf::Text* PassAlongCreditsTxt();
	sf::Text* PassAlongStaleOrCheckmateTxt();
	sf::Text* PassAlongWinnerTxt();
	sf::RectangleShape* PassAlongResetButton();
	sf::Text* PassAlongResetTxt();
	sf::RectangleShape* PassAlongPlayAgainButton();
	sf::Text* PassAlongPlayAgainTxt();
	sf::RectangleShape* PassAlongCancelButton();
	sf::Text* PassAlongCancelTxt();
	sf::RectangleShape* PassAlongUndoButton();
	sf::Text* PassAlongUndoTxt();
	sf::RectangleShape* PassAlongCompMoveButton();
	sf::Text* PassAlongCompMoveTxt();

	void LeftClick(sf::Event);

private:

	sf::Font font;

	// Main button GUI items

	sf::Sprite PieceSprite;
	sf::Sprite BoardTileSprite;
	sf::Text TitleTxt;
	sf::Text CurrentTeamTxt;
	sf::Text CreditsTxt;
	sf::Text StaleOrCheckmateTxt;
	sf::Text WinnerTxt;
	sf::RectangleShape ResetButton;
	sf::Text ResetTxt;
	sf::RectangleShape PlayAgainButton;
	sf::Text PlayAgainTxt;
	sf::RectangleShape CancelButton;
	sf::Text CancelTxt;
	sf::RectangleShape UndoButton;
	sf::Text UndoTxt;
	sf::RectangleShape CompMoveButton;
	sf::Text CompMoveTxt;

	// Main Button pointers for GUI

	sf::Sprite* ptrPieceSprite;
	sf::Sprite* ptrBoardTileSprite;
	sf::Text* ptrTitleTxt;
	sf::Text* ptrCurrentTeamTxt;
	sf::Text* ptrCreditsTxt;
	sf::Text* ptrStaleOrCheckmateTxt;
	sf::Text* ptrWinnerTxt;
	sf::RectangleShape* ptrResetButton;
	sf::Text* ptrResetTxt;
	sf::RectangleShape* ptrPlayAgainButton;
	sf::Text* ptrPlayAgainTxt;
	sf::RectangleShape* ptrCancelButton;
	sf::Text* ptrCancelTxt;
	sf::RectangleShape* ptrUndoButton;
	sf::Text* ptrUndoTxt;
	sf::RectangleShape* ptrCompMoveButton;
	sf::Text* ptrCompMoveTxt;

	// Pawn promotion GUI items
	sf::Text PawnPromotionTxt;
	sf::RectangleShape PPQueenButton;
	sf::Text PPQueenTxt;
	sf::RectangleShape PPRookButton;
	sf::Text PPRookTxt;
	sf::RectangleShape PPBishopButton;
	sf::Text PPBishopTxt;
	sf::RectangleShape PPKnightButton;
	sf::Text PPKnightTxt;

	// Pawn Promotion pointers for GUI
	sf::Text* ptrPawnPromotionTxt;
	sf::RectangleShape* ptrPPQueenButton;
	sf::Text* ptrPPQueenTxt;
	sf::RectangleShape* ptrPPRookButton;
	sf::Text* ptrPPRookTxt;
	sf::RectangleShape* ptrPPBishopButton;
	sf::Text* ptrPPBishopTxt;
	sf::RectangleShape* ptrPPKnightButton;
	sf::Text* ptrPPKnightTxt;

	EColour currentTeamColour = EColour::white;

	bool bWhiteKing_Unmoved = true;
	bool bBlackKing_Unmoved = true;
	bool bWRookKSide_Unmoved = true;
	bool bWRookQSide_Unmoved = true;
	bool bBRookKSide_Unmoved = true;
	bool bBRookQSide_Unmoved = true;
	
	std::pair<int, int> kingPosition;

	// DestList is only used in the LeftClick function.
	// DestList is declared here so that it is not reset to empty every time LeftClick is called (its contents must be preserved).
	std::vector<std::pair<int, int>> DestList = {};

	std::pair<int, int> oldClick = std::make_pair(0, 0);

	// The most recent move:
	//	get<0> is the start pos of piece,
	//	get<1> is original colour at start pos,
	//	get<2> is the original piecetype at start pos,
	//	get<3> is the end pos of piece,
	//	get<4> is the original colour at end pos,
	//	get<5> is the original piecetype at end pos.
	// The function is initialized as two white rooks at (0,0) so that pressing undo at the start has no effect.
	std::tuple<std::pair<int, int>, EColour, EPiece, std::pair<int, int>, EColour, EPiece > PrevMove = { \
		std::make_pair(0, 0), EColour::white, EPiece::rook, std::make_pair(0, 0), EColour::white, EPiece::rook };

	// this copy of PrevMove is used in the UndoPrevMove function, and specifically for undoing en passant.
	std::tuple<std::pair<int, int>, EColour, EPiece, std::pair<int, int>, EColour, EPiece > PrevPrevMove = PrevMove;

	bool bHasUndone = true; // used to ensure undo can only happen once

	sf::Vector2f ResetButtonTopLeft = { PIX_MPL * 8.5, PIX_MPL * 1.75 };
	sf::Vector2f ResetButtonSize = { PIX_MPL * 2, PIX_MPL * 0.875 };

	sf::Vector2f PlayAgainButtonTopLeft = { PIX_MPL * 8.125, PIX_MPL * 6 };
	sf::Vector2f PlayAgainButtonSize = { PIX_MPL * 1.5, PIX_MPL * 0.5 };

	sf::Vector2f CancelButtonTopLeft = { PIX_MPL * 9.75, PIX_MPL * 6 };
	sf::Vector2f CancelButtonSize = { PIX_MPL * 1, PIX_MPL * 0.5 };

	sf::Vector2f UndoButtonTopLeft = { PIX_MPL * 8.75, PIX_MPL * 2.75 };
	sf::Vector2f UndoButtonSize = { PIX_MPL * 1.5, PIX_MPL * 0.5 };

	sf::Vector2f CompMoveButtonTopLeft = { PIX_MPL * 8.5, PIX_MPL * 3.375 };
	sf::Vector2f CompMoveButtonSize = { PIX_MPL * 2, PIX_MPL * 0.625 };

	sf::Vector2f PPQueenButtonTopLeft = { PIX_MPL * 0.5, PIX_MPL * 1.125 };
	sf::Vector2f PPRookButtonTopLeft = { PIX_MPL * 2.5, PIX_MPL * 1.125 };
	sf::Vector2f PPBishopButtonTopLeft = { PIX_MPL * 0.5, PIX_MPL * 2.0625 };
	sf::Vector2f PPKnightButtonTopLeft = { PIX_MPL * 2.5, PIX_MPL * 2.0625 };
	sf::Vector2f PPButtonSize = { PIX_MPL * 1.5, PIX_MPL * 0.75 };

	void ResetGame();

	bool bClickOffBoard(std::pair<int, int>);
	bool bClickOnReset(std::pair<int, int>);
	bool bClickOnPlayAgain(std::pair<int, int>);
	bool bClickOnCancel(std::pair<int, int>);
	bool bClickOnUndo(std::pair<int, int>);
	bool bClickOnCompMove(std::pair<int, int>);

	bool bClickOnPPQueen(std::pair<int, int>);
	bool bClickOnPPRook(std::pair<int, int>);
	bool bClickOnPPBishop(std::pair<int, int>);
	bool bClickOnPPKnight(std::pair<int, int>);

	std::pair<std::pair<int, int>, std::pair<int, int>> CalculateOptimalMove(int);
	int CalculateBoardValue(EPiece piecetype = EPiece::empty); // optional argument -- if none given, then assumed value of empty
	void PerformCalculatedMove(std::pair<std::pair<int, int>, std::pair<int, int>>);

	std::pair<int, int> findKingPosition(EColour);

	bool bCheckIfCheck(std::pair<int, int>, EColour);

	std::vector<std::pair<int, int>> GetBlockCheckSpots(std::pair<int, int>);

	std::vector<std::pair<int, int>> GetDestListCheckingForPin(CPiece*);

	std::vector<std::pair<int, int>> RemoveDestinationsWhereKingInCheck(std::vector<std::pair<int, int>>);

	std::vector<std::pair<int, int>> ObtainValidDestinationsForAnyPiece(CPiece*);

	bool bCanCastleSide(int);

	void CheckIfStaleOrCheckmate();

	void switchTeam();

	void eliminateCastlingOptions();

	bool bIsPawnPromotion();
	void DoPawnPromotion(std::pair<int, int>);

	void UndoPrevMove();
};
