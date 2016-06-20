# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/20 17:15:03 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = main.c ../utils/error_check.c

OBJ = main.o error_check.o

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

