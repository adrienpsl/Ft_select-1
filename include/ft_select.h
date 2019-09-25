/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:40:07 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/25 10:08:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

struct	s_select
{
	char			*arg;
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

struct s_sig
{
	int	sig;
	void	(*f)(int);
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
	escape = 27,
	newline = 10
};

void	get_window_info(struct s_display *display);

void	get_list_info(struct s_display *display,
				struct s_select *list, int nb);

_Bool	it_fits(struct s_display *display);

void	display_list(struct s_select *list, struct s_display *display);

void	display_selection(struct s_select *list, struct s_display *display);

void	init_term(_Bool start);

void	key_dispatcher(int key, struct s_select *list,
		struct s_display *display, int *position);

void	update_select_struct(struct s_select *list, struct s_display *display,
		int *position);

void	key_left(struct s_select *list, struct s_display *display,
		int *position);

void	key_right(struct s_select *list, struct s_display *display,
		int *position);

void	key_up(struct s_select *list, struct s_display *display,
		int *position);

void	key_down(struct s_select *list, struct s_display *display,
		int *position);

void	key_escape(void);

int		set_signals(void);

void	background(int c);

void	quit(int c);

void	select_loop(struct s_select *list, struct s_display *display);

int	g_position;

struct s_select		*g_list;

struct s_display	*g_display;

#endif
