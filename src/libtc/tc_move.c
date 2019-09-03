#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_move(int col, int row)
{
	char *cm_cap;
	
	if (!(cm_cap = tgetstr("cm", NULL)))
		return (1);
	else if (tputs(tgoto(cm_cap, col, row), 1, tc_output))
		return (1);
	else
		return (0);
}
