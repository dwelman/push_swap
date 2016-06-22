/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:44:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/22 15:09:41 by ddu-toit         ###   ########.fr       */
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

int		collapse_step(t_list *trav)
{
	if ((ft_strcmp("sa", (char*)trav->data) == 0 &&
		ft_strcmp("sb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("sb", (char*)trav->data) == 0 &&
		 ft_strcmp("sa", (char*)trav->next->data) == 0))
	{
			ft_putendl("ss");
			return (1);
	}
	if ((ft_strcmp("ra", (char*)trav->data) == 0 &&
		ft_strcmp("rb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rb", (char*)trav->data) == 0 &&
		 ft_strcmp("ra", (char*)trav->next->data) == 0))
	{
		ft_putendl("rr");
		return (1);
	}
	if ((ft_strcmp("rra", (char*)trav->data) == 0 &&
		ft_strcmp("rrb", (char*)trav->next->data) == 0) ||
		(ft_strcmp("rrb", (char*)trav->data) == 0 &&
		 ft_strcmp("rra", (char*)trav->next->data) == 0))
	{
		ft_putendl("rrr");
		return (1);
	}
	return (0);
}

void	print_steps(t_info *info)
{
	t_list	*trav;

	trav = info->steps;
	while (trav)
	{
		if (collapse_step(trav))
			trav = trav->next;
		else
			ft_printf("%s\n", (char*)trav->data);
		trav = trav->next;
	}
}
