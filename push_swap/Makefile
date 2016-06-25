# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 09:38:38 by daviwel           #+#    #+#              #
#    Updated: 2016/06/25 14:40:27 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ../utils/store_stack.c ../utils/error_check.c ../utils/check_dup.c\
	  sort.c ../utils/inc_elems.c ../utils/ft_lstappend.c output.c\
	  ../utils/ft_lstdel.c calc.c check_stack.c calc.c get_optimal.c\
	  test_moves.c test_moves2.c test_moves3.c get_best.c do_best_op.c\
	  roll_back_moves.c sort2.c ../utils/ft_lstcpy.c try_next.c

OBJ = main.o store_stack.o error_check.o check_dup.o sort.o inc_elems.o\
	 ft_lstappend.o output.o ft_lstdel.o calc.o check_stack.o get_optimal.o\
	 test_moves.o test_moves2.o test_moves3.o get_best.o do_best_op.o\
	 roll_back_moves.o sort2.o ft_lstcpy.o try_next.o

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

