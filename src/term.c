#include <unistd.h>

#include "libtc.h"

void	init_term(_Bool start)
{
	if (start)
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_cursor(0);
		tc_clear();
	}
	else
	{
		tc_wipe();
		tc_cursor(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
	}
}

