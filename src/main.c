/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/11 15:03:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include <termcap.h>
#include <termios.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

static int	fill_select_struct(struct s_select *list, char **argv, int argc)
{
	int	i;
	int	count;

	ft_bzero(list, sizeof(struct s_select) * (argc - 1));
	i = 1;
	count = 0;
	while (i < argc)
	{
		while (!(list[count].len = ft_strlen(argv[i])))
			++i;
		list[count].arg = argv[i];
		++i;
		++count;
	}
	return (count);
}

static void	initialize_select_var(int *key, int *position,
		struct s_display *display)
{
	char		*ttyname_s;
	extern int	g_tc_fd;

	if (!(ttyname_s = ttyname(STDIN_FILENO)))
		exit(1);
	else if ((g_tc_fd = open(ttyname_s, O_RDWR)) == -1)
		exit(1);
	*key = 0;
	*position = 0;
	*display = (struct s_display){.wcol = 0, .wrow = 0, .colsize = 0,
									.nb_element = 0};
}

#ifdef __unix__

int			ft_select(int argc, char **argv)
{
	struct s_select		list[argc - 1];
	struct s_display	display;
	int					position;
	int					key;

	initialize_select_var(&key, &position, &display);
	display.nb_element = fill_select_struct(list, argv, argc);
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

#else

int			ft_select(int argc, char **argv)
{
	struct s_select		list[argc - 1];
	struct s_display	display;
	int					position;
	int					key;

	initialize_select_var(&key, &position, &display);
	display.nb_element = fill_select_struct(list, argv, argc);
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
		display_list(list, &display);
	}
	init_term(0);
	display_selection(list, &display);
	return (0);
}

#endif

int			main(int argc, char **argv)
{
	extern int	g_tc_fd;

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
	close(g_tc_fd);
	return (0);
}
