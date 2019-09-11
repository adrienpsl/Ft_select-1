/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:19:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 10:20:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

void	update_select_struct(struct s_select *list, struct s_display *display,
		int *position)
{
	if (*position + 1 < display->nb_element)
	{
		ft_memmove(&(list[*position]), &(list[*position + 1]),
			(display->nb_element - *position + 1) * sizeof(struct s_select));
		--display->nb_element;
		ft_bzero(&(list[display->nb_element]), sizeof(struct s_select));
	}
	else if (display->nb_element > 1)
	{
		--display->nb_element;
		ft_bzero(&(list[*position]), sizeof(struct s_select));
		--*position;
	}
	else
	{
		tc_wipe_stderr();
		init_term(0);
		exit(0);
	}
}
