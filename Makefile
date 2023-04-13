# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 10:08:41 by eralonso          #+#    #+#              #
#    Updated: 2023/04/13 17:38:04 by eralonso         ###   ########.fr        #
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
B_NAME		=	FdF_bonus

#<-------------------------------->LIBRARY<---------------------------------->#
LIBRARY		=	lib/
LIB_A		=	lib/libft/libft.a lib/ft_printf/libftprintf.a
LIB_SEARCH	=	-L./lib/libft -L./lib/ft_printf -L./lib/minilibx_macos \
				-lft -lftprintf -lmlx -lm

#<-------------------------------->HEADERS<---------------------------------->#
HEADER		=	./inc/
B_HEADER	=	./bonus/inc/
PRINTF_H	=	./lib/ft_printf/inc/
LIBFT_H		=	./lib/libft/
MLX_H		=	./lib/minilibx_macos/

#<--------------------------------->DIRS<------------------------------------>#
SRC_DIR		=	src/
OBJ_DIR		=	objs/

B_SRC_DIR	=	bonus/src/
B_OBJ_DIR	=	bonus/objs/

#<--------------------------------->FILES<---------------------------------->#
FILES		=	fdf utils check_map load_map print_map key_events \
				move_events button_events config views \
				key_utils print_utils print_utils2 math_utils config_utils \
				polar print_menu menu_utils menu_utils2

B_FILES		=	$(addsuffix _bonus, $(FILES))

#<--------------------------------->SRCS<----------------------------------->#
SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

B_SRCS		=	$(addprefix $(B_SRC_DIR), $(addsuffix .c, $(B_FILES)))

#<----------------------------->OBJS && DEPS<------------------------------->#
OBJS		=	$(addprefix $(OBJ_DIR), $(subst .c,.o,$(SRCS)))
DEPS		=	$(subst .o,.d,$(OBJS))

B_OBJS		=	$(addprefix $(B_OBJ_DIR), $(subst .c,.o,$(B_SRCS)))
B_DEPS		=	$(subst .o,.d,$(B_OBJS))

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		=	-I$(HEADER) -I$(PRINTF_H) -I$(LIBFT_H) -I$(MLX_H)
B_INCLUDE	=	-I$(B_HEADER) -I$(PRINTF_H) -I$(LIBFT_H) -I$(MLX_H)
FRMWK		=	-framework OpenGL -framework Appkit
#FRMWK		=	-F /System/Library/Frameworks/OpenGL.framework/Versions/A \
				-F /System/Library/Frameworks/AppKit.framework/Versions/C
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CFLAGS		=	-Wall -Wextra -Werror -O3# -fsanitize=address

#<--------------------------------->RULES<----------------------------------->#
$(OBJ_DIR)%.o	:	%.c $(LIB_A) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)       \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)       \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

$(B_OBJ_DIR)%.o	:	%.c $(LIB_A) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)       \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)       \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(B_INCLUDE) -c $< -o $@

all				:
	@$(MAKE) -C $(LIBRARY)
	@$(MAKE) $(NAME)


$(NAME)			:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_SEARCH) $(FRMWK) -o $@
	@echo "\n$(GREEN)FdF has been compiled$(DEF_COLOR)"

bonus			:
	@$(MAKE) -C $(LIBRARY)
	@$(MAKE) $(B_NAME)

$(B_NAME)			:	$(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIB_SEARCH) $(FRMWK) -o $@
	@echo "\n$(GREEN)FdF bonus has been compiled$(DEF_COLOR)"

clean			:
	@$(MAKE) clean -C $(LIBRARY)
	@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
	@echo ""
	@echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	@echo ""

fclean			:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIBRARY)
	@$(RM) $(NAME) $(B_NAME)
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
