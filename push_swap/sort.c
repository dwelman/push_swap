/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 13:39:48 by ddu-toit         ###   ########.fr       */
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

void	sort_stacks(t_info *info)
{
	ft_strcpy(info->diffs->last_a,"qq");
	ft_strcpy(info->diffs->last_b,"qq");
	ft_printf("sortdif = %d\n", calc_total_sortdiff(info));
	while (calc_total_sortdiff(info) != 0)
	{
		ft_printf("last move a : %s\n", info->diffs->last_a);
		ft_printf("last move b : %s\n", info->diffs->last_b);
		do_tests(info);
		get_best(info);
		print_stacks(info);
	}
}

void	dumb_sort(t_info *info)
{
	int	pos;

	while (info->a && info->elem_a)
	{
		if (check_stack(info) == 0)
		{
			/*if (*(int*)info->a->data < *(int*)info->a->next->data && *(int*)info->a->next->data <= info->median)
			{
				ft_lstswap(info->a);
				ft_lstappend(&info->steps, ft_lstnew("sa"));
			}*/
			if (*(int*)info->a->data <= info->median)
			{
				ft_lstpushpop(&info->a, &info->b);
				ft_lstappend(&info->steps, ft_lstnew("pa"));
				inc_elems(info, 0);
			}
			else if (*(int*)info->a->data > *(int*)info->a->next->data)
			{
				ft_lstswap(info->a);
				ft_lstappend(&info->steps, ft_lstnew("sa"));
			}
			else if (*(int*)info->a->next->data == smallest(info->a, &pos))
			{
				ft_lstswap(info->a);
				ft_lstappend(&info->steps, ft_lstnew("sa"));
			}
			if (check_stack(info) == 0)
			{
				while (*(int*)info->a->data != smallest(info->a, &pos))
				{
					if (info->max / 2 - pos  >= 0)
					{
						ft_lstrot(&info->a, info->max);
						ft_lstappend(&info->steps, ft_lstnew("ra"));
					}		
					else
					{
						ft_lstrotrev(&info->a, info->max);
						ft_lstappend(&info->steps, ft_lstnew("rra"));
					}
					print_stacks(info);
				}
			}
			if (check_stack(info) == 0)
			{
				ft_lstpushpop(&info->a, &info->b);
				ft_lstappend(&info->steps, ft_lstnew("pa"));
				inc_elems(info, 0);
				print_stacks(info);
			}
		}
		else
			break;
	}
	while (info->b && info->elem_b)
	{
		ft_lstpushpop(&info->b, &info->a);
		ft_lstappend(&info->steps, ft_lstnew("pb"));
		inc_elems(info, 1);
	}
	print_stacks(info);
}
