/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_ftcolor_stderr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:43:54 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:43:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

/*
** curses_color is a color defined via macros in curses.h, e.g. COLOR_GREEN
*/

int	tc_ftcolor_stderr(int curses_color)
{
	char *af_cap;

	if (!(af_cap = tgetstr("AF", NULL)))
		return (1);
	else if (tputs(tparm(af_cap, curses_color), 1, tc_output_stderr))
		return (1);
	else
		return (0);
}
