/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:14:11 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 17:56:54 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

static void	define_location(struct s_select *list, struct s_display *display)
{
	int				i;
	unsigned short	x;
	unsigned short	y;

	i = 0;
	x = 0;
	y = 0;
	while (list && i < display->nb_element)
	{
		y = y % display->wrow + 1;
		list[i].col = x * (display->colsize + 1);
		list[i].row = y - 1;
		++i;
		if (y + 1 > display->wrow)
			++x;
	}
}

void		display_list(struct s_select *list, struct s_display *display)
{
	int nb;

	nb = display->nb_element;
	define_location(list, display);
	while (nb)
	{
		--nb;
		if (list[nb].isselected)
		{
			tc_bgcolor(COLOR_WHITE);
			tc_ftcolor(COLOR_BLACK);
		}
		if (list[nb].isunderline)
			tc_underline();
		if (list[nb].arg)
			tc_placendisplay(list[nb].col, list[nb].row, list[nb].len,
					list[nb].arg);
		if (list[nb].isunderline || list[nb].isselected)
			tc_reset();
	}
	g_list = list;
	g_display = display;
}

void		display_selection(struct s_select *list, struct s_display *display)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < display->nb_element)
	{
		if (list[i].isselected)
			++nb;
		++i;
	}
	i = 0;
	while (i < display->nb_element)
	{
		if (list[i].isselected)
		{
			if (nb != 1)
				ft_printf("%s ", list[i].arg);
			else
				ft_printf("%s", list[i].arg);
			--nb;
		}
		++i;
	}
}
