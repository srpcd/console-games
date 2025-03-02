#ifndef UTIL_H
#define UTIL_H
#undef DEBUG

char flushGetch();

typedef enum {
	EASY = 0,
	NORMAL = 1,
	HARD = 2,
	INSANE = 3,
	RANDOMLY = 4
} Difficulty;

typedef enum {
	PLAYER_PLAYER = 0
} PlayerMode;

typedef enum {
	true = 1,
	false = 0
} bool;

#endif
