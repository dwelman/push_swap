/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/27 17:12:36 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Runs sorting algorithms and stores results
*/

void	run_sort_algorithms(t_info *info)
{
	t_algo	*b_sort;
	t_algo	*merge_sort;
//	t_algo	*select_sort;
	t_algo	*d_sort;

	b_sort = new_algo(info);
	merge_sort = new_algo(info);
//	select_sort = new_algo(info);
	d_sort = new_algo(info);

	ft_printf("dumb sort\n");
	info->in_count = dumb_sort(d_sort, info);
	ft_printf("operations = %d\n", d_sort->op_count);
	print_stacks(d_sort->stack_a, d_sort->stack_b, info);
	ft_printf("bubble sort\n");
	bubble_sort(b_sort, info);
	ft_printf("operations = %d\n", b_sort->op_count);
	if (b_sort->op_count < info->in_count && stack_sorted(b_sort->stack_a))
		info->selection = BUBBLE;
	print_stacks(b_sort->stack_a, b_sort->stack_b, info);
	ft_printf("split\n");
	split_sort(merge_sort, info);
	ft_printf("operations = %d\n", merge_sort->op_count);
	if (b_sort->op_count < info->in_count && stack_sorted(b_sort->stack_a))
	print_stacks(b_sort->stack_a, b_sort->stack_b, info);
	ft_printf("rollback\n");
	rollback_sort(info);
	print_stacks(info->a, info->b, info);
	ft_printf("operations = %d\n", info->elem_steps);
//	ft_printf("select sort\n");
//	print_stacks(select_sort->stack_a, select_sort->stack_b, info);
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
	print_stacks(info.a, info.b, &info);
	run_sort_algorithms(&info);
//	print_steps();
	return (0);
}
