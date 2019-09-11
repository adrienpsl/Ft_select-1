/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:19:21 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 13:38:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libtc.h"

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
