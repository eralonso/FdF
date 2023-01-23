# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 10:08:41 by eralonso          #+#    #+#              #
#    Updated: 2023/01/22 18:45:28 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<--------------------------------->COLORS<----------------------------------->#
DEF_COLOR	=	\033[1;99m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
PINK		=	\033[1;95m
CIAN		=	\033[1;96m

#<--------------------------------->NAME<------------------------------------>#
NAME		=	FdF

#<-------------------------------->LIBRARY<---------------------------------->#
LIBRARY		=	lib/
LIB			=	lib/lib.a

#<-------------------------------->HEADERS<---------------------------------->#
HEADER		=	./inc/
B_HEADER	=	./bonus/inc/
PRINTF_H	=	./lib/ft_printf/inc/
LIBFT_H		=	./lib/libft/

#<--------------------------------->DIRS<------------------------------------>#
SRC_DIR		=	./src

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		=	-I $(HEADER) -I $(PRINTF_H) -I $(LIBFT_H)
B_INCLUDE	=	-I $(B_HEADER) -I $(PRINTF_H) -I $(LIBFT_H)
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CFLAGS		=	-Wall -Wextra -Werror

#<--------------------------------->RULES<----------------------------------->#
$(OBJ_DIR)%.o	:	%.c $(DEPS_SRCS) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)\rCompiling: $(YELLOW)$(notdir $<)...		$(DEF_COLOR)\r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

$(B_OBJ_DIR)%.o	:	%.c $(DEPS_SRCS) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)\rCompiling: $(YELLOW)$(notdir $<)...		$(DEF_COLOR)\r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(B_INCLUDE) -c $< -o $@

all				:
	@$(MAKE) -C $(LIBRARY)
	@$(MAKE) $(NAME)

bonus			:
	@$(MAKE) BONUS=1 all

ifndef BONUS

$(NAME)			::	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@
	@echo "\n$(GREEN)FdF has been compiled$(DEF_COLOR)"

else

$(NAME)		::	$(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIB) -o $@
	@echo "\n$(GREEN)FdF bonus has been compiled$(DEF_COLOR)"

endif

$(NAME)			::
	@echo "$(YELLOW)Nothing to be done for 'FdF'$(DEF_COLOR)"

clean			:
	@$(MAKE) clean -C $(LIBRARY)
	@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
	@echo ""
	@echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	@echo ""

fclean			:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIBRARY)
	@$(RM) $(NAME) $(BONUS)
	@echo ""
	@echo "$(RED)Program has been removed$(DEF_COLOR)"

re				:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "$(CIAN)FdF has been recompiled$(DEF_COLOR)"

.PHONY			: all clean fclean re bonus

-include		$(DEPS)
-include		$(B_DEPS)
