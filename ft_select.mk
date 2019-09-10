# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/09/06 17:01:27 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_select

SOURCES_PATH := ./src/

SOURCES :=	main.c \
		get_window_info.c \
		display_list.c \
		term.c \
		input_key.c \
		update_struct.c \
		libtc/tc_init.c \
		libtc/tc_output.c \
		libtc/tc_output_stderr.c \
		libtc/tc_bgcolor.c \
		libtc/tc_bgcolor_stderr.c \
		libtc/tc_ftcolor.c \
		libtc/tc_ftcolor_stderr.c \
		libtc/tc_reset.c \
		libtc/tc_reset_stderr.c \
		libtc/tc_move.c \
		libtc/tc_move_stderr.c \
		libtc/tc_keymove.c \
		libtc/tc_clear.c \
		libtc/tc_clear_stderr.c \
		libtc/tc_wipe.c \
		libtc/tc_wipe_stderr.c \
		libtc/tc_cursor.c \
		libtc/tc_cursor_stderr.c \
		libtc/tc_underline.c \
		libtc/tc_underline_stderr.c \
		libtc/tc_setnoncanonical.c \
		libtc/tc_placendisplay.c \
		libtc/tc_placendisplay_stderr.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIBFT := ./libft/

INCLUDES := -I./include/ -I$(PATH_LIBFT)include/ -I./src/libtc/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TEST := ./ft_select include/* src/**/* auteur ft_select ft_select.mk src/**/* ok pl kksjjsjsj dwdsdsd d ewe  ewwe  w ew ew eew ew ew   ouihwoh qw owohu  ew * *

LDLIBS += -ltermcap $(PATH_LIBFT)libft.a

#LDFLAGS += -flto=full

CFLAGS += -Wall -Wextra -Werror -D_POSIX_C_SOURCE
ifneq ($(shell uname -s),Darwin)
	CFLAGS += -ansi
endif

CFLAGS += -g -fsanitize=address
#CFLAGS += -fno-builtin -O2
