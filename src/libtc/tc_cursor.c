/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:43:47 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:43:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_cursor(_Bool visible)
{
	char *vi_cap;
	
	if (visible)
	{
		if (!(vi_cap = tgetstr("vs", NULL)))
			return (1);
	}
	else
	{
		if (!(vi_cap = tgetstr("vi", NULL)))
			return (1);
	}
	if (tputs(vi_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
