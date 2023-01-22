# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 14:33:49 by eralonso          #+#    #+#              #
#    Updated: 2022/12/21 18:44:55 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/COLORS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
DEF_COLOR = \033[1;39m
WHITE_BOLD = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/NAME/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
NAME		= libftprintf.a

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-HEADERS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
HEADER		= ./inc/

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/DIRS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
OBJS_DIR	= objs/
SRCS_DIR	= src/
MAIN_DIR	= src/main/
UTILS_DIR	= src/utils/

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/LIBFT/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
LIB			= ../libft/libft.a
DEPS_SRCS	= ../libft/objs/*.o

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/FILES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
MAIN		:= ft_printf ft_checker ft_flags_checker
UTILS		:= ft_chars_utils ft_ptr_utils ft_nbrs_utils
FILES		+= ${MAIN}
FILES		+= ${UTILS}

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/SRCS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
UTILS_SRCS	= $(addsuffix .c, $(addprefix ${UTILS_DIR}, ${UTILS}))
MAIN_SRCS	:= $(addsuffix .c, $(addprefix ${MAIN_DIR}, ${MAIN}))
SRCS		+= ${UTILS_SRCS}
SRCS		+= ${MAIN_SRCS}

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/OBJS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
OBJS		= $(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/DEPS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
DEPS		= $(addsuffix .d, $(basename ${OBJS}))

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/COMANDS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
RM			= rm -f
AR			= ar crs
MK			= Makefile
MKD			= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I${HEADER}
B_INCLUDE	= -I${B_HEADER}

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/RULES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#
$(OBJS_DIR)%.o	:	%.c ${DEPS_SRCS} ${MK}
	@${MKD} $(dir $@)
	@printf "${PINK}\rCompiling: ${YELLOW}$<...${DEF_COLOR}							\r"
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all				:
	@echo ""
	@$(MAKE) ${NAME}

${NAME}			::	${OBJS}
	@cp ${LIB} ${NAME}
	@${AR} ${NAME} ${OBJS}
	@echo "${GREEN}\nLIBRARY: ft_printf has been created${DEF_COLOR}"

${NAME}			::
	@echo "${YELLOW}Nothing to be done for 'ft_printf'\n${DEF_COLOR}"

clean			:
	@${RM} -r ${OBJS_DIR}
	@echo "${RED}OBJS && DEPS of 'ft_printf' has been removed${DEF_COLOR}"

fclean			:	
	@$(MAKE) clean
	@${RM} ${NAME}
	@echo "${RED}LIBRARY: 'ft_printf' has been removed${DEF_COLOR}"

re				:
	@echo ""
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "${CIAN}LIBRARY: 'ft_printf' has been remake${DEF_COLOR}"

.PHONY: all clean fclean re

-include	${DEPS}
