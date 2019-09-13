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

_Bool	it_fits(struct s_display *display)
{
	if (display->nb_element <= (display->wcol / (display->colsize + 1)) * display->wrow)
		return (1);
	else
		return (0);
}
