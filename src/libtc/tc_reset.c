/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:16 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:44:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_reset(void)
{
	char *me_cap;
       
	if (!(me_cap = tgetstr("me", NULL)))
		return (1);
	else if (tputs(me_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
