#ifndef MAIN_H
#define MAIN_H

#include "util.h"

extern char straightLine[42];
extern char *difficulties[4];
extern char *difficultiesWRandom[5];
extern char *modes[1];
extern char **difficultiesPtr;
extern char *playModes[3];

int main(int, char*[]);
void goodbyeText();
bool waitForGetch(int, int);
void mainMenu();
void setPlayButton(bool);
void warningToNotResize();
void setupAnsi();
void restoreOldState();
void setupVariables();
void printTicTacToe();
void printGuesser();
void guesserGame();
void ticTacToe();
void printWithUserIn(char);
void gameMenu();

#endif
