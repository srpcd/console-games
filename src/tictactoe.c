#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "tictactoe.h"
#include "menu.h"
#include "main.h"
#include "util.h"
#include "ansi.h"

char board[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

CELL get_selection(const int selection) {
	CELL cell;
	cell.column = selection % 3;
	cell.row = (selection-cell.column) / 3 + 1;
	cell.column++;
	
	#ifdef DEBUG
		printf("\033[s");
		MOVECUR("2", "2");
		printf("sel=%d [row=%d, col=%d]", selection, cell.row, cell.column);
		printf("\033[u");
	#endif
	return cell;
}

void cannot_put_here() {
	printf("\033[s");
	MOVECUR("1", "30");
	printf("%11sYou can't put here!%-11s\n", COLOR_RED, COLOR_RESET);
	printf("\033[u");
}

TICTACTOE_DIRECTION getWinningDirection(char turn) {
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return DIAGONAL_FORWARDS;
	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) return DIAGONAL_BACKWARDS;
	
	if (board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) return HORIZONTAL_1;
	if (board[1][0] == turn && board[1][1] == turn && board[1][2] == turn) return HORIZONTAL_2; 
	if (board[2][0] == turn && board[2][1] == turn && board[2][2] == turn) return HORIZONTAL_3;
	
	if (board[0][0] == turn && board[1][0] == turn && board[2][0] == turn) return VERTICAL_1; 
	if (board[0][1] == turn && board[1][1] == turn && board[2][1] == turn) return VERTICAL_2; 
	if (board[0][2] == turn && board[1][2] == turn && board[2][2] == turn) return VERTICAL_3;
	
	return NO_WIN;
}

void winCrossing(char winner, TICTACTOE_DIRECTION direction) {
	switch(direction) {
		case DIAGONAL_FORWARDS:
			MOVECUR("9", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "41"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case DIAGONAL_BACKWARDS:
			MOVECUR("9", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "41");
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case HORIZONTAL_1:
			MOVECUR("9", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("9", "41");
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("9", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case HORIZONTAL_2:
			MOVECUR("13", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "41");
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case HORIZONTAL_3:
			MOVECUR("17", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "41");
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case VERTICAL_1:
			MOVECUR("9", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "30"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case VERTICAL_2:
			MOVECUR("9", "41"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "41"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "41"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
		case VERTICAL_3:
			MOVECUR("9", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("13", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			MOVECUR("17", "52"); 
			printf(COLOR_RESET COLOR_BLACK BG_COLOR_LIGHT_WHITE COLOR_STRIKETHROUGH "----%c----", winner);
			break;
	}
}

bool isWinner(char turn) {
	if ((board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) ||
		(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) ||
		(board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) ||
		(board[1][0] == turn && board[1][1] == turn && board[1][2] == turn) ||
		(board[2][0] == turn && board[2][1] == turn && board[2][2] == turn) ||
		(board[0][0] == turn && board[1][0] == turn && board[2][0] == turn) ||
		(board[0][1] == turn && board[1][1] == turn && board[2][1] == turn) ||
		(board[0][2] == turn && board[1][2] == turn && board[2][2] == turn)) {
		
		return true;
	}
	return false;
}

char getWinner() {
	return isWinner('X') ? 'X' : (isWinner('O') ? 'O' : ' ');
}

void clear_cannot_put_here() {
	SAVECUR;
	MOVECUR("1", "30");
	printf("%11s%-49s\n", BG_COLOR_LIGHT_BLACK COLOR_BLACK, BG_COLOR_LIGHT_BLACK COLOR_BLACK);
	LOADCUR;
}

void show_board(const int offset, const int selection) {
	MOVECUR("8", "12");
	
	const CELL cell = get_selection(selection);
	const int col = cell.column;
	const int row = cell.row;
	
	for(int i = 0; i < sizeof(board) / sizeof(board)[0]; i++) {
		for(int j = 0; j < sizeof(board)[0] / sizeof(board)[0][0]; j++) {
			char* boardnum = malloc(3);
			if (board[i][j] == 'X') {
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s    X    " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK));
			} else if (board[i][j] == 'O') {
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s    O    " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK));
			} else {
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK)); 
				SETCOL(itoa(offset+j*11, boardnum, 10));
				printf("%s         " COLOR_RESET BG_COLOR_BLACK "  \n" COLOR_RESET, ((row == i+1 && col == j+1) ? BG_COLOR_YELLOW COLOR_BLACK : BG_COLOR_LIGHT_WHITE COLOR_BLACK));
			}
			SETCOL(itoa(offset+j*11, boardnum, 10));
			printf(BG_COLOR_BLACK COLOR_BLACK "           "  COLOR_RESET);
			free(boardnum);
			MOVEUP; MOVEUP; MOVEUP;
		}
		printf("\n\n\n\n");
		SETCOL("12");
	}
}

void displayWinner(char winner) {
	SAVECUR;
	MOVECUR("6", "30");
	printf("%16s%c wins!%-17s", COLOR_RESET, winner, COLOR_RESET);
	LOADCUR;
}

bool isFull() {
	for(int i = 0; i < sizeof(board)/sizeof(board[0]); i++) {
		for(int j = 0; j < sizeof(board[0])/sizeof(board[0][0]); j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void start_tictactoe(TICTACTOE_GAME settings) {
	CLEAR;
	
	const char offset = 30;
	
	for (int i = 1; i <= 36; i++) {
		char* character = malloc(3);
		MOVECUR(itoa(i, character, 10), "1");
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_WHITE); printf("\n");
		free(character);
	}
	if (settings.mode == PLAYER_PLAYER) {
		MOVECUR("12", "12");
		
		char winner, currentTurn, scanCode;
		unsigned char arrow;
		bool exitGetch;
		bool anyWin = false;
		char currentSelection = 0;
		loadOnTicTacToeKeyMenu();
		show_board(offset, currentSelection);
		
		for (int turn = 0; !anyWin; turn++) {
			exitGetch = false;
			currentTurn = turn % 2 ? 'X' : 'O';
			
			SAVECUR;
			MOVECUR("6", "30");
			printf("%11sPlayer %d's turn (%c)%-11s\n", COLOR_RESET, (turn % 2) + 1, currentTurn, COLOR_RESET);
			LOADCUR;
			
			while(true) {
				winner = getWinner();
				
				if (winner == 'X' || winner == 'O') {
					show_board(offset, 9);
					displayWinner(winner);
					winCrossing(winner, getWinningDirection(winner));
					exitGetch = true;
					break;
				} else if (isFull()) {
					SAVECUR;
					MOVECUR("6", "30");
					printf("%14sIt's a tie!%-16s\n", COLOR_RESET, COLOR_RESET);
					LOADCUR;
					exitGetch = true;
					break;
				}
				
				arrow = getch();
				if (arrow == 13) {
					//check_empty_boxes(&currentSelection, currentTurn, true, 0);
					CELL cell = get_selection(currentSelection);
					if (board[cell.row-1][cell.column-1] != ' ') {
						cannot_put_here();
						show_board(offset, currentSelection);
					} else {
						board[cell.row-1][cell.column-1] = currentTurn;
						show_board(offset, currentSelection);
						break;
					}
				} else if (toupper(arrow) == 'Q') {
					//ticTacToe();
					SAVECUR;
					MOVECUR("6", "30");
					printf("%15sGame Over%-17s\n", COLOR_RESET, COLOR_RESET);
					LOADCUR;
					exitGetch = true;
					break;
				} else if (arrow == 224) {
					clear_cannot_put_here();
					scanCode = getch();
					if (scanCode == 75) {
						currentSelection--;
						if (currentSelection < 0) {
							currentSelection = 0;
						}
					} else if (scanCode == 77) {
						currentSelection++;
						if (currentSelection > 8) {
							currentSelection = 8;
						}
					} else if (scanCode == 72) {
						currentSelection -= 3;
						if (currentSelection < 0) {
							currentSelection += 3;
						}
					} else if (scanCode == 80) {
						currentSelection += 3;
						if (currentSelection > 8) {
							currentSelection -= 3;
						}
					}
				}
				//check_empty_boxes(&currentSelection, currentTurn, false, scanCode);
				show_board(offset, currentSelection);
			}
			if (exitGetch) break;
		}
		CLEAR_ATTR; 
		
		show_board(offset, 9);
		if (winner == 'X' || winner == 'O') winCrossing(winner, getWinningDirection(winner));
		CLEAR_ATTR; 
		loadAfterTicTacToeKeyMenu();
		
		for (int i = 0; i < sizeof(board)/sizeof(board[0]); i++){
			for (int j = 0; j < sizeof(board[0])/sizeof(board[0][0]); j++) {
				board[i][j] = ' ';
			}
		}
		
		while(true){
			bool whileBreaker = false;
			char finalAction = getch();
			
			switch(toupper(finalAction)) {
				case 'Q':
					CLEAR;
					gameMenu();
					whileBreaker = true;
					break;
				case 'R':
					start_tictactoe(settings);
					whileBreaker = true;
					break;
				case 'T':
					ticTacToe();
					whileBreaker = true;
					break;
			}
			
			if (whileBreaker) break;
		}
		
		//printf(BG_COLOR_LIGHT_BLACK COLOR_WHITE "Game started: Player vs Player");
	}
}

