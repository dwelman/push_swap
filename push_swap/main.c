/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 13:50:32 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_info *info)
{
	int i;
	t_list	*trav_a;
	t_list	*trav_b;

	i = -1;
	trav_a = info->a;
	trav_b = info->b;
	while (++i < info->max)
	{
		if (trav_a)
		{
			ft_putchar(' ');
			ft_putnbr(*(int*)trav_a->data);
			trav_a = trav_a->next;
		}
		ft_putchar('\t');
		if (trav_b)
		{
			ft_putchar(' ');
			ft_putnbr(*(int*)trav_b->data);
			trav_b = trav_b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("___\t___\n a \t b\n");
}

void	print_steps(t_info *info)
{
	t_list	*trav;

	trav = info->steps;
	while (trav)
	{
		ft_printf("%s\n", (char*)info->steps->data);
		trav = trav->next;
	}
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

	init_info(&info);
	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	info.max = info.elem_a;
	check_dup(info.a);
	dumb_sort(&info);
	print_steps(&info);
	return (0);
}
