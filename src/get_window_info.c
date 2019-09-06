/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:55:12 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 17:01:34 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>

#include "ft_select.h"

struct s_display	get_window_info(void)
{
	int	column_count;
	int	line_count;

	column_count = tgetnum("co");
	line_count = tgetnum("li");
/*	ft_printf("co:%d\nli:%d\n", column_count, line_count);
*/	return ((struct s_display){.wininfo_row = line_count,
			.wininfo_col = column_count});
}
