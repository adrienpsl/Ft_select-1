
#include <unistd.h>
#include <termcap.h>

#include "libft.h"
#include "libtcap.h"

void	get_window_info(void)
{
	int	column_count;
	int	line_count;

	column_count = tgetnum("co");
	line_count = tgetnum("li");
	ft_printf("co:%d\nli:%d\n", column_count, line_count);
	
	char *cl_cap = tgetstr("cl", NULL);
	tputs(cl_cap, 1, ft_tcoutput);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (ft_tcinit())
		return (1);
	else if (argc < 2)
		return (1);
	else
	{
		get_window_info();
		ft_print_tables(&argv[1]);
	}
	return (0);
}
