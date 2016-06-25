/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/25 09:48:14 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int		do_tests_check(t_info *info)
{
	int valid;

	valid = 11;
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
	valid -= (2147483647 == info->diffs->sa);

	valid -= (2147483647 == info->diffs->sb);
	valid -= (2147483647 == info->diffs->ss);
	valid -= (2147483647 == info->diffs->ra);
	valid -= (2147483647 == info->diffs->rb);
	valid -= (2147483647 == info->diffs->rr);
	valid -= (2147483647 == info->diffs->rra);
	valid -= (2147483647 == info->diffs->rrb);
	valid -= (2147483647 == info->diffs->rrr);
	valid -= (2147483647 == info->diffs->pa);
	valid -= (2147483647 == info->diffs->pb);
	ft_printf("sa = %d\n", info->diffs->sa);
    ft_printf("sb = %d\n", info->diffs->sb);
    ft_printf("ss = %d\n", info->diffs->ss);
    ft_printf("ra = %d\n", info->diffs->ra);
    ft_printf("rb = %d\n", info->diffs->rb);
    ft_printf("rr = %d\n", info->diffs->rr);
    ft_printf("rra = %d\n", info->diffs->rra);
    ft_printf("rrb = %d\n", info->diffs->rrb);
    ft_printf("rrr = %d\n", info->diffs->rrr);
    ft_printf("pa = %d\n", info->diffs->pa);
    ft_printf("pb = %d\n", info->diffs->pb);
}

int		try_next(t_info *info, int moves, int *first_move)
{
	t_list	*move_buffer;
	int		i;
	int		*b_index;
	int		s_diff;

	i = 0;
	while (i < moves && i < info->max)
	{
		do_tests(info);
		b_index = (int*)malloc(sizeof(int));
		*b_index =  get_best(info);
		ft_lstpush(&move_buffer, ft_lstnew(b_index));
		if (i == 0)
			*first_move = *b_index;
		do_best(info, *b_index, 0);
		i++;
	}
	s_diff = calc_total_sortdiff(info);
	roll_back_moves(info, move_buffer);
	return (s_diff);
}

void	rollback_sort(t_info *info)
{
	int cur_move;

	ft_strcpy(info->diffs->last_a,"qq");
	ft_strcpy(info->diffs->last_b,"qq");
	info->choice_diff = calc_total_sortdiff(info);
	while (calc_total_sortdiff(info) != 0)
	{
	//	ft_printf("last move a : %s\n", info->diffs->last_a);
	//	ft_printf("last move b : %s\n", info->diffs->last_b);
		do_tests(info);
		cur_move = get_best(info, 0);
//		do_best(info, get_best(info), 1);
		print_stacks(info);
	}
}
