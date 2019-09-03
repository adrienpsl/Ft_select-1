#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_underline(void)
{
	char *us_cap;
       
	if (!(us_cap = tgetstr("us", NULL)))
		return (1);
	else if (tputs(us_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
