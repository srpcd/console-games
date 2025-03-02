#ifndef TICTACTOE_H
#define TICTACTOE
#include "util.h"

typedef struct {
	PlayerMode mode;
	Difficulty diff;
} TICTACTOE_GAME;

typedef enum {
	NO_WIN,
	DIAGONAL_FORWARDS,
	DIAGONAL_BACKWARDS,
	HORIZONTAL_1,
	HORIZONTAL_2,
	HORIZONTAL_3,
	VERTICAL_1,
	VERTICAL_2,
	VERTICAL_3
} TICTACTOE_DIRECTION;

typedef struct {
	int row;
	int column;
} CELL;

CELL get_selection(const int);
void cannot_put_here();
TICTACTOE_DIRECTION getWinningDirection(char);
void winCrossing(char, TICTACTOE_DIRECTION);
bool isWinner(char turn);
char getWinner();
void clear_cannot_put_here();
void show_board(const int, int);
void displayWinner(char);
void start_tictactoe(TICTACTOE_GAME);

#endif