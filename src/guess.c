#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "menu.h"
#include "util.h"
#include "guess.h"
#include "ansi.h"
#include "option.h"

const int difficultyInts[4] = {50, 100, 250, 1000};

GuessGameSession startGame(Difficulty difficulty) {
	srand(time(NULL));
	GuessGameSession game;
	game.guesses = 0;
	game.min = 1;
	game.max = difficultyInts[difficulty];
	game.difficulty = difficulty;
	game.result = (rand() % game.max) + game.min;
	int guess;
	bool already_ran = false;
	
	for (int i = 1; i <= 35; i++) {
		char* character = malloc(3);
		MOVECUR(itoa(i, character, 10), "1");
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_WHITE); printf("\n");
		free(character);
	}
	do {
		loadOnGuessesGame();
		MOVECUR("12", "1");
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_WHITE); printf("\r");
		if (!already_ran) {
			already_ran = true;
			MOVECUR("12", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_WHITE "Enter a guess between %d and %d: " COLOR_LIGHT_CYAN, game.min, game.max);
		}
		else if (already_ran) {
			MOVECUR("12", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_WHITE "Enter a guess between %d and %d: " COLOR_RED "%d", game.min, game.max, guess);
		}
		SHOWCUR;
		if(difficulty == NORMAL || difficulty == HARD) {
			MOVECUR("12", "53");
		} else if(difficulty == INSANE) {
			MOVECUR("12", "54");
		} else if(difficulty == EASY) {
			MOVECUR("12", "52");
		}
		printf(COLOR_LIGHT_CYAN);
		scanf("%d", &guess);
		HIDECUR;
		printf(COLOR_RESET);
		while (getchar() != '\n');
		if (guess > game.max || guess < game.min) {
			makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_RED); printf("\r");
			MOVECUR("13", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_RED "Please enter a number between %d and %d.\n" COLOR_RESET, game.min, game.max);
			continue;
		} else if (guess > game.result) {
			makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_RED); printf("\r");
			MOVECUR("13", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_RED "Too high! \n" COLOR_RESET);
		} else if (guess < game.result) {
			makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_RED); printf("\r");
			MOVECUR("13", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_RED "Too low! \n" COLOR_RESET);
		} else {
			makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_GREEN); printf("\r");
			MOVECUR("13", "20");
			printf(BG_COLOR_LIGHT_BLACK COLOR_GREEN "You got it!\n" COLOR_RESET);
		}
		game.guesses++;
		
	} while (guess != game.result);
	
	return game;
}

void guessesGame(Difficulty difficulty) {
	CLEAR;
	
	GuessGameSession game = startGame(difficulty);
	printf("\n");
	SETCOL("20");
	makeEmptyLine(BG_COLOR_BLACK); printf("\r");
	SETCOL("20");
	printf("Your guesses: " COLOR_CYAN "%d" COLOR_RESET, game.guesses);
	SETCOL("60");
	makeEmptyLine(BG_COLOR_LIGHT_BLACK); printf("\n");
	SETCOL("20");
	makeEmptyLine(BG_COLOR_BLACK); printf("\r");
	SETCOL("20");
	printf("Difficulty: " COLOR_CYAN "%s" COLOR_RESET, difficultiesPtr[game.difficulty]);
	SETCOL("60");
	makeEmptyLine(BG_COLOR_LIGHT_BLACK); printf("\n");
	printf("\n");
	SETCOL("20");
	
	loadAfterGuessesKeyMenu();
	
	OptionMenu optionMenu;
	optionMenu.title = "Choose";
	optionMenu.options = playModes;
	optionMenu.optionsSize = sizeof(playModes) / sizeof(playModes[0]);
	optionMenu.defaultOption = 2;
	optionMenu.useLine = 1;
	
	OpenOptionMenu userChoice = singleHorizontalOptionMenu(optionMenu, NULL);
	if (userChoice.value == 0 || userChoice.exit) {
		gameMenu();
	} else if (userChoice.value == 1) {
		guessesGame(difficulty);
	} else if (userChoice.value == 2) {
		guesserGame();
	}
}
