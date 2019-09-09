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

void			get_window_info(struct s_display *display);

void			get_list_info(struct s_display *display,
			struct s_select *list, int nb);

_Bool			it_doesnt_fit(struct s_display *display, int nb);

#endif
