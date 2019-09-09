#include "libtc.h"

int	display_list(char **argv, struct s_select *list, int nb)
{
	while (nb)
	{
		--nb;
		if (*argv)
			tc_placendisplay(list[nb].col,...)
	}
	return (1);
}
