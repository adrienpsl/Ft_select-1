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

int	tc_reset(void);

int	tc_underline(void);

#endif
