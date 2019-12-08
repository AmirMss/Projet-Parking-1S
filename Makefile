NAME = Parking

CC = gcc
CFLAGS = 

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC =  main.c	\
	map.c		\
	player.c	\
	util.c

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
	@echo "\033[32mParking ready !!\033[0m"

clean : 
	@rm -Rf $(OBJ_DIR)
	@make clean -C $(LIB_FT)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_FT)

re : fclean 
	@make all

.PHONY : all clean fclean re
