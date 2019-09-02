
#include <unistd.h>

#include "libft.h"
#include "init_term.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (init_term())
		return (1);
	else if (argc < 2)
		return (1);
	else
		ft_print_tables(argv);
	return (0);
}
