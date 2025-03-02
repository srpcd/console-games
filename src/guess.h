#ifndef GUESS_H
#define GUESS_H

#include "util.h"

typedef struct {
	int guesses;
	short max;
	short min;
	short result;
	Difficulty difficulty;
} GuessGameSession;

GuessGameSession startGame(Difficulty);
void guessesGame(Difficulty);

#endif
