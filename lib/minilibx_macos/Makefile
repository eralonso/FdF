#<---COLORS--->#
DEF_COLOR = \033[1;39m
WHITE = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

#<---NAME--->#
NOM		=	libmlx.a

#<---SRC && OTHERS--->#
OBJ_DIR	=	./obj/

SRC_C	=	mlx_shaders.c mlx_xpm.c mlx_int_str_to_wordtab.c
SRC_M	= 	mlx_new_image.m mlx_new_window.m mlx_init_loop.m

OBJ_C	=	$(addprefix $(OBJ_DIR)src_c/, $(SRC_C:%.c=%.o)) #$(SRC_C:%.c=%.o) 
OBJ_M	=	$(addprefix $(OBJ_DIR)src_m/, $(SRC_M:%.m=%.o)) #$(SRC_M:%.m=%.o) 

DEPS	+=	$(addprefix $(OBJ_DIR)src_c/, $(SRC_C:%.c=%.d)) #$(SRC_C:%.c=%.d) 
DEPS	+=	$(addprefix $(OBJ_DIR)src_m/, $(SRC_M:%.m=%.d)) #$(SRC_M:%.c=%.d) 

CFLAGS	+=	-O2 -Wno-deprecated-declarations

MDP		=	mkdir -p

#<---RULES--->#
$(OBJ_DIR)src_c/%.o: %.c Makefile
	@$(MDP) $(dir $@)
	@printf "$(PINK)         \rCompiling: $(YELLOW)$<...$(DEF_COLOR)         \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)src_m/%.o: %.m Makefile
	@$(MDP) $(dir $@)
	@printf "$(PINK)         \rCompiling: $(YELLOW)$<...$(DEF_COLOR)         \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP -c $< -o $@

all		:
	@echo ""
	@$(MAKE) $(NOM)

$(NOM)	:	$(OBJ_C) $(OBJ_M)
	@ar -crs $@ $(OBJ_C) $(OBJ_M)
	@#ranlib $@
	@printf "\n$(GREEN)LIBRARY: '$(subst .a,,$@)' has been created.$(DEF_COLOR)\n"

#$(NOM)	::
#	@echo "$(YELLOW)Nothing to be done for '$(subst .a,,$(NOM))'\n$(DEF_COLOR)"

clean	:
	@rm -rf $(OBJ_DIR) *~
	@rm -f mlx_app

fclean	:
	@$(MAKE) clean
	@$(RM) $(NOM)
	@echo "$(RED)LIBRARY: '$(subst .a,,$(NOM))' has been removed$(DEF_COLOR)"

re		:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(CIAN)LIBRARY: '$(subst .a,,$(NOM))' has been remake$(DEF_COLOR)"
	@echo ""

.PHONY:	all clean fclean re

-include	$(DEPS)
