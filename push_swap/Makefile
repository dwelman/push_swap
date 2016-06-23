# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/23 08:01:04 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ../utils/store_stack.c ../utils/error_check.c ../utils/check_dup.c\
	  sort.c ../utils/inc_elems.c ../utils/ft_lstappend.c output.c \
	  check_stack.c

OBJ = main.o store_stack.o error_check.o check_dup.o sort.o inc_elems.o\
	  ft_lstappend.o output.o check_stack.o

CFLAG = -Wall -Werror -Wextra

ATTACH = -L ../libft/ -lft

all: $(NAME)

$(NAME):
	clang $(CFLAG) -I ../lbft -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) checker.h

