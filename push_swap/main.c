/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/24 12:12:23 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	init_info(t_info *info)
{
	info->elem_a = 0;
	info->elem_b = 0;
	info->elem_steps = 0;
	info->b = NULL;
	info->a = NULL;
	info->diffs = (t_diff*)malloc(sizeof(t_diff));
}

int		main(int argc, char **argv)
{
	t_info	info;
	t_list	*trav;

	init_info(&info);
	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);	
	info.max = info.elem_a;
	print_stacks(&info);
	check_dup(info.a);
	info.median = median(&info);
	print_stacks(&info);
//	printf("median = %d\n", info.median);
	trav = info.a;
	while (trav)
	{
//		ft_printf("opt pos of %d : %d\t", *(int*)trav->data, trav->op_pos);
//		printf("cur pos = %d\n", get_curpos(info.a, trav));
//		ft_printf("%d moves to opt\n", calc_moves_to_op(trav->op_pos, get_curpos(info.a, trav), &info));
		trav = trav->next;
	}
	sort_stacks(&info);
//	ft_printf("sb\n");
	print_stacks(&info);
//	ft_printf("total fuckedupness = %d\nindividual total fuckedupness with different moves\n", calc_total_sortdiff(&info));
	test_sa(&info);
//	ft_printf("sa = %d\n", info.diffs->sa);
	test_sb(&info);
//	ft_printf("sb = %d\n", info.diffs->sb);
	test_ss(&info);
//	ft_printf("ss = %d\n", info.diffs->ss);
	test_ra(&info);
//	ft_printf("ra = %d\n", info.diffs->ra);
	test_rb(&info);
//	ft_printf("rb = %d\n", info.diffs->rb);
	test_rr(&info);
//	ft_printf("rr = %d\n", info.diffs->rr);
	test_rra(&info);
//	ft_printf("rra = %d\n", info.diffs->rra);
	test_rrb(&info);
//	ft_printf("rrb = %d\n", info.diffs->rrb);
	test_rrr(&info);
//	ft_printf("rrr = %d\n", info.diffs->rrr);
	test_pa(&info);
//	ft_printf("pa = %d\n", info.diffs->pa);
	test_pb(&info);
//	ft_printf("pb = %d\n", info.diffs->pb);
	print_steps(&info);
	return (0);
}
