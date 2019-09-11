/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 13:58:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <termios.h>

#include "ft_select.h"
#include "libtc.h"

void	key_up(struct s_select *list, struct s_display *display,
		int *position)
{
	list[*position].isunderline = 0;
	*position = (*position - 1) % display->nb_element;
	if (*position < 0)
		*position = display->nb_element - 1;
	list[*position].isunderline = 1;
}

void	key_down(struct s_select *list, struct s_display *display,
		int *position)
{
	list[*position].isunderline = 0;
	*position = (*position + 1) % display->nb_element;
	list[*position].isunderline = 1;
}

void	key_right(struct s_select *list, struct s_display *display,
		int *position)
{
	if (display->nb_element <= display->wrow)
		return ;
	list[*position].isunderline = 0;
	if ((*position + display->wrow) % display->nb_element < *position)
		*position = list[*position].row;
	else
		*position = *position + display->wrow;
	list[*position].isunderline = 1;
}

void	key_left(struct s_select *list, struct s_display *display,
		int *position)
{
	if (display->nb_element <= display->wrow)
		return ;
	list[*position].isunderline = 0;
	if (list[*position].col == 0)
	{
		if (list[*position].row <= display->nb_element % display->wrow)
			*position = display->nb_element -
				(display->nb_element % display->wrow) + list[*position].row;
		else
			*position = display->nb_element -
			(display->wrow - *position) - (display->nb_element % display->wrow);
		if (*position >= display->nb_element)
			*position -= display->wrow;
	}
	else
		*position = *position - display->wrow;
	list[*position].isunderline = 1;
}
