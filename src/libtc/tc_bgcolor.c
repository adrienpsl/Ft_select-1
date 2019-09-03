#include <curses.h>
#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

/*
** curses_color is a color defined via macros in curses.h, e.g. COLOR_GREEN
*/

int	tc_bgcolor(int curses_color)
{
	char *af_cap;

	if (!(af_cap = tgetstr("AF", NULL)))
		return (1);
	else if (tputs(tparm(af_cap, curses_color), 1, tc_output))
		return (1);
	else
		return (0);
}
