/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/21 13:50:34 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int		smallest(t_list *list)
{
	int	small;

	small = *(int*)list->data;
	while (list)
	{
		if (*(int*)list->data < small)
			small = *(int*)list->data;
		list = list->next;
	}
	return (small);
}

void	dumb_sort(t_info *info)
{
	while (info->a && info->elem_a)
	{
		while (*(int*)info->a->data != smallest(info->a))
		{
			ft_lstrot(&info->a, info->max);
			ft_lstpush(&info->steps, ft_lstnew("ra"));	
		}
		ft_lstpushpop(&info->a, &info->b);
		ft_lstpush(&info->steps, ft_lstnew("pa"));
		inc_elems(info, 0);
	}
	while (info->b && info->elem_b)
	{
		ft_lstpushpop(&info->b, &info->a);
		ft_lstpush(&info->steps, ft_lstnew("pb"));
		inc_elems(info, 1);
	}
}

