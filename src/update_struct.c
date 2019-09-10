#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

void	update_select_struct(struct s_select *list, struct s_display *display, int position)
{
	if (position + 1 < display->nb_element)
	{
		ft_memmove(&(list[position]), &(list[position + 1]), (display->nb_element - position + 1) * sizeof(struct s_select));
		--display->nb_element;
		ft_bzero(&(list[display->nb_element]), sizeof(struct s_select));
	}
}
