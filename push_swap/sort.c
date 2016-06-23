/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/23 07:36:12 by ddu-toit         ###   ########.fr       */
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
		}
		ft_lstpushpop(&info->a, &info->b);
		ft_lstappend(&info->steps, ft_lstnew("pa"));
		inc_elems(info, 0);
	}
	while (info->b && info->elem_b)
	{
		ft_lstpushpop(&info->b, &info->a);
		ft_lstappend(&info->steps, ft_lstnew("pb"));
		inc_elems(info, 1);
	}
}

