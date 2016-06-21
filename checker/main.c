/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 09:23:16 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list(t_list *list)
{
	int	*num;
	while (list != NULL)
	{
		num = list->data;
		ft_printf("%d\n", *num);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;

	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	//print_list(info.a);
	while (get_next_instruction(&a, &b) != -1)
	{
		print_list(a);
		ft_printf("a\n");
		print_list(b);
		ft_printf("b\n");
	}
	return (0);
}
