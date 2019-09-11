/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_placendisplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:54:34 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 13:54:37 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libtc.h"

int	tc_placendisplay(unsigned short col, unsigned short row, int size,
						void *content)
{
	extern int	g_tc_fd;

	if (tc_move(col, row))
		return (1);
	else if (size != write(g_tc_fd, content, size))
		return (1);
	else
		return (0);
}
