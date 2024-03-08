#include <ncurses.h>
#include "nc.h"
#include "../libvector/vector.h"

int Sread(WINDOW* win, int y, int x, int visual_limit, int char_limit, char** buff) {
	string S = string_init(*buff);
	curs_set(1);
	int p[2]={0};
	for (;;) {
		int ch = mvwgetch(win, y, x+p[0]);
		switch (ch) {
			case 27:
				curs_set(0);
				return 0;
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			case KEY_BACKSPACE:
				break;
			case 4:
			case 10:
				curs_set(0);
				*buff = string_get_c_str(&S);
				return 1;
			default:
				if (p[1] == char_limit) continue; // IF p[0] IS VISUAL_LIMIT SCROLL HORIZONTALLY
				if (!((ch >= ' ' && ch <= '~') || (ch >= 225 && ch <= 250))) continue;
				string_append_char(&S, ch);
				mvwaddch(win, y, x+p[0], ch);
				p[0]++; p[1]++;
				break;
		}
	}
	return 1;
}
