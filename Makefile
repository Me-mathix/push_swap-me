NAME		=	push_swap

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

SRC			=	push_swap.c \
				utils.c \
				main.c \
				intruction.c \
				instruction2.c \
				all_sort.c \
				utils2.c \
				presort.c


INC_DIR		=	./

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -I $(INC_DIR) -c $< -o $@

all: lib $(NAME) 

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

$(NAME): $(OBJ)
	@echo "\033[0;33m\nCOMPILING push_swap...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32m./push_swap created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ) $(OBJB)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting push_swap executable..."
	@rm -f $(NAME) push_swap
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re