# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 23:01:19 by brvalcas          #+#    #+#              #
#    Updated: 2019/05/10 12:36:13 by brvalcas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

EXE = 0

ARG = 0
ARG_2 = 0

SRC =	srcs/free/free_tab_str.c\
		srcs/free/free_line.c\
		\
		srcs/ft_is/ft_isalnum.c\
		srcs/ft_is/ft_isalpha.c\
		srcs/ft_is/ft_isascii.c\
		srcs/ft_is/ft_isdigit.c\
		srcs/ft_is/ft_isprint.c\
		\
		srcs/ft_lst/ft_lstadd.c\
		srcs/ft_lst/ft_lstdel.c\
		srcs/ft_lst/ft_lstdelone.c\
		srcs/ft_lst/ft_lstiter.c\
		srcs/ft_lst/ft_lstmap.c\
		srcs/ft_lst/ft_lstnew.c\
		\
		srcs/ft_mem/ft_bzero.c\
		srcs/ft_mem/ft_memalloc.c\
		srcs/ft_mem/ft_memccpy.c\
		srcs/ft_mem/ft_memchr.c\
		srcs/ft_mem/ft_memcmp.c\
		srcs/ft_mem/ft_memcpy.c\
		srcs/ft_mem/ft_memdel.c\
		srcs/ft_mem/ft_memjoin.c\
		srcs/ft_mem/ft_memmove.c\
		srcs/ft_mem/ft_memset.c\
		\
		srcs/ft_print/ft_buff_printf.c\
		srcs/ft_print/ft_print_words_tables.c\
		\
		srcs/ft_put/ft_putchar.c\
		srcs/ft_put/ft_putchar_fd.c\
		srcs/ft_put/ft_putchar_len.c\
		srcs/ft_put/ft_putendl.c\
		srcs/ft_put/ft_putendl_fd.c\
		srcs/ft_put/ft_putnbr.c\
		srcs/ft_put/ft_putnbr_fd.c\
		srcs/ft_put/ft_putstr.c\
		srcs/ft_put/ft_putstr_fd.c\
		srcs/ft_put/ft_putstr_len.c\
		\
		srcs/ft_str/ft_str_is_digit.c\
		srcs/ft_str/ft_str_is_int.c\
		srcs/ft_str/ft_strcat.c\
		srcs/ft_str/ft_strchr.c\
		srcs/ft_str/ft_strclr.c\
		srcs/ft_str/ft_strcmp.c\
		srcs/ft_str/ft_strcpy.c\
		srcs/ft_str/ft_strdel.c\
		srcs/ft_str/ft_strdup.c\
		srcs/ft_str/ft_strequ.c\
		srcs/ft_str/ft_striter.c\
		srcs/ft_str/ft_striteri.c\
		srcs/ft_str/ft_strjoin.c\
		srcs/ft_str/ft_strjoin_free.c\
		srcs/ft_str/ft_strlcat.c\
		srcs/ft_str/ft_strlen.c\
		srcs/ft_str/ft_strmap.c\
		srcs/ft_str/ft_strmapi.c\
		srcs/ft_str/ft_strncat.c\
		srcs/ft_str/ft_strnchr.c\
		srcs/ft_str/ft_strncmp.c\
		srcs/ft_str/ft_strncpy.c\
		srcs/ft_str/ft_strndup.c\
		srcs/ft_str/ft_strnequ.c\
		srcs/ft_str/ft_strnew.c\
		srcs/ft_str/ft_strnjoin.c\
		srcs/ft_str/ft_strnstr.c\
		srcs/ft_str/ft_strrchr.c\
		srcs/ft_str/ft_strsplit.c\
		srcs/ft_str/ft_strstr.c\
		srcs/ft_str/ft_strsub.c\
		srcs/ft_str/ft_strtrim.c\
		\
		srcs/ft_to/ft_tolower.c\
		srcs/ft_to/ft_toupper.c\
		\
		srcs/ft_to_ascii/ft_dotoa.c\
		srcs/ft_to_ascii/ft_itoa.c\
		srcs/ft_to_ascii/ft_lltoa.c\
		srcs/ft_to_ascii/ft_lltoa_base.c\
		srcs/ft_to_ascii/ft_ulltoa.c\
		srcs/ft_to_ascii/ft_ulltoa_base.c\
		\
		srcs/ft_to_int/ft_atoi.c\
		srcs/ft_to_int/ft_atoll.c\
		srcs/ft_to_int/ft_atoull.c\
		\
		srcs/ft_unicode/ft_putval_tab.c\
		srcs/ft_unicode/ft_putwchar.c\
		srcs/ft_unicode/ft_unicode_to_str.c\
		srcs/ft_unicode/ft_set_octet.c\
		srcs/ft_unicode/ft_set_unichar.c\
		srcs/ft_unicode/ft_wchar_len.c\
		srcs/ft_unicode/ft_wset_plage_byte.c\
		\
		srcs/GNL/get_next_line.c\
		\
		srcs/maths/ft_absolue.c\
		srcs/maths/pgcd.c\
		srcs/maths/ft_sqrt.c\
		srcs/maths/ft_recursive_factorial.c\
		srcs/maths/ft_recursive_power.c\
		srcs/maths/ft_fibonacci.c\
		srcs/maths/ft_is_prime.c\
		srcs/maths/ft_find_next_prime.c\
		\
		srcs/ft_printf/ft_printf.c\
		srcs/ft_printf/argument_flag.c\
		srcs/ft_printf/init_list.c\
		srcs/ft_printf/tab_option.c\
		srcs/ft_printf/option_value.c\
		srcs/ft_printf/free_data.c\
		srcs/ft_printf/conversion.c\
		srcs/ft_printf/conversion_two.c\
		srcs/ft_printf/conversion_three.c\
		srcs/ft_printf/conversion_four.c\
		\
		srcs/ft_len/ft_len_tab_str.c

OBJET = $(SRC:.c=.o)

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)
CC = @gcc

all : $(NAME)

$(OBJET): includes/libft.h includes/ft_printf.h includes/get_next_line.h Makefile

$(NAME) : $(OBJET)
	@ar rc $@ $^
	@ranlib $@
	@echo "Creation libft.a	Done !"
	@echo "-------------------------------"


comp : $(NAME)
ifeq ($(EXE), 0)
	@echo "Usage : La variable EXE n'est pas initialisee"
else
	@gcc $(NAME) ~/Documents/libft/Programme/main/main_$(EXE).c -o ~/Documents/libft/Programme/$(EXE)
endif
exe : comp
ifneq ($(EXE), 0)
ifeq ($(ARG), 0)
	@echo "Usage : La variable ARG n'est pas initialisee"
else
ifeq ($(ARG_2), 0)
	@~/Documents/libft/Programme/$(EXE) $(ARG)
else
	@~/Documents/libft/Programme/$(EXE) $(ARG) $(ARG_2)
endif
endif
endif
debug :
ifneq ($(EXE), 0)
	cpp ~/Documents/libft/Programme/main/main_$(EXE).c
else
	@echo "Usage : La variable EXE n'est pas initialisee"
endif

norm_cat: norm 
	@clear
	@cat norm.txt
	@rm norm.txt

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)

re : fclean all
