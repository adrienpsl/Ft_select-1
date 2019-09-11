/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:19:21 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 14:51:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libtc.h"

#ifdef __unix__

void	init_term(_Bool start)
{
	if (start)
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_cursor(0);
		tc_clear();
	}
	else
	{
		tc_wipe();
		tc_cursor(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
	}
}

#else

void	init_term(_Bool start)
{
	if (start)
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_cursor(0);
		tc_clear();
	}
	else
	{
		tc_move(0, 0);
		tc_cursor(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
	}
}

#endif
