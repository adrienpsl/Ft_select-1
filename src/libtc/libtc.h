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
int	tc_output_stderr(int c);

int	tc_bgcolor(int curses_color);
int	tc_bgcolor_stderr(int curses_color);

int	tc_ftcolor(int curses_color);
int	tc_ftcolor_stderr(int curses_color);

int	tc_reset(void);
int	tc_reset_stderr(void);

int	tc_underline(void);
int	tc_underline_stderr(void);

int	tc_move(int col, int row);
int	tc_move_stderr(int col, int row);

int	tc_keymove(void);

int	tc_clear(void);
int	tc_clear_stderr(void);

int	tc_wipe(void);
int	tc_wipe_stderr(void);

int	tc_cursor(_Bool visible);
int	tc_cursor_stderr(_Bool visible);

int	tc_setnoncanonical(int fd, _Bool reset);

int	tc_placendisplay(unsigned short col, unsigned short row, int size, void *content);
int	tc_placendisplay_stderr(unsigned short col, unsigned short row, int size, void *content);

union	u_buffer
{
	unsigned int	value;
	char		buf[sizeof(unsigned int)];
};

#endif
