#include "ft_select.h"
#include "libtc.h"

int	display_list(char **argv, struct s_select *list, int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		--nb;
		if (*argv)
			tc_placendisplay(list[nb].col, list[nb].row + i, list[nb].len, argv[nb + 1]);
		++i;
	}
	return (1);
}
