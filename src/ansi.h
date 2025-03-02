#ifndef ANSI_H
#define ANSI_H

#define CLEAR                  printf("\033[H\033[J")
#define ERASELN                printf("\r\033[2K")
#define ERASEAF                printf("\033[0K")

#define MOVEUP                 printf("\033[1A")
#define MOVEDOWN               printf("\033[1B")
#define MOVERIGHT              printf("\033[1C")
#define MOVELEFT               printf("\033[1D")

#define SAVECUR                printf("\033[s");
#define LOADCUR                printf("\033[u");

#define HIDECUR                printf("\033[?12l\033[?25l")
#define SHOWCUR                printf("\033[?12h\033[?25h")

#define HOMEPOS                printf("\033[H")

#define NOT_LINEWRAPPING       printf("\033[?7l\033[=7l")
#define USE_LINEWRAPPING       printf("\033[?7h\033[=7h")

#define NOT_SCROLLING          printf("\033[?3h")
#define USE_SCROLLING          printf("\033[?3l")

#define SET_WINDOW_SIZE        system("mode con: cols=105 lines=30 > nul 2>&1"); printf("\033[8;30;105t")

#define MOVECUR(row, col)      printf("\033[%s;%sf", row, col)
#define SETCOL(col)            printf("\033[%sG", col)

#define GOTOALT                printf("\033[?1049h")
#define EXITALT                printf("\033[?1049l")

#define COLOR_RESET            "\033[0m"
#define COLOR_BOLD             "\033[1m"
#define COLOR_UNDERLINE        "\033[4m"
#define COLOR_STRIKETHROUGH    "\033[9m"

#define COLOR_BLACK            "\033[30m"
#define COLOR_RED              "\033[31m"
#define COLOR_GREEN            "\033[32m"
#define COLOR_YELLOW           "\033[33m"
#define COLOR_BLUE             "\033[34m"
#define COLOR_PURPLE           "\033[35m"
#define COLOR_CYAN             "\033[36m"
#define COLOR_WHITE            "\033[37m"

#define COLOR_LIGHT_BLACK      "\033[90m"
#define COLOR_LIGHT_RED        "\033[91m"
#define COLOR_LIGHT_GREEN      "\033[92m"
#define COLOR_LIGHT_YELLOW     "\033[93m"
#define COLOR_LIGHT_BLUE       "\033[94m"
#define COLOR_LIGHT_PURPLE     "\033[95m"
#define COLOR_LIGHT_CYAN       "\033[96m"
#define COLOR_LIGHT_WHITE      "\033[97m"

#define BG_COLOR_BLACK         "\033[40m"
#define BG_COLOR_RED           "\033[41m"
#define BG_COLOR_GREEN         "\033[42m"
#define BG_COLOR_YELLOW        "\033[43m"
#define BG_COLOR_BLUE          "\033[44m"
#define BG_COLOR_PURPLE        "\033[45m"
#define BG_COLOR_CYAN          "\033[46m"
#define BG_COLOR_WHITE         "\033[47m"

#define BG_COLOR_LIGHT_BLACK   "\033[100m"
#define BG_COLOR_LIGHT_RED     "\033[101m"
#define BG_COLOR_LIGHT_GREEN   "\033[102m"
#define BG_COLOR_LIGHT_YELLOW  "\033[103m"
#define BG_COLOR_LIGHT_BLUE    "\033[104m"
#define BG_COLOR_LIGHT_PURPLE  "\033[105m"
#define BG_COLOR_LIGHT_CYAN    "\033[106m"
#define BG_COLOR_LIGHT_WHITE   "\033[107m"

#define CLEAR_ATTR             LOADCUR; HOMEPOS; printf(COLOR_RESET);

#endif
