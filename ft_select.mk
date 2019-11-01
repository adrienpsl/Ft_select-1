# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_select.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/09/11 18:17:14 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_select

SOURCES_PATH := ./src/

SOURCES :=	main.c \
		get_window_info.c \
		display_list.c \
		term.c \
		input_key.c \
		input_key2.c \
		update_struct.c \
		signals.c \
		libtc/tc_init.c \
		libtc/tc_output.c \
		libtc/tc_bgcolor.c \
		libtc/tc_ftcolor.c \
		libtc/tc_reset.c \
		libtc/tc_move.c \
		libtc/tc_keymove.c \
		libtc/tc_clear.c \
		libtc/tc_wipe.c \
		libtc/tc_cursor.c \
		libtc/tc_underline.c \
		libtc/tc_setnoncanonical.c \
		libtc/tc_placendisplay.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

PATH_LIBFT := ./libft/

INCLUDES := -I./include/ -I$(PATH_LIBFT)include/ -I./src/libtc/

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

LDLIBS += -ltermcap $(PATH_LIBFT)libft.a

#LDFLAGS += -flto=full

ifneq ($(shell uname -s),Darwin)
	CFLAGS += -ansi -Wall -Wextra -Werror -std=c99 -D_POSIX_C_SOURCE
else
	CFLAGS += -Wall -Wextra -Werror -D_DARWIN_C_SOURCE -std=c99
endif

CFLAGS += -g -fsanitize=address
#CFLAGS += -fno-builtin -O2
