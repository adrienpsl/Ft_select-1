/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/06 17:00:41 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <unistd.h>
#include <termcap.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

static void	fill_select_struct(struct s_select *list, char **argv, int nb)
{
	ft_bzero(list, sizeof(struct s_select) * nb);
	while (nb)
	{
		--nb;
		list[nb].len = ft_strlen(argv[nb + 1]);
	}
}

int		ft_select(int argc, char **argv)
{
	struct s_select		list[argc - 1];
	struct s_display	display;
	int	key;

	key = 0;
	display = (struct s_display){0};
	fill_select_struct(list, argv, argc - 1);
	get_window_info(&display);
	get_list_info(&display, list, argc - 1);
	if (it_doesnt_fit(&display, argc - 1))
	{
		ft_dprintf(STDERR_FILENO, "Cannot display list, screen too small\n");
		return (1);
	}
	display_list(argv, list, &display, argc - 1);
	tc_setnoncanonical(STDIN_FILENO, 0);
	/* input ft here loop */
	while ((key = tc_keymove()))
	{
		if (key == newline)
			break ;
	/*	else if (key == del || key == backspace)
		{
			list[0] = NULL;
		}
		ft_printf("%d\n", key);
	*/	else if (key == up)
		{
			tc_move(0,0);
		}
		else if (key == down)
			tc_move(2,2);
		display_list(argv, list, &display, argc - 1);
	}
	tc_wipe();
	tc_setnoncanonical(STDIN_FILENO, 1);
	/* output selected files */
	return (0);
}

int		main(int argc, char **argv)
{
	if (tc_init())
		return (1);
	else if (argc < 2)
	{
		ft_dprintf(STDERR_FILENO,
				"%s requires at least one argument.\n\nUsage:\t%s FILE|DIRECTORY...\n",
				&argv[0][2], argv[0]);
		return (1);
	}
	else if (ft_select(argc, argv))
	{
		tc_wipe();
		return (1);
	}
	return (0);
}
