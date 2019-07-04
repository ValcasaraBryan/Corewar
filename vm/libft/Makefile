# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 16:18:24 by jdurand-          #+#    #+#              #
#    Updated: 2019/07/04 09:26:20 by jdurand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
NAME =			libft.a
DIR_CURR =		/libft
DIR_INCL =		./includes
DIR_OBJS =		./objs
DIR_SRCS =		./srcs
FLAGS_COMP =	-Wall -Wextra -Werror
FLAGS_INCL =	-I $(DIR_INCL)
FILES_HEADER =	libft.h
FILES_SRCS =	ft_atoi.c			\
				ft_bzero.c			\
				ft_putchar.c		\
				ft_putnbr.c			\
				ft_putstr.c			\
				ft_putstr_fd.c		\
				ft_strcmp.c			\
				ft_strdup.c			\
				ft_strlen.c			\
				ft_strnew.c
HEADERS =		$(FILES_HEADER:%.h=$(DIR_INCL)/%.h)
OBJS =			$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS =			$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo
	@echo $(DIR_CURR) : \"$(NAME)\" made successfully

all : $(NAME)

clean :
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted

fclean : clean
	@rm -f $(NAME)
	@echo $(DIR_CURR) : \"$(NAME)\" deleted

re : fclean all

normec :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

normeh :
	@norminette -R CheckForbiddenSourceHeader $(HEADERS)

.PHONY: all clean fclean re normec normeh
