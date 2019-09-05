
#include <curses.h>
#include <unistd.h>
#include <termcap.h>

#include "libft.h"
#include "libtc.h"

void	get_window_info(void)
{
	int	column_count;
	int	line_count;

	column_count = tgetnum("co");
	line_count = tgetnum("li");
	ft_printf("co:%d\nli:%d\n", column_count, line_count);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (tc_init())
		return (1);
	else if (argc < 2)
	{
		ft_dprintf(STDERR_FILENO,
		"%s requires at least one argument.\n\nUsage:\t%s FILE|DIRECTORY...\n",
			&argv[0][2], argv[0]);
		return (1);
	}
	else
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_clear();
		get_window_info();
		if (tc_bgcolor(COLOR_GREEN))
			return (1);
		tc_move(1,1);
		tc_reset();
/*		ft_print_tables(&argv[1]);
		tc_underline();
		ft_print_tables(&argv[1]);
		tc_reset();
		ft_print_tables(&argv[1]);
		tc_clear();
		ft_printf("output result here\n");
*/		tc_setnoncanonical(STDIN_FILENO, 1);
	}
	return (0);
}
