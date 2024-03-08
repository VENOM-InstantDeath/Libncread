#ifndef NCREAD_H
#define NCREAD_H
#include <ncurses.h>
int Sread(WINDOW* win, int y, int x, int visual_limit, int char_limit, char** buff);
#endif
