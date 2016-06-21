/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 12:26:46 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_info *info)
{
	int i;

	i = 0;
	while (i < info->max)
	{
		if (info->a)
		{
			printf(" %d",*(int*)info->a->data);
			info->a = info->a->next;
		}
		ft_putchar('\t');
		if (info->b)
		{
			printf("derp %d",*(int*)info->b->data);
			info->b = info->b->next;
		}
		ft_putchar('\n');
		i++;
	}
	ft_printf("___\t___\n a \t b\n");
}

void	init_info(t_info *info)
{
	  info->elem_a = 0;
	  info->elem_b = 0;
	  info->elem_steps = 0; 
}

int		main(int argc, char **argv)
{
	t_info	info;

	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	info.max = info.elem_a;
	check_dup(info.a);
	t_list *trav = info.a;
	while (trav)
	{
		printf("%d\n", *(int*)trav->data);
		trav = trav->next;
	}
	dumb_sort(&info);
	return (0);
}
