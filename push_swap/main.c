/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/24 09:00:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	init_info(t_info *info)
{
	  info->elem_a = 0;
	  info->elem_b = 0;
	  info->elem_steps = 0; 
}

int		main(int argc, char **argv)
{
	t_info	info;
	t_list	*trav;

	init_info(&info);
	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	print_stacks(&info);
	info.max = info.elem_a;
	check_dup(info.a);
	info.median = median(&info);
	print_stacks(&info);
	printf("median = %d\n", info.median);
	trav = info.a;
	while (trav)
	{
		ft_printf("opt pos of %d : %d\t", *(int*)trav->data, trav->op_pos);
		printf("cur pos = %d\n", get_curpos(info.a, trav));
		ft_printf("%d moves to opt\n", calc_moves_to_op(trav->op_pos, get_curpos(info.a, trav), &info));
		trav = trav->next;
	}
	print_stacks(&info);
	ft_printf("total fuckedupness = %d\nindividual total fuckedupness with different moves\n", calc_total_sortdiff(&info));
/*
	test_sa(&info);
	test_sb(&info);
	test_ss(&info);
	test_ra(&info);
	test_rb(&info);
	test_rr(&info);
	test_rra(&info);
	test_rrb(&info);
	test_rrr(&info);
	test_pa(&info);
	test_pb(&info);
	printf("sa = %d\n", info.diffs->sa);
	printf("sb = %d\n", info.diffs->sb);
	printf("ss = %d\n", info.diffs->ss);	
	print_steps(&info);*/
	return (0);
}
