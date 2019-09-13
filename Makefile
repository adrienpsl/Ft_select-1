# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:03:51 by abarthel          #+#    #+#              #
#    Updated: 2019/09/11 16:08:58 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ft_select.mk

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) lib -j -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)
	@printf "\n\e[38;5;136m%4s [\e[1m$(NAME) built]\n\n\e[0m"
	@printf "\n\e[31m%s[\e[1mWARNING]: ft_select uses deprecated and non POSIX compliant functions such as signal(2) and termcaps.\nIt may not properly work on your system \e[32m$(shell uname -s).\n\n\e[0m"

clean:
	@$(RM) $(OBJECTS) $(DEPENDS)
	@$(MAKE) clean -C $(PATH_LIBFT)

fclean:
	@$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
	@$(MAKE) fclean -C $(PATH_LIBFT)

re: fclean $(NAME)

test: all
	$(TEST)

-include $(DEPENDS)

%.o: %.c Makefile $(NAME).mk
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "\e[38;5;142m%-24s \e[38;5;37mobject built\n\e[0m" $(notdir $(basename $@))
