#include <unistd.h>

#include "libtc.h"

void	init_term(_Bool start)
{
	if (start)
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_cursor_stderr(0);
		tc_clear_stderr();
	}
	else
	{
		tc_wipe_stderr();
		tc_cursor_stderr(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
	}
}

