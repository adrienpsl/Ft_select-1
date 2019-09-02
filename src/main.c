
#include <unistd.h>

#include "libft.h"
#include "init_term.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (init_term())
		return (1);
	return (0);
}
