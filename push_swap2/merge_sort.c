/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:37:40 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/27 17:11:11 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_wave(t_list *stack)
{
	int		ret;
	t_list	*trav;

	trav = stack;
	ret = 0;
	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			if (*(int*)trav->data > *(int*)trav->next->data)
				ret++;
			trav = trav->next;
		}
	}
	return (ret);
}

int	c_wave_rev(t_list *stack)
{
	int		ret;
	t_list	*trav;

	trav = stack;
	ret = 0;
	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			if (*(int*)trav->data < *(int*)trav->next->data)
				ret++;
			trav = trav->next;
		}
	}
	return (ret);
}

t_list	*get_last(t_list *list)
{
	t_list *ret;
	
	ret = list;
	if (ret)
	{
		while (ret->next != NULL)
			ret = ret->next;
	}
	return (ret);
}

void	fill_a(t_algo *algo, t_info *info)
{
	t_list	*last_a;

	last_a = get_last(algo->stack_a);
	while (algo->stack_b && (algo->op_count < info->in_count))
	{
		if ((algo->stack_b->next && *(int*)algo->stack_b->data < *(int*)algo->stack_b->next->data)
			&& (algo->stack_a->next && *(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data))
				ss(algo);
		if (algo->stack_b->next && *(int*)algo->stack_b->data < *(int*)algo->stack_b->next->data)
			sb(algo);
		if (algo->stack_a->next && *(int*)algo->stack_a->data > *(int*)algo->stack_a->next->data)
			sa(algo);
		pa(algo);
		if (stack_sorted(algo->stack_a) == 0 || algo->elem_a < algo->max)
			rra(algo);
		last_a = get_last(algo->stack_a);
	}
}

void	split_sort(t_algo *algo, t_info *info)
{
	int		wave_a;
	int		wave_b;

	wave_b = 0;
	info->in_count = 1000;
	while ((stack_sorted(algo->stack_a) == 0 || algo->elem_a < algo->max)
		&& (algo->op_count < info->in_count))
	{
		wave_a = c_wave(algo->stack_a);
		while (wave_a + 1 > wave_b)
		{
			pb(algo);
			//move_check
			wave_a = c_wave(algo->stack_a);
			wave_b = c_wave_rev(algo->stack_b);
		}
		fill_a(algo, info);
		ft_printf("lel\n");
		if (algo->stack_a && get_last(algo->stack_a))
			while (*(int*)algo->stack_a->data > *(int*)get_last(algo->stack_a)->data
				&& algo->op_count < info->in_count)
					rra(algo);
		print_stacks(algo->stack_a, algo->stack_b, info);
		wave_a = c_wave(algo->stack_a);
		wave_b = c_wave_rev(algo->stack_b);
		ft_printf("finish\n");
	}
}
/*		if (*(int*)algo->stack_b->data < *(int*)algo->stack_a->data)
		{
//			&& (*(int*)algo->stack_b->data < *(int*)last_a->data))
			ft_printf("lel|||||||\n");
		}
		else if (((*(int*)algo->stack_b->data < *(int*)algo->stack_a->data)
			&& (*(int*)algo->stack_a->data < *(int*)last_a->data)) || !algo->stack_a->next)
			pa(algo);
		else if ((*(int*)algo->stack_b->data > *(int*)algo->stack_a->data)
			&& (*(int*)algo->stack_a->data < *(int*)last_a->data)
			&& (*(int*)algo->stack_b->data > *(int*)last_a->data))
			pa(algo);
		else if (!algo->stack_b->next)
			pa(algo);
		else
*/	
