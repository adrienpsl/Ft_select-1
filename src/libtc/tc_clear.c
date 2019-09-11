/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:43:47 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 13:54:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_clear(void)
{
	char	*cl_cap;

	if (!(cl_cap = tgetstr("cl", NULL)))
		return (1);
	else if (tputs(cl_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
