/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_underline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:29 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:44:30 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>

#include "libtc.h"

int	tc_underline(void)
{
	char *us_cap;
       
	if (!(us_cap = tgetstr("us", NULL)))
		return (1);
	else if (tputs(us_cap, 1, tc_output))
		return (1);
	else
		return (0);
}
