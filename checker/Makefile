# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/21 12:13:40 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = main.c read_instructions.c validate.c ../utils/store_stack.c \
	  ../utils/error_check.c ../utils/inc_elems.c

OBJ = main.o read_instructions.o validate.o store_stack.o error_check.o \
	  inc_elems.o

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

run:
	./printer | ./checker 4 3 2 1

norme:
	norminette $(SRC) checker.h

