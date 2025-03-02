#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "shape.h"
#include "main.h"
#include "menu.h"
#include "guess.h"
#include "util.h"
#include "ansi.h"
#include "option.h"
#include "tictactoe.h"

#ifdef DEBUG
	#pragma message("Debug is enabled")
#endif

char straightLine[42];
char *difficulties[4] = {"Easy", "Normal", "Hard", "Insane"};
char *difficultiesWRandom[5] = {"Easy", "Normal", "Hard", "Insane", "Randomly"};
char *modes[1] = {"Player vs Player"};
char **difficultiesPtr = difficulties;
char *playModes[3] = {"Main Menu", "Play Again", "New Game"};

int main(int argc, char *argv[]) {
	setupAnsi();
	warningToNotResize();
	setupVariables();
	mainMenu();
	goodbyeText();
	restoreOldState();
	return 0;
}

void goodbyeText() {
	CLEAR;
	
	char *shape1[] = {
		"             AAAAAAAA   BBBBBBBB   CCCCCCCC  DDDDDD    EEEEEE    FF    FF  XXXXXXXX",
		"             AA         BB    BB   CC    CC  DD    DD  EE    EE   FF  FF   XX      ",
		"             AAAAAAAA   BB    BB   CC    CC  DD    DD  EEEEEE      FFFF    XXXXXXXX",
		"             AA    AA   BB    BB   CC    CC  DD    DD  EE    EE     FF     XX      ",
		"             AAAAAAAA   BBBBBBBB   CCCCCCCC  DDDDDD    EEEEEE       FF     XXXXXXXX",
	};
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printShape(shape1, 5, 0);
	usleep(500000);
	CLEAR;
	
	char *shape2[] = {
		"             BBBBBBBB   AAAAAAAA   DDDDDDDD  CCCCCC    FFFFFF    XX    XX  EEEEEEEE",
		"             BB         AA    AA   DD    DD  CC    CC  FF    FF   XX  XX   EE      ",
		"             BBBBBBBB   AA    AA   DD    DD  CC    CC  FFFFFF      XXXX    EEEEEEEE",
		"             BB    BB   AA    AA   DD    DD  CC    CC  FF    FF     XX     EE      ",
		"             BBBBBBBB   AAAAAAAA   DDDDDDDD  CCCCCC    FFFFFF       XX     EEEEEEEE",
	};
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printShape(shape2, 5, 0);
	usleep(500000);
}

bool waitForGetch(int interval, int max) {
	for (int i = interval; i <= max; i += interval) {
		char flch = flushGetch();
		if (flch != 0) {
			return true;
		}
		usleep(interval);
	}
	return false;
}

void mainMenu() {
	CLEAR;
	
	char *shape[] = {
		"               RRRRRRR   RRRRRRR   RRR   RR   RRRRRRR   RRRRRRR   RR        RRRRRRR",
		"               RR        RR   RR   RR R  RR   RR        RR   RR   RR        RR     ",
		"               RR        RR   RR   RR  R RR   RRRRRRR   RR   RR   RR        RRRRRRR",
		"               RR        RR   RR   RR   RRR        RR   RR   RR   RR        RR     ",
		"               RRRRRRR   RRRRRRR   RR    RR   RRRRRRR   RRRRRRR   RRRRRRR   RRRRRRR",
		"                                                                                   ",
		"                         RRRRRRR    RRRRR    RR    RR   RRRRRRR   RRRRRRR          ",
		"                         RR        RR   RR   RRR  RRR   RR        RR               ",
		"                         RRRRRRR   RRRRRRR   RR RR RR   RRRRRRR   RRRRRRR          ",
		"                         RR   RR   RR   RR   RR    RR   RR             RR          ",
		"                         RRRRRRR   RR   RR   RR    RR   RRRRRRR   RRRRRRR          "
	};
	MOVECUR("4", "1");
	printShape(shape, 11, 0);
	
	setPlayButton(true);
    
    while (1) {
        if (waitForGetch(50000, 1000000)) {
        	break;
		};
		MOVECUR("4", "1");
		printShape(shape, 11, 0);
    }
	for (int i = 0; i < 6; i++) setPlayButton(i % 2);
	
	CLEAR;
	sleep(1);
	
	gameMenu();
}

void setPlayButton(bool isWhite) {
	usleep(50000);
	if (isWhite){
		MOVECUR("22", "42");
		printf(BG_COLOR_WHITE COLOR_BLACK "                \n" COLOR_RESET);
		MOVECUR("23", "42");
		printf(BG_COLOR_WHITE COLOR_BLACK "      Play      \n" COLOR_RESET);
		MOVECUR("24", "42");
		printf(BG_COLOR_WHITE COLOR_BLACK "                \n" COLOR_RESET);
	} else {
		MOVECUR("22", "42");
		printf(BG_COLOR_BLACK COLOR_WHITE "                \n" COLOR_RESET);
		MOVECUR("23", "42");
		printf(BG_COLOR_BLACK COLOR_WHITE "      Play      \n" COLOR_RESET);
		MOVECUR("24", "42");
		printf(BG_COLOR_BLACK COLOR_WHITE "                \n" COLOR_RESET);
	}
}

void warningToNotResize() {
	printf("\n\n");
	char *shape[] = {
		"             AAA       AAA   AAAAAA   AAAAA   AAA    AA   AA   AAA    AA   AAAAAAA   AA         ",
		"             AAA       AAA  AAA  AAA  AA  AA  AAAA   AA   AA   AAAA   AA   AA        AA         ",
		"             AAAA AAA AAAA  AAAAAAAA  AAAAAA  AA AAA AA   AA   AA AAA AA   AAAAAAA   AA         ",
		"              AAAAAAAAAAA   AAA  AAA  AA  AA  AA   AAAA   AA   AA   AAAA   AA   AA              ",
		"                AAA AAA     AAA  AAA  AA  AA  AA    AAA   AA   AA    AAA   AAAAAAA   AA         ",
		"                                                                                                ",
		"    DDD     DDDD   DD  DD  DDDDD        DDDD  DDDD   DDD  D  DDDD  DDDD        DDDDD  D  D  DDDD",
		"    D  DD  DD  DD  DDD DD    D          DDD   DD    DDD   D    D   DD            D    DDDD  DD  ",
		"    DDD     DDDD   DD DDD    D          D  D  DDDD   DDD  D  DDDD  DDDD          D    D  D  DDDD",
		"                                                                                                ",
		"                        DD     DD  D  DD  DD  DDD     DDDD   DD     DD                          ",
		"                        DD DDD DD  D  DDD DD  D  DD  DD  DD  DD DDD DD                          ",
		"                         DDD DDD   D  DD DDD  DDD     DDDD    DDD DDD    DD                     "
	};
	printf("\n\n\n\n");
	printShape(shape, 15, 0);
	sleep(1);
}

void setupAnsi() {
	system("title Console Games >nul 2>&1");
	GOTOALT;
	SET_WINDOW_SIZE;
	NOT_SCROLLING;
	HIDECUR;
	NOT_LINEWRAPPING;
}

void restoreOldState() {
	EXITALT;
	USE_SCROLLING;
	SHOWCUR;
	USE_LINEWRAPPING;
}

void setupVariables() {
	char length = sizeof(straightLine) - 1;
	
	for (int i = 0; i < length; i++) {
		straightLine[i] = 196;
	}
	straightLine[length] = '\0';
}

void printGuesser() {
	CLEAR;
	printf("\n\n\n\n");
	loadGuessesKeyMenu();
}
void printTicTacToe() {
	CLEAR;
	printf("\n\n\n\n");
	loadTicTacToeKeyMenu();
}

void guesserGame() {
	char title[11] = "Difficulty";
	
	OptionMenu optionMenu;
	optionMenu.title = title;
	optionMenu.options = difficulties;
	optionMenu.optionsSize = sizeof(difficulties) / sizeof(difficulties[0]);
	optionMenu.defaultOption = 2;
	optionMenu.useLine = 1;
	
	printGuesser();
	
	OpenOptionMenu selected = singleOptionMenu(optionMenu, NULL);
	if (selected.exit != true) {
		guessesGame(selected.value);
	} else {
		gameMenu();
	}
}
void ticTacToe() {
	char title[22] = "Select your opponent";
	
	OptionMenu optionMenu;
	optionMenu.title = title;
	optionMenu.options = modes;
	optionMenu.optionsSize = sizeof(modes) / sizeof(modes[0]);
	optionMenu.defaultOption = 1;
	optionMenu.useLine = 1;
	
	printTicTacToe();
	
	OpenOptionMenu selected = singleOptionMenu(optionMenu, NULL);
	if (selected.exit != true) {
		if (selected.value != 1) {
			TICTACTOE_GAME settings;
			settings.mode = selected.value;
			start_tictactoe(settings);
		}
	} else {
		gameMenu();
	}
	
}

void printWithUserIn(char userInput) {
	switch(userInput) {
		case 'A':
			MOVECUR("7", "1"); makeEmptyLine(BG_COLOR_LIGHT_WHITE COLOR_LIGHT_BLACK);
			MOVECUR("7", "30"); printf(BG_COLOR_LIGHT_WHITE COLOR_LIGHT_BLACK "A) Guesser Game\n" COLOR_RESET);
			
			MOVECUR("8", "1"); makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
			MOVECUR("8", "30"); printf(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE "B) Tic Tac Toe\n" COLOR_RESET);
			break;
		case 'B':
			MOVECUR("7", "1"); makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
			MOVECUR("7", "30"); printf(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE "A) Guesser Game\n" COLOR_RESET);
			
			MOVECUR("8", "1"); makeEmptyLine(BG_COLOR_LIGHT_WHITE COLOR_LIGHT_BLACK);
			MOVECUR("8", "30"); printf(BG_COLOR_LIGHT_WHITE COLOR_LIGHT_BLACK "B) Tic Tac Toe\n" COLOR_RESET);
			break;
	}
}

void gameMenu() {
	CLEAR;
	MOVECUR("5", "1"); makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
	
	MOVECUR("6", "1"); makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
	MOVECUR("6", "30"); printf(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE "Choose a game you'd like to play:\n" COLOR_RESET);
	
	printWithUserIn('A');
	
	MOVECUR("9", "1"); makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
	MOVECUR("1", "1"); 
	loadKeyMenu();
	
	unsigned char userInput;
	unsigned char secondKeyType;
	char whileBreaker = 0;
	char selection = 'A';
	char scheduledQuit = 0;
	
	while (!whileBreaker) {
		userInput = toupper(getch());
		switch(userInput) {
			case 0:
			case 224:
				secondKeyType = getch();
				switch(secondKeyType) {
					case 77:
					case 80:
						selection++;
						if (selection > 'B') {
							selection = 'A';
						}
						printWithUserIn(selection);
						break;
					case 75:
					case 72:
						selection--;
						if (selection < 'A') {
							selection = 'B';
						}
						printWithUserIn(selection);
						break;
				}
				break;
			
			case 'A':
				selection = 'A';
				printWithUserIn(selection);
				break;
			case 'B':
				selection = 'B';
				printWithUserIn(selection);
				break;
			case 13:
				whileBreaker++;
				break;
			case 'Q':
				whileBreaker++;
				scheduledQuit++;
				break;
		}
	}
	
	if (scheduledQuit) {
		return;
	}
	
	switch(selection) {
		case 'A':
			guesserGame();
			break;
		case 'B':
			ticTacToe();
			break;
	}
}



