/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:52:15 by abarthel          #+#    #+#             */
/*   Updated: 2019/04/18 12:17:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTC_H
# define LIBTC_H

int	tc_init(void);

int	tc_output(int c);

int	tc_bgcolor(int curses_color);

int	tc_ftcolor(int curses_color);

int	tc_reset(void);

int	tc_underline(void);

int	tc_move(int col, int row);

int	tc_clear(void);

int	tc_setnoncanonical(int fd, _Bool reset);

union	u_buffer
{
	unsigned int	value;
	char		buf[sizeof(unsigned int)];
};

enum	e_key
{
	up = 4283163,
	down = 4348699,
	left = 4479771,
	right = 4414235,
	enter = 32,
	space = 10
};

#endif
