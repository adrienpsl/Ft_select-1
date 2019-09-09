#include <unistd.h>

#include "libtc.h"

int	tc_placendisplay(unsigned short col, unsigned short row, int size, void *content)
{
	if (tc_move(col, row))
		return (1);
	else if (size != write(STDOUT_FILENO, content, size))
		return (1);
	else
		return (0);
}
