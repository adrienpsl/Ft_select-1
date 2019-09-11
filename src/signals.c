/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:16:37 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 18:40:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>

#include "ft_select.h"
#include "libtc.h"

#include "libft.h"

void	change_winsize(int sig)
{
	static int i;

	++i;
	(void)sig;
	tc_clear();
	get_window_info(g_display);
	g_display->colsize = g_display->wrow;
	checkfits(g_display, g_display->nb_element);
	display_list(g_list, g_display);
}

void	foreground(int sig)
{
	(void)sig;
	init_term(1);
	tc_clear();
	if (signal(SIGCONT, SIG_DFL) == SIG_ERR)
		exit(2);
	if (signal(SIGTSTP, background) == SIG_ERR)
		exit(2);
	display_list(g_list, g_display);
}

void	background(int sig)
{
	(void)sig;
	tc_clear();
	init_term(0);
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		exit(2);
	ioctl(0, TIOCSTI, "\032");
	if (signal(SIGCONT, foreground) == SIG_ERR)
		exit(2);
}

int		set_signals(void)
{
	if ((signal(SIGINT, SIG_IGN) == SIG_ERR)
			|| (signal(SIGTSTP, background) == SIG_ERR)
			|| (signal(SIGWINCH, change_winsize) == SIG_ERR))
		exit(2);
	return (0);
}
