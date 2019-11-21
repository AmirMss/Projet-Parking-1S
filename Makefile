NAME = test

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC =  main.c	\
	affiche_map.c	\
	affiche_voiture.c	\
	efface_voiture.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all :
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	@rm -Rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean 
	@make all

.PHONY : all clean fclean re
