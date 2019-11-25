# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 20:10:01 by tbeguin           #+#    #+#              #
#    Updated: 2019/09/21 07:11:06 by tbeguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =  ft_memset.c 	\
	   ft_bzero.c 		\
	   ft_memcpy.c 		\
	   ft_memccpy.c 	\
	   ft_memmove.c 	\
	   ft_memchr.c 		\
	   ft_memcmp.c 		\
	   ft_strlen.c 		\
	   ft_strdup.c 		\
	   ft_strcpy.c		\
	   ft_strncpy.c		\
	   ft_strcat.c 		\
	   ft_strncat.c 	\
	   ft_strlcat.c 	\
	   ft_strchr.c 		\
	   ft_strrchr.c 	\
	   ft_strstr.c 		\
	   ft_strnstr.c 	\
	   ft_strcmp.c 		\
	   ft_strncmp.c 	\
	   ft_atoi.c 		\
	   ft_isalpha.c 	\
	   ft_isdigit.c 	\
	   ft_isalnum.c 	\
	   ft_isascii.c 	\
	   ft_isprint.c 	\
	   ft_toupper.c 	\
	   ft_tolower.c 	\
	   ft_memalloc.c 	\
	   ft_memdel.c		\
	   ft_strnew.c		\
	   ft_strdel.c		\
	   ft_strclr.c		\
	   ft_striter.c		\
	   ft_striteri.c	\
	   ft_strmap.c		\
	   ft_strmapi.c		\
	   ft_strequ.c		\
	   ft_strnequ.c		\
	   ft_strsub.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_strsplit.c	\
	   ft_itoa.c		\
	   ft_putchar.c		\
	   ft_putstr.c		\
	   ft_putendl.c		\
	   ft_putnbr.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   ft_lstnew.c		\
	   ft_lstdelone.c	\
	   ft_lstdel.c		\
	   ft_lstadd.c		\
	   ft_lstiter.c		\
	   ft_lstmap.c		\
	   ft_islower.c		\
	   ft_isupper.c		\
	   ft_lstrev.c		\
	   get_next_line.c	

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(OBJS) : %.o:%.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mLibft Created\033[0m"

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved Libft\033[0m"

re : fclean all

.PHONY : all clean fclean re
