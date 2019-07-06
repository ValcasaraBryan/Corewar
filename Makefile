# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 16:00:31 by jdurand-          #+#    #+#              #
#    Updated: 2019/07/06 13:59:38 by jdurand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			clang
NAME_ASM =		asm
NAME_VM =		corewar
DIR_CURR =		/corewar
DIR_INCL =		./includes
DIR_LIBFT =		./libft
DIR_OBJS =		./objs
DIR_SRCS =		./srcs
FLAGS_COMP =	-g
FLAGS_INCL =	-I $(DIR_INCL)
FLAGS_LIBFT =	-L $(DIR_LIBFT) -lft
FLAGS_INCL_SDL = -I ~/.brew/include/SDL2
FLAGS_LIB_SDL = -L ~/.brew/lib/ -lsdl2 -lsdl2_ttf
FILES_HEADER =	asm.h				\
				corewar.h
FILES_SRCS_ASM =	asm.c			\
				list_chain_new.c	\
				list_chain_add.c	\
				print_file.c		\
				ft_is.c				\
				ft_str_is.c			\
				ft_str_is_number.c	\
				check_token.c		\
				get_token.c			\
				main.c				\
				token_utility.c		\
				add_type.c			\
				add_word.c			\
				check_params.c		\
				skip_separator.c	\
				check_word.c		\
				liberation.c		\
				quote.c				\
				error_msg.c			\
				check_label.c		\
				suffix_name.c		\
				op.c
FILES_SRCS_VM =	bin_extractor.c			\
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
				main_vm.c					\
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
OBJS_ASM =		$(FILES_SRCS_ASM:%.c=$(DIR_OBJS)/%.o)
OBJS_VM =		$(FILES_SRCS_VM:%.c=$(DIR_OBJS)/%.o)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL) $(FLAGS_INCL_SDL)
	@printf "."

all : libft
	@$(MAKE) $(NAME_ASM)
	@$(MAKE) $(NAME_VM)

$(NAME_ASM) : $(OBJS_ASM)
	@$(CC) $(FLAGS_COMP) -o $(NAME_ASM) $(OBJS_ASM) $(FLAGS_LIBFT) $(FLAGS_LIB_SDL)
	@echo
	@echo $(DIR_CURR) : \"$(NAME_ASM)\" made successfully

$(NAME_VM) : $(OBJS_VM)
	@$(CC) $(FLAGS_COMP) -o $(NAME_VM) $(OBJS_VM) $(FLAGS_LIBFT) $(FLAGS_LIB_SDL)
	@echo
	@echo $(DIR_CURR) : \"$(NAME_VM)\" made successfully

libft :
	@$(MAKE) -C $(DIR_LIBFT)

clean :
	@$(MAKE) -C $(DIR_LIBFT)/ clean
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_VM)
	@echo $(DIR_CURR) : all object files deleted

fclean :
	@$(MAKE) -C $(DIR_LIBFT)/ fclean
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_VM)
	@echo $(DIR_CURR) : all object files deleted
	@rm -f $(NAME_VM)
	@echo $(DIR_CURR) : \"$(NAME_VM)\" deleted
	@rm -f $(NAME_ASM)
	@echo $(DIR_CURR) : \"$(NAME_ASM)\" deleted

re : fclean all

.PHONY: all clean fclean re libft
