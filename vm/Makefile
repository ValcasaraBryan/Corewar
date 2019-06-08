# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 16:00:31 by jdurand-          #+#    #+#              #
#    Updated: 2019/06/08 19:09:11 by jdurand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
NAME =			corewar
DIR_CURR =		/vm
DIR_INCL =		./includes
DIR_LIBFT =		./libft
DIR_OBJS =		./objs
DIR_SRCS =		./srcs
FLAGS_COMP =	-Wall -Wextra -Werror
FLAGS_INCL =	-I $(DIR_INCL)
FLAGS_LIBFT =	-L $(DIR_LIBFT) -lft
FILES_HEADER =	corewar.h
FILES_SRCS =	bin_extractor.c			\
				functions_byte.c		\
				functions_champion.c	\
				functions_grid.c		\
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
				key_functions.c			\
				main.c					\
				manage_byte.c			\
				manage_champion.c		\
				manage_grid.c			\
				manage_storage.c		\
				manage_thread.c			\
				structs_check.c			\
				structs_print.c			\
				tempo_utility.c			\
				unit_tests.c			\
				utilities.c
HEADERS =		$(FILES_HEADER:%.h=$(DIR_INCL)/%.h)
OBJS =			$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS =			$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

all : libft
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS_COMP) -o $(NAME) $(OBJS) $(FLAGS_LIBFT)
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
