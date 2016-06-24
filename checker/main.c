/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/24 07:46:59 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list(t_list *list)
{
	int	*num;

	while (list != NULL)
	{
		num = list->data;
		ft_printf("%d\t", *num);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_info	info;

	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	info.max = info.elem_a;
	info.b = (t_list *)malloc(sizeof(t_list));
	info.b = NULL;
	info.elem_b = 0;
	info.diffs = (t_diff *)malloc(sizeof(t_diff));
	get_next_instruction(&info);
	//print_list(info.a);
	//ft_printf("| a\n");
	//print_list(info.b);
	//ft_printf("| b\n");
	validate(&info);
	return (0);
}
