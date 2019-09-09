#include "ft_select.h"
#include "libtc.h"

static void	define_location(struct s_select *list, struct s_display *display, int nb)
{
	int		i;
	unsigned short	x;
	unsigned short	y;

	i = 0;
	x = 0;
	y = 0;
	while (list && i < nb)
	{
		y = y % display->wrow + 1;
		list[i].col = x * (display->colsize + 1);
		list[i].row = y - 1;
		++i;
		if (y + 1 > display->wrow)
			++x;
	}
}

void	display_list(char **argv, struct s_select *list, struct s_display *display, int nb)
{
	tc_clear();
	define_location(list, display, nb);
	while (nb)
	{
		--nb;
		if (*argv)
			tc_placendisplay(list[nb].col, list[nb].row, list[nb].len, argv[nb + 1]);
	}
}
