#include <conio.h>
#include "util.h"

char flushGetch() {
    if (_kbhit()) {
    	return _getch();
    } else {
    	return 0;
	}
}