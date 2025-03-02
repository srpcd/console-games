#include <stdio.h>
#include "menu.h"
#include "ansi.h"

void makeEmptyLine(char* before) {
	for (int i = 0; i < 200; i++) {
		printf("%s " COLOR_RESET, before);
	}
}

void loadTicTacToeKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "19");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> Back      " COLOR_RESET);
	
	MOVECUR("24", "36");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Select" COLOR_RESET);
	
	MOVECUR("24", "60");
	printf(COLOR_WHITE BG_COLOR_RED "ARROWS -> Move " COLOR_RESET);
	
	printf("\033[u");
}

void loadGuessesKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "19");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> Back      " COLOR_RESET);
	
	MOVECUR("24", "36");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Select" COLOR_RESET);
	
	MOVECUR("24", "60");
	printf(COLOR_WHITE BG_COLOR_RED "ARROWS -> Move " COLOR_RESET);
	
	printf("\033[u");
}

void loadAfterGuessesKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "19");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> Back      " COLOR_RESET);
	
	MOVECUR("24", "36");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Select" COLOR_RESET);
	
	MOVECUR("24", "60");
	printf(COLOR_WHITE BG_COLOR_RED "ARROWS -> Move " COLOR_RESET);
	
	printf("\033[u");
}

void loadOnGuessesGame() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "17");
	printf(COLOR_WHITE BG_COLOR_RED "KEYBOARD -> NUM" COLOR_RESET);
	
	MOVECUR("24", "45");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Guess " COLOR_RESET);
	
	printf("\033[u");
}

void loadOnTicTacToeKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "13");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> End Game  " COLOR_RESET);
	
	MOVECUR("24", "36");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Select" COLOR_RESET);
	
	MOVECUR("24", "60");
	printf(COLOR_WHITE BG_COLOR_RED "ARROWS -> Move " COLOR_RESET);
	
	printf("\033[u");
}

void loadAfterTicTacToeKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "13");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> Main Menu " COLOR_RESET);
	
	MOVECUR("24", "36");
	printf(COLOR_WHITE BG_COLOR_RED "R -> Play Again" COLOR_RESET);
	
	MOVECUR("24", "60");
	printf(COLOR_WHITE BG_COLOR_RED "T -> Game Menu " COLOR_RESET);
	
	printf("\033[u");
}

void loadKeyMenu() {
	printf("\033[s");
	
	MOVECUR("25", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("24", "1"); makeEmptyLine(BG_COLOR_RED);
	MOVECUR("23", "1"); makeEmptyLine(BG_COLOR_RED);
	
	MOVECUR("24", "5");
	printf(COLOR_WHITE BG_COLOR_RED "Q -> Exit      " COLOR_RESET);
	
	MOVECUR("24", "25");
	printf(COLOR_WHITE BG_COLOR_RED "AB -> Options  " COLOR_RESET);
	
	MOVECUR("24", "51");
	printf(COLOR_WHITE BG_COLOR_RED "ENTER -> Select" COLOR_RESET);
	
	MOVECUR("24", "77");
	printf(COLOR_WHITE BG_COLOR_RED "ARROWS -> Move " COLOR_RESET);
	
	printf("\033[u");
}
