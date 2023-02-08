# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 12:39:13 by eralonso          #+#    #+#              #
#    Updated: 2023/02/08 16:03:11 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------->COLORS<-----------------------------------#
DEF_COLOR = \033[1;39m
WHITE = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#------------------------------------>NAME<------------------------------------#
NAME = libft.a

#----------------------------------->HEADER<-----------------------------------#
HEADER = libft.h

#------------------------------------->SRC<----–-------------------------------#
SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c	ft_memcmp.c	ft_strlen.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strrncmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		get_next_line.c ft_nbrlen_base.c ft_matrixlen.c ft_isnumdup.c \
		ft_isint.c ft_isnum.c ft_atoll.c ft_close.c \

#------------------------------------>OBJ<-------------------------------------#
OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(subst .c,.o,$(SRCS)))

DEP = $(addsuffix .d, $(basename $(OBJS)))

#----------------------------------->COMANDS<----------------------------------#
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MDP = mkdir -p
AR = ar curs
INCLUDE = -I ./

#------------------------------------>RULES<-----------------------------------#
$(OBJS_DIR)%.o: %.c Makefile
	@$(MDP) $(dir $@)
	@printf "$(PINK)      \rCompiling: $(YELLOW)$<...$(DEF_COLOR)      \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

all			: 
	@echo ""
	@$(MAKE) $(NAME)

$(NAME)		:	$(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "\n$(GREEN)LIBRARY: '$(subst .a,,$@)' has been created.$(DEF_COLOR)\n"

#$(NAME)		:
#	@echo "$(YELLOW)Nothing to be done for '$(subst .a,,$(NAME))'$(DEF_COLOR)"

clean:
	@$(RM) -r $(OBJS_DIR)

fclean		:
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(RED)LIBRARY: '$(subst .a,,$(NAME))' has been removed.$(DEF_COLOR)"

re			:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(CIAN)LIBRARY: '$(subst .a,,$(NAME))' has been remake$(DEF_COLOR)"
	@echo ""

.PHONY: all bonus clean fclean re bonus

-include $(DEP)
