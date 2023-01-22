# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:34:08 by eralonso          #+#    #+#              #
#    Updated: 2022/12/13 09:36:54 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR 	=	\033[1;39m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;30m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
CIAN		=	\033[1;36m

NAME		=	lib.a

LBFA		=	libft/libft.a
FTPFA		=	ft_printf/libftprintf.a

LIBFT_DIR	=	libft/
PRINTF_DIR	=	ft_printf/

RM			=	rm -f

#-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/RULES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-#

all			:
	@$(MAKE) library
	@$(MAKE) printf
	@$(MAKE) ${NAME}

library		::
	@$(MAKE) -C ${LIBFT_DIR}

library		::
	@echo -n

printf		::
	@$(MAKE) -C ${PRINTF_DIR}

printf		::
	@echo -n

${NAME}		:: ${LBFA} ${FTPFA}
	@cp ${LBFA} ./${NAME}
	@cp ${FTPFA} ./${NAME}

${NAME}		::
	@echo -n

clean		:
	@$(MAKE) clean -C ${LIBFT_DIR}
	@$(MAKE) clean -C ${PRINTF_DIR}

fclean		:
	@$(MAKE) fclean -C ${LIBFT_DIR}
	@$(MAKE) fclean -C ${PRINTF_DIR}
	@${RM} ${NAME}

re			:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re library printf
