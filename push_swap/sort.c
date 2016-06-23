/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/23 08:42:40 by daviwel          ###   ########.fr       */
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

void	dumb_sort(t_info *info)
{
	int	pos;

	while (info->a && info->elem_a)
	{
		if (check_stack(info) == 0)
		{
			if (*(int*)info->a->data > *(int*)info->a->next->data)
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
