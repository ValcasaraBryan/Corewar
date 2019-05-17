NAME = asm

arg =

SRC = srcs/%.c

OBJET_ASM = objets/asm.o

OBJ = objets/%.o

LIB = libft/libft.a

INCL = includes

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

all : lib $(NAME)

objets :
	@mkdir -p objets

lib : Makefile objets
	@make -C libft

$(OBJ) : $(SRC) $(LIB) Makefile includes/asm.h
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "Creation objets		Done !"

$(NAME) : $(OBJET_ASM)
	@$(CC) $(CFLAGS) $(LIB) $(OBJET_ASM) -o $@
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