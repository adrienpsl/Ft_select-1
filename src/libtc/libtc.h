/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:52:15 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 13:53:16 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTC_H
# define LIBTC_H

int		tc_init(void);

int		tc_output(int c);

int		tc_bgcolor(int curses_color);

int		tc_ftcolor(int curses_color);

int		tc_reset(void);

int		tc_underline(void);

int		tc_move(int col, int row);

int		tc_keymove(void);

int		tc_clear(void);

int		tc_wipe(void);

int		tc_cursor(_Bool visible);

int		tc_setnoncanonical(int fd, _Bool reset);

int		tc_placendisplay(unsigned short col, unsigned short row, int size,
		void *content);

union	u_buffer
{
	unsigned int	value;
	char			buf[sizeof(unsigned int)];
};

int		g_tc_fd;

#endif
