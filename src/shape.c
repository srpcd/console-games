#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ansi.h"
#include "shape.h"

void printShape(char* shape[], int lines, int sleep_per_cell) {   // the shape needs all strings to be of the same size
	srand(time(NULL));
	int random = (rand() % 7) + 1;
	for (int i = 0; i < lines; i++) {
		ERASELN;
		for (int j = 0; shape[i][j] != '\0'; j++) {
			switch(shape[i][j]) {
				case 'A':
					printf(BG_COLOR_YELLOW " " COLOR_RESET);
					break;
				case 'B':
					printf(BG_COLOR_BLUE " " COLOR_RESET);
					break;
				case 'C':
					printf(BG_COLOR_RED " " COLOR_RESET);
					break;
				case 'D':
					printf(BG_COLOR_WHITE " " COLOR_RESET);
					break;
				case 'E':
					printf(BG_COLOR_PURPLE " " COLOR_RESET);
					break;
				case 'F':
					printf(BG_COLOR_CYAN " " COLOR_RESET);
					break;
				case 'X':
					printf(BG_COLOR_GREEN " " COLOR_RESET);
					break;
				case 'R':
					switch(random) {
						case 1: 
							printf(BG_COLOR_YELLOW " " COLOR_RESET);
							break;
						case 2: 
							printf(BG_COLOR_BLUE " " COLOR_RESET);
							break;
						case 3: 
							printf(BG_COLOR_RED " " COLOR_RESET);
							break;
						case 4: 
							printf(BG_COLOR_WHITE " " COLOR_RESET);
							break;
						case 5: 
							printf(BG_COLOR_PURPLE " " COLOR_RESET);
							break;
						case 6: 
							printf(BG_COLOR_CYAN " " COLOR_RESET);
							break;
						case 7: 
							printf(BG_COLOR_GREEN " " COLOR_RESET);
							break;
					}
					break;
				default:
					printf(" ");
				if (j % 10 == 4 && sleep_per_cell) usleep(sleep_per_cell);
			}
		}
		MOVEDOWN;
		printf("\r");
	}
}


