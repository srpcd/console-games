
CC       = gcc.exe
SRC      = src
OUT      = out
OBJ      = $(OUT)/main.o $(OUT)/option.o $(OUT)/guess.o $(OUT)/menu.o $(OUT)/shape.o $(OUT)/tictactoe.o $(OUT)/util.o
BINFLAGS = 
BIN      = ConsoleGames.exe

.PHONY: clean all

clean:
	if exist out rmdir /Q /S $(OUT)
	
all:
	mkdir $(OUT)
	$(CC) -c $(SRC)/main.c -o $(OUT)/main.o
	$(CC) -c $(SRC)/option.c -o $(OUT)/option.o
	$(CC) -c $(SRC)/guess.c -o $(OUT)/guess.o
	$(CC) -c $(SRC)/menu.c -o $(OUT)/menu.o
	$(CC) -c $(SRC)/shape.c -o $(OUT)/shape.o
	$(CC) -c $(SRC)/tictactoe.c -o $(OUT)/tictactoe.o
	$(CC) -c $(SRC)/util.c -o $(OUT)/util.o
	$(CC) -O3 $(OBJ) -o $(BIN) -static-libgcc

