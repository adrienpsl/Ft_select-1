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
		libtc/tc_init.c \
		libtc/tc_output.c \
		libtc/tc_bgcolor.c \
		libtc/tc_ftcolor.c \
		libtc/tc_reset.c \
		libtc/tc_move.c \
		libtc/tc_clear.c \
		libtc/tc_underline.c \
		libtc/tc_setnoncanonical.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/ -I./src/libtc/

PATH_LIB := ./libft/

LIB := $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TEST := ./ft_select Makefile src libft ft_select.mk

LDLIBS += -ltermcap

LDFLAGS += 

CFLAGS += -Wall -Wextra -Werror -D_POSIX_C_SOURCE
ifneq ($(shell uname -s),Darwin)
	CFLAGS += -ansi
endif

CFLAGS += -g -fsanitize=address
#CFLAGS += -fno-builtin -O2 -ftlo=full
