/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:40:07 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 17:01:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

struct	s_select
{
	unsigned short	len:14;
	unsigned short	col:14;
	unsigned short	row:14;
	_Bool			isselected:1;
	_Bool			isunderline:1;
};

struct	s_display
{
	unsigned short	wcol;
	unsigned short	wrow;
	unsigned short	colsize;
	unsigned short	nb_element;
};

enum	e_key
{
	del = 2117294875,
	up = 4283163,
	down = 4348699,
	left = 4479771,
	right = 4414235,
	backspace = 127,
	space = 32,
	newline = 10
};

void			get_window_info(struct s_display *display);

void			get_list_info(struct s_display *display,
			struct s_select *list, int nb);

_Bool			it_doesnt_fit(struct s_display *display, int nb);

void			display_list(char **argv, struct s_select *list, struct s_display *display, int nb);

void			display_selection(char **argv, struct s_select *list, struct s_display *display);

void			checkfits(struct s_display *display, int argc);

#endif
