NAME = test

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC =  main.c	\
	affiche_map.c	\
	affiche_voiture.c	\
	efface_voiture.c	\
	open_files.c

LIB_FT = ./libft
FT_LNK = -L $(LIB_FT) -l ft

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all :
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIB_FT)
	@make $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) -I $(LIB_FT) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(FT_LNK)

clean : 
	@rm -Rf $(OBJ_DIR)
	@make clean -C $(LIB_FT)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_FT)

re : fclean 
	@make all

.PHONY : all clean fclean re
