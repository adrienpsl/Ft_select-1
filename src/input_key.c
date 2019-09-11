/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 19:40:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>
#include <termios.h>

#include "ft_select.h"
#include "libtc.h"

static void	key_space(struct s_select *list, struct s_display *display,
		int *position)
{
	list[*position].isselected ^= 1;
	key_down(list, display, position);
}

static void	key_del(struct s_select *list, struct s_display *display,
		int *position)
{
	update_select_struct(list, display, position);
	list[*position].isunderline = 1;
}

static void	key_escape(void)
{
	init_term(0);
	exit(0);
}

void		key_dispatcher(int key, struct s_select *list,
		struct s_display *display, int *position)
{
	if (key == space)
		key_space(list, display, position);
	else if (key == down)
		key_down(list, display, position);
	else if (key == up)
		key_up(list, display, position);
	else if (key == right)
		key_right(list, display, position);
	else if (key == left)
		key_left(list, display, position);
	else if (key == del || key == backspace)
		key_del(list, display, position);
	else if (key == escape)
		key_escape();
}
