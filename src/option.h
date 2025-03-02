#ifndef OPTION_H
#define OPTION_H

typedef struct {
	char *title;
	char **options;
	int optionsSize;
	int defaultOption;
	char useLine;
} OptionMenu;

typedef struct {
	OptionMenu menu;
	unsigned int value;
	bool exit;
} OpenOptionMenu;

OpenOptionMenu singleOptionMenu(OptionMenu, void (*)(void));
OpenOptionMenu singleHorizontalOptionMenu(OptionMenu, void (*)(void));

#endif
