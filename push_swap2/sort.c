/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/27 14:03:57 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_tests(t_info *info)
{
	test_sa(info);
	test_sb(info);
	test_ss(info);
	test_ra(info);
	test_rb(info);
	test_rr(info);
	test_rra(info);
	test_rrb(info);
	test_rrr(info);
	test_pa(info);
	test_pb(info);
/*	ft_printf("\nsa = %d\n", info->diffs->sa);
    ft_printf("sb = %d\n", info->diffs->sb);
    ft_printf("ss = %d\n", info->diffs->ss);
    ft_printf("ra = %d\n", info->diffs->ra);
    ft_printf("rb = %d\n", info->diffs->rb);
    ft_printf("rr = %d\n", info->diffs->rr);
    ft_printf("rra = %d\n", info->diffs->rra);
    ft_printf("rrb = %d\n", info->diffs->rrb);
    ft_printf("rrr = %d\n", info->diffs->rrr);
    ft_printf("pb = %d\n", info->diffs->pa);
	ft_printf("pa = %d\n", info->diffs->pb);*/
}

void	sort_stacks(t_info *info)
{
	ft_strcpy(info->diffs->last_a,"qq");
	ft_strcpy(info->diffs->last_b,"qq");
	info->choice_diff = calc_total_sortdiff(info);
	while (calc_total_sortdiff(info) != 0)
	{
		if (info->elem_a == info->max && check_stack(info) == 1)
			break ;
		do_tests(info);
		if (*(int *)info->a->data <= info->median)
			info->diffs->pa = -1000;
		if (*(int *)info->a->data <= info->median && *(int *)info->a->next->data <= info->median &&
				ft_strcmp(info->diffs->last_a, "sa") != 0 && *(int *)info->a->data > *(int *)info->a->next->data)
			info->diffs->sa = -2000;
		if (ft_strcmp(info->diffs->last_a, "sa") != 0 && *(int *)info->a->data > *(int *)info->a->next->data)
			info->diffs->sa = -2000;
		if (check_stack(info) == 1 && check_stack_desc(info) == 1)
		{
		//	while (info->elem_b != 0)
		//	{
			if (ft_strcmp(info->diffs->last_a, "pa") != 0)
				info->diffs->pb = -2000;
		//		do_best(info, get_best(info), 1);
		//	}
		//	break;
		}
		if (look_below_median(info) == 1 && check_stack_desc(info) == 1)
		{
			info->diffs->ra -= 510;
			info->diffs->rra -= 500;
		}
		if (check_stack_desc(info) == 1)
		{
			info->diffs->sb = 200000;
			info->diffs->ss = 200000;
			info->diffs->rb = 200000;
			info->diffs->rrb = 200000;
			info->diffs->rrr = 200000;
		}
		do_best(info, get_best(info), 1);
	//info->choice_diff = calc_total_sortdiff(info);
		print_stacks(info);
		ft_printf("last a = %s\n", info->diffs->last_a);
		ft_printf("last b = %s\n", info->diffs->last_b);
	}
}
