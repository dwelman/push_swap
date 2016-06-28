/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/28 15:54:36 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Runs sorting algorithms and stores results
*/

void	run_sort_algorithms(t_info *info)
{
	t_algo	*best;
	t_algo	*b_sort;
	t_algo	*s_sort;
	t_algo	*d_sort;

	b_sort = new_algo(info);
	s_sort = new_algo(info);
	d_sort = new_algo(info);
	info->in_count = dumb_sort(d_sort, info);
	best = d_sort;
	bubble_sort(b_sort, info);
	if (b_sort->op_count < best->op_count && stack_sorted(b_sort->stack_a))
		best = b_sort;
	split_sort(s_sort, info);
	if (s_sort->op_count < best->op_count && stack_sorted(s_sort->stack_a))
		best = s_sort;
	t_info *test;
	test = sort_stacks(info);
	ft_printf("OPERATIONS FOR THIS WEIRD FUNCTION = %d\n", test->elem_steps);
	rollback_sort(info);
	if (info->elem_steps < best->op_count && stack_sorted(info->a))
		print_steps(info->steps);
	else
		print_steps(best->operations);
	delete_algo(&b_sort);
	delete_algo(&s_sort);
	delete_algo(&d_sort);
}

int		main(int argc, char **argv)
{
	t_info	info;

	init_info(&info);
	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	info.max = info.elem_a;
	check_dup(info.a);
	info.median = median(&info);
	run_sort_algorithms(&info);
	return (0);
}
