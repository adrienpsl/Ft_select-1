/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_setnoncanonical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:44:24 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

int	tc_setnoncanonical(int fd, _Bool reset)
{
	struct termios	termios_p;
	struct termios	verif;

	if (isatty(fd) != 1)
		return (1);
	tcgetattr(fd, &termios_p);
	if (reset)
		termios_p.c_lflag |= (ICANON | ECHO);
	else
		termios_p.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, TCSAFLUSH, &termios_p);
	tcgetattr(fd, &verif);
	if (verif.c_lflag ^ termios_p.c_lflag)
		return (1);
	else
		return (0);
}

