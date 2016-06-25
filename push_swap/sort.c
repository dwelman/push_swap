/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/25 09:48:37 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int		smallest(t_list *list, int *pos)
{
	int	small;
	int	i;

	small = *(int*)list->data;
	i = 0;
	while (list)
	{
		if (*(int*)list->data < small)
		{
			small = *(int*)list->data;
			*pos = i;
		}
		list = list->next;
		i++;
	}
	return (small);
}

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

int		try_next(t_info *info, int moves)
{
	t_list	*move_buffer;
	int		i;
	int		*b_index;
	int		first_move;

	i = 0;
	while (i < moves && i < info->max)
	{	
		do_tests(info);
		b_index = (int*)malloc(sizeof(int));
		*b_index =  get_best(info);
		ft_lstpush(&move_buffer, ft_lstnew(b_index));
		if (i == 0)
			first_move = *b_index;
		do_best(info, *b_index, 0);
		i++;
	}
	if (info->choice_diff > calc_total_sortdiff(info) || info->elem_steps == moves)
	{
		info->choice_i = first_move;
		info->choice_diff = calc_total_sortdiff(info);
	}
	roll_back_moves(info, move_buffer);
	return (first_move);
}

void	sort_stacks(t_info *info)
{
	ft_strcpy(info->diffs->last_a,"qq");
	ft_strcpy(info->diffs->last_b,"qq");
	info->choice_diff = calc_total_sortdiff(info);
	while (calc_total_sortdiff(info) != 0)
	{
		do_tests(info);
		if (*(int *)info->a->data <= info->median)
			info->diffs->pa = -1000;
		if (*(int *)info->a->data <= info->median && *(int *)info->a->next->data <= info->median &&
				ft_strcmp(info->diffs->last_a, "sa") != 0 && *(int *)info->a->data > *(int *)info->a->next->data)
			info->diffs->sa = -2000;
		if (check_stack(info) == 1 && check_stack_desc(info) == 1)
		{
			while (info->elem_b != 0)
			{
				info->diffs->pb = -2000;
				do_best(info, get_best(info), 1);
			}
			break;
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
		info->choice_diff = calc_total_sortdiff(info);
		print_stacks(info);
		ft_printf("last a = %s\n", info->diffs->last_a);
		ft_printf("last b = %s\n", info->diffs->last_b);
	}
}
