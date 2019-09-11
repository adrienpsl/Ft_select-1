/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:55:12 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 18:44:30 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <sys/ioctl.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

void	get_window_info(struct s_display *display)
{
	struct winsize	win;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &win);
	display->wcol = win.ws_col;
	display->wrow = win.ws_row;
}

void	get_list_info(struct s_display *display, struct s_select *list, int nb)
{
	display->colsize = 0;
	while (nb)
	{
		--nb;
		if (list[nb].len > display->colsize)
			display->colsize = list[nb].len;
	}
}

_Bool	it_doesnt_fit(struct s_display *display, int nb)
{
	if ((nb - 1) / display->wrow <= display->wcol / display->colsize)
		return (0);
	else
		return (1);
}

void	checkfits(struct s_display *display, int argc)
{
	if (it_doesnt_fit(display, argc - 1))
	{
		ft_dprintf(STDERR_FILENO, "Cannot display list, screen too small\n");
		tc_cursor(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
		exit(1);
	}
}
