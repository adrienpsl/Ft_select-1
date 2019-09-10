#include <unistd.h>

#include "libtc.h"

int	tc_placendisplay_stderr(unsigned short col, unsigned short row, int size, void *content)
{
	if (tc_move_stderr(col, row))
		return (1);
	else if (size != write(STDERR_FILENO, content, size))
		return (1);
	else
		return (0);
}
