NAME = asm

arg =

SRC = srcs/%.c

OBJET_ASM = objets/asm.o\
			objets/list_chain_new.o\
			objets/list_chain_add.o\
			objets/print_file.o\
			objets/ft_is.o\
			objets/print_data.o\
			objets/ft_str_is.o\
			objets/ft_str_is_number.o\
			objets/check_token.o\
			objets/get_token.o\
			objets/token_utility.o\
			objets/add_type.o\
			objets/add_word.o\
			objets/check_params.o\
			objets/skip_separator.o\
			objets/check_word.o\
			objets/liberation.o

OBJ = objets/%.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes -I ../op.h

all : lib $(NAME)

objets :
	@mkdir -p objets

lib : Makefile objets
	@make -C libft

$(OBJ) : $(SRC) $(LIB) Makefile includes/asm.h
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "Creation objets		Done !"

$(NAME) : $(OBJET_ASM) srcs/main.c
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_ASM) srcs/main.c ../op.c -o $@
	@echo "Compilation asm	Done !"
	@echo "-------------------------------"

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf objets

re : fclean all

.PHONY: objets exe clean fclean re