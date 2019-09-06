/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:10 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 16:44:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>

int	tc_output(int c)
{
	if (write(STDOUT_FILENO, &c, 1) != 1)
		return (0);
	else
		return (1);
}
