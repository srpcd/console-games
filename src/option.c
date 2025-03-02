#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "util.h"
#include "option.h"
#include "menu.h"
#include "ansi.h"

OpenOptionMenu singleOptionMenu(OptionMenu settings, void (*before)(void)) {
	OpenOptionMenu optionMenu;
	optionMenu.menu = settings;
	optionMenu.value = settings.defaultOption;
	optionMenu.exit = false;

	for (int i = 0; i <= settings.optionsSize + settings.useLine; i++) {
		MOVEDOWN;
	}

	while(1) {
		if (before != NULL) {
			before();
		} else {
			for (int i = 0; i <= settings.optionsSize + settings.useLine; i++) MOVEUP;
		}
		
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
		printf("\r\n");
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
		SETCOL("40");
		printf(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE "%s%s\n" COLOR_RESET, COLOR_UNDERLINE, settings.title);
		for (int i = 0; i <= settings.optionsSize-1; i++) {
			if (optionMenu.value - 1 == i) {
				makeEmptyLine(BG_COLOR_WHITE COLOR_LIGHT_BLACK);
				SETCOL("28");
				printf(BG_COLOR_WHITE COLOR_LIGHT_BLACK "%24s%-6s\n" COLOR_RESET, BG_COLOR_WHITE COLOR_BLACK, settings.options[i]);
				continue;
			}
			makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_WHITE);
			SETCOL("28");
			printf(BG_COLOR_LIGHT_BLACK COLOR_WHITE "%19s%-6s\n" COLOR_RESET, COLOR_WHITE, settings.options[i]);
		}
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_LIGHT_WHITE);
		
		unsigned char code = getch();
		
		if (code == 224) {
			code = getch();
			if (code == 80 || code == 77) {
				optionMenu.value++;
				if (optionMenu.value > settings.optionsSize) {
					optionMenu.value = 1;
				}
			} else if (code == 72 || code == 75) {
				optionMenu.value--;
				if (optionMenu.value < 1) {
					optionMenu.value = settings.optionsSize;
				}
			}
		} else if (code == 13) {
			break;
		} else if (toupper(code) == 'Q') {
			optionMenu.exit = true;
			break;
		}
	}
	optionMenu.value--;
	return optionMenu;
}

OpenOptionMenu singleHorizontalOptionMenu(OptionMenu settings, void (*before)(void)) {
	OpenOptionMenu optionMenu;
	optionMenu.menu = settings;
	optionMenu.value = settings.defaultOption;
	optionMenu.exit = false;
	while(1) {
		if (before != NULL) {
			before();
		} else {
			MOVEUP;
			SETCOL("20");
		}
		
		SETCOL("20");
		printf(COLOR_LIGHT_BLACK "%s:%-6s" COLOR_RESET, settings.title, COLOR_RESET);
		for (int i = 0; i <= settings.optionsSize-1; i++) {
			if (optionMenu.value - 1 == i) {
				printf("%9s%s%-6s" COLOR_RESET, BG_COLOR_WHITE COLOR_BLACK, settings.options[i], COLOR_RESET);
				continue;
			}
			printf("%4s%s%-6s" COLOR_RESET, COLOR_WHITE, settings.options[i], COLOR_RESET);
		}
		SETCOL("60");
		makeEmptyLine(BG_COLOR_LIGHT_BLACK COLOR_WHITE);
		printf("\n");
		
		unsigned char code = getch();
		
		if (code == 224) {
			code = getch();
			if (code == 80 || code == 77) {
				optionMenu.value++;
				if (optionMenu.value > settings.optionsSize) {
					optionMenu.value = 1;
				}
			} else if (code == 72 || code == 75) {
				optionMenu.value--;
				if (optionMenu.value < 1) {
					optionMenu.value = settings.optionsSize;
				}
			}
		} else if (code == 13) {
			break;
		} else if (toupper(code) == 'Q') {
			optionMenu.exit = true;
			break;
		}
	}
	optionMenu.value--;
	return optionMenu;
}
