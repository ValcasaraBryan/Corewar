# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 16:00:31 by jdurand-          #+#    #+#              #
#    Updated: 2019/05/17 16:02:37 by jdurand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
NAME =			corewar
DIR_CURR =		/vm
DIR_INCL =		./includes
DIR_MLX =		~/projets/libs
DIR_LIBFT =		./libft
DIR_OBJS =		./objs
DIR_SRCS =		./srcs
FLAGS_COMP =	-Wall -Wextra -Werror
FLAGS_INCL =	-I $(DIR_INCL)
FLAGS_LIBFT =	-L $(DIR_LIBFT) -lft
FLAGS_MLX =		-L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
FILES_HEADER =	corewar.h
FILES_SRCS =	main.c
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
	@$(CC) $(FLAGS_COMP) -o $(NAME) $(OBJS) $(FLAGS_LIBFT) $(FLAGS_MLX)
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

.PHONY: clean fclean re all libft
