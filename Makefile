# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:03:51 by abarthel          #+#    #+#              #
#    Updated: 2019/08/16 14:48:13 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ft_select.mk

CFLAGS += -Wall -Wextra -Werror -ansi -D_POSIX_C_SOURCE

.PHONY: all clean fclean re

all: $(NAME)

$(NAME)	: $(OBJECTS)
	@$(MAKE) lib -j -C $(PATH_LIB)
	@$(CC) -ltermcap $(CFLAGS) $^ -o $@ $(LIB)
	@printf "\n\e[38;5;136m%4s [\e[1m$(NAME) built]\n\n\e[0m"

clean:
	@$(RM) $(OBJECTS) $(DEPENDS)
	@$(MAKE) clean -C $(PATH_LIB)

fclean:
	@$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
	@$(MAKE) fclean -C $(PATH_LIB)

re: fclean $(NAME)

-include $(DEPENDS)

%.o: %.c Makefile $(NAME).mk
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "\e[38;5;142m%-24s \e[38;5;37mobject built\n\e[0m" $(notdir $(basename $@))
