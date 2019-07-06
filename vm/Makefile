# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 16:00:31 by jdurand-          #+#    #+#              #
#    Updated: 2019/07/06 09:52:59 by jdurand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			clang
NAME =			corewar
DIR_CURR =		/vm
DIR_INCL =		./includes
DIR_LIBFT =		./libft
DIR_OBJS =		./objs
DIR_SRCS =		./srcs
FLAGS_COMP =	-g -Weverything -Wno-padded -Wno-sign-conversion -Wno-gnu-union-cast
FLAGS_INCL =	-I $(DIR_INCL)
FLAGS_LIBFT =	-L $(DIR_LIBFT) -lft
FLAGS_INCL_SDL = -I ~/.brew/include/SDL2
FLAGS_LIB_SDL = -L ~/.brew/lib/ -lsdl2 -lsdl2_ttf
FILES_HEADER =	corewar.h
FILES_SRCS =	bin_extractor.c			\
				functions_announce.c	\
				functions_byte.c		\
				functions_champion.c	\
				functions_get_args.c	\
				functions_grid.c		\
				functions_read_write.c	\
				functions_storage.c		\
				functions_thread.c		\
				instr_add.c				\
				instr_aff.c				\
				instr_and.c				\
				instr_fork.c			\
				instr_ld.c				\
				instr_ldi.c				\
				instr_lfork.c			\
				instr_live.c			\
				instr_lld.c				\
				instr_lldi.c			\
				instr_move.c			\
				instr_or.c				\
				instr_st.c				\
				instr_sti.c				\
				instr_sub.c				\
				instr_xor.c				\
				instr_zjmp.c			\
				main.c					\
				manage_byte.c			\
				manage_champion.c		\
				manage_grid.c			\
				manage_print.c			\
				manage_storage.c		\
				manage_thread.c			\
				process_battle.c		\
				set_values_instr.c		\
				structs_check.c			\
				structs_setup.c			\
				utilities_a.c 			\
				utilities_b.c 			\
				visu_free.c				\
				visu_init_sdl.c			\
				visu_print_grid.c 		\
				visu_print_infos.c 		\
				visu_print_players.c	\
				visu_print_threads.c	\
				visu_utilities.c
HEADERS =		$(FILES_HEADER:%.h=$(DIR_INCL)/%.h)
OBJS =			$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS =			$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL) $(FLAGS_INCL_SDL)
	@printf "."

all : libft
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS_COMP) -o $(NAME) $(OBJS) $(FLAGS_LIBFT) $(FLAGS_LIB_SDL)
	@echo
	@echo $(DIR_CURR) : \"$(NAME)\" made successfully

libft :
	@$(MAKE) -C $(DIR_LIBFT)

clean :
	@$(MAKE) -C $(DIR_LIBFT)/ clean
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted

fclean :
	@$(MAKE) -C $(DIR_LIBFT)/ fclean
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted
	@rm -f $(NAME)
	@echo $(DIR_CURR) : \"$(NAME)\" deleted

re : fclean all

normec :
	@$(MAKE) -C $(DIR_LIBFT)/ normec
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

normeh :
	@$(MAKE) -C $(DIR_LIBFT)/ normeh
	@norminette -R CheckForbiddenSourceHeader $(HEADERS)

.PHONY: all clean fclean re libft normec normeh
