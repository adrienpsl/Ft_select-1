/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:43:59 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:44:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>

#include "libft.h"

int	tc_init(void)
{
	char	*term_type;

	if (!(term_type = ft_getenv("TERM")))
	{
		ft_dprintf(STDERR_FILENO, "TERM environnement variable not defined.\n");
		return (1);
	}
	if (tgetent(NULL, term_type) != 1)
	{
		ft_dprintf(STDERR_FILENO, "Terminfo error.\n");
		return (1);
	}
	return (0);
}
