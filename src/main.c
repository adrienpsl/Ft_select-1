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
#include <termios.h>

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

static void	init_term(_Bool start)
{
	if (start)
	{
		tc_setnoncanonical(STDIN_FILENO, 0);
		tc_cursor(0);
		tc_clear();
	}
	else
	{
		tc_wipe();
		tc_cursor(1);
		tc_setnoncanonical(STDIN_FILENO, 1);
	}
}

static void	key_dispatcher(int key, struct s_select *list, struct s_display *display, int *position)
{
	if (key == down)
	{
		list[*position].isunderline = 0;
		*position = (*position + 1) % display->nb_element;
		list[*position].isunderline = 1;
	}
	else if (key == up)
	{
		list[*position].isunderline = 0;
		*position = (*position - 1) % display->nb_element;
		if (*position < 0)
			*position = display->nb_element - 1;
		list[*position].isunderline = 1;
	}
	else if (key == right)
	{
		list[*position].isunderline = 0;
		*position = (*position + display->wrow) % display->nb_element; /* not correct */
		list[*position].isunderline = 1;
	}
}

int		ft_select(int argc, char **argv)
{
	struct s_select		list[argc - 1];
	struct s_display	display;
	int	position;
	int	key;

	key = 0;
	position = 0;
	display = (struct s_display){0};
	display.nb_element = argc - 1;
	fill_select_struct(list, argv, argc - 1);
	get_window_info(&display);
	get_list_info(&display, list, argc - 1);
	if (it_doesnt_fit(&display, argc - 1))
	{
		ft_dprintf(STDERR_FILENO, "Cannot display list, screen too small\n");
		return (1);
	}
	init_term(1);
	list[0].isunderline = 1;
	display_list(argv, list, &display, argc - 1);
	while ((key = tc_keymove()))
	{
		if (key == newline)
			break ;
		else
			key_dispatcher(key, list, &display, &position);
		tc_wipe();
		display_list(argv, list, &display, argc - 1);
	}
	init_term(0);
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
		tc_clear();
		return (1);
	}
	return (0);
}
