/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/28 15:54:31 by ddu-toit         ###   ########.fr       */
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

t_info	*sort_stacks(t_info *info)
{
	t_info	*mask = (t_info*)malloc(sizeof(t_info));

	info_mask(info, mask);
	ft_strcpy(mask->diffs->last_a, "qq");
	ft_strcpy(mask->diffs->last_b, "qq");
	mask->choice_diff = calc_total_sortdiff(mask);
	while (calc_total_sortdiff(mask) != 0)
	{
		if (mask->elem_a == mask->max && stack_sorted(mask->a) == 1)
			break ;
		do_tests(mask);
		if (*(int *)mask->a->data <= mask->median)
			mask->diffs->pa = -1000;
		if (*(int *)mask->a->data <= mask->median && *(int *)mask->a->next->data <= mask->median &&
				ft_strcmp(mask->diffs->last_a, "sa") != 0 && *(int *)mask->a->data > *(int *)mask->a->next->data)
			mask->diffs->sa = -2000;
		if (ft_strcmp(mask->diffs->last_a, "sa") != 0 && *(int *)mask->a->data > *(int *)mask->a->next->data)
			mask->diffs->sa = -2000;
		if (stack_sorted(mask->a) == 1 && stack_sorted_desc(mask->b) == 1)
		{
		//	while (info->elem_b != 0)
		//	{
			if (ft_strcmp(mask->diffs->last_a, "pa") != 0)
				mask->diffs->pb = -2000;
		//		do_best(info, get_best(info), 1);
		//	}
		//	break;
		}
		if (look_below_median(mask) == 1 && stack_sorted_desc(mask->b) == 1)
		{
			mask->diffs->ra -= 510;
			mask->diffs->rra -= 500;
		}
		if (stack_sorted_desc(mask->b) == 1)
		{
			mask->diffs->sb = 200000;
			mask->diffs->ss = 200000;
			mask->diffs->rb = 200000;
			mask->diffs->rrb = 200000;
			mask->diffs->rrr = 200000;
		}
		do_best(mask, get_best(mask), 1);
	//info->choice_diff = calc_total_sortdiff(info);
//	//	ft_printf("last a = %s\n", info->diffs->last_a);
//		ft_printf("last b = %s\n", info->diffs->last_b);
	}
	print_stacks(mask->a, mask->b, info);
	return (mask);
}
