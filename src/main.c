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
		list[nb].arg = argv[nb + 1];
		list[nb].len = ft_strlen(argv[nb + 1]);
	}
}

static __inline__ void	initialize_select_var(int *key, int *position, struct s_display *display, int argc)
{
	*key = 0;
	*position = 0;
	*display = (struct s_display){0};
	display->nb_element = argc - 1;
}

int		ft_select(int argc, char **argv)
{
	struct s_select		list[argc - 1];
	struct s_display	display;
	int	position;
	int	key;

	initialize_select_var(&key, &position, &display, argc);
	fill_select_struct(list, argv, display.nb_element);
	get_window_info(&display);
	get_list_info(&display, list, display.nb_element);
	checkfits(&display, argc);
	init_term(1);
	list[0].isunderline = 1;
	display_list(list, &display);
	while ((key = tc_keymove()))
	{
		if (key == newline)
			break ;
		else
			key_dispatcher(key, list, &display, &position);
		tc_wipe();
		display_list(list, &display);
	}
	init_term(0);
	display_selection(list, &display);
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
		return (1);
	return (0);
}
