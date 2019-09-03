#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_reset(void)
{
	char *me_cap;
       
	if (!(me_cap = tgetstr("me", NULL)))
		return (1);
	else if (tputs(me_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
