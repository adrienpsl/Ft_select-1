
#include <curses.h>
#include <unistd.h>
#include <termcap.h>

#include "ft_select.h"
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

static void	fill_select_struct(struct s_select *list, char **argv, int nb)
{
	while (nb > 0)
	{
		ft_putendl(argv[nb]);
		ft_bzero(list, sizeof(struct s_select));
		--nb;
	}
}

int		main(int argc, char **argv)
{
	struct s_select	list[argc - 1];

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
		fill_select_struct(list, argv, argc - 1);
/*		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_clear();
		get_window_info();
		if (tc_bgcolor(COLOR_GREEN))
			return (1);
		tc_move(2, 1);
		write(1, "OK", 3);
		tc_move(3,3);
		write(1, "OK", 3);
		write(1, "OK", 3);
*/	/*	ft_print_tables(argv);
	tc_reset();
		tc_move(10,10);
		ft_print_tables(&argv[1]);
		tc_underline();
		ft_print_tables(&argv[1]);
		tc_reset();
		ft_print_tables(&argv[1]);
		tc_clear();
		ft_printf("output result here\n");
		tc_setnoncanonical(STDIN_FILENO, 1);
		tc_move(10,10);
*/	}
	return (0);
}
