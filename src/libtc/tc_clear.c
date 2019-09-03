#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_clear(void)
{
	char *cl_cap;
	
	if (!(cl_cap = tgetstr("cl", NULL)))
		return (1);
	else if (tputs(cl_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
