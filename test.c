#include <ncurses.h>
#include "nc.h"

int main() {
	WINDOW* stdscr = initscr();
	curs_set(0); keypad(stdscr, 1);
	start_color(); use_default_colors();
	cbreak();
	init_pair(1, 20, 15);
	int y, x; getmaxyx(stdscr, y, x);
	WINDOW* win = newwin(3, 50, y/2-1, x/2-25);
	wbkgd(win, COLOR_PAIR(1));
	wrefresh(stdscr); wrefresh(win);
	char* buff;
	int err = Sread(win, 1, 2, 20, 20, &buff); 
	endwin();
	puts(buff);
}
