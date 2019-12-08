NAME = Parking

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC =  main.c	\
	map.c		\
	player.c	\
	util.c		\
	place.c		\
	my_lib.c


OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all :
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mParking ready !!\033[0m"

clean : 
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mRemoved Obj\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved $(NAME)\033[0m"

re : fclean 
	@make all

.PHONY : all clean fclean re
