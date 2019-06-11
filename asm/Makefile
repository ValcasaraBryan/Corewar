NAME = asm
TEST = test

arg =

SRC = srcs/%.c

OBJET_ASM = objets/asm.o

OBJ = objets/%.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes -I ../op.h

all : lib $(NAME) test

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

test : $(OBJET_ASM) srcs/test.c
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_ASM) srcs/test.c ../op.c -o $(TEST)

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf objets

re : fclean all

.PHONY: objets exe clean fclean re