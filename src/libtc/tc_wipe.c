/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_wipe.c                                          :+:      :+:    :+:   */
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

int	tc_wipe(void)
{
	char *cl_cap;
	
	if (tc_move(0, 0))
		return (1);
	if (!(cl_cap = tgetstr("cd", NULL)))
		return (1);
	else if (tputs(cl_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
