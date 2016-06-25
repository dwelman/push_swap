/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:09:19 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/25 15:49:34 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	sort_arr(int *arr, int elem)
{
	int	*ptr;
	int	swapped;
	int	i;
	int	temp;

	swapped = 1;
	i = 0;
	ptr = arr;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < elem)
		{
			if (ptr[i] > ptr[i + 1])
			{
				temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	median(t_info *info)
{
	int		*list;
	int		i;
	int		ret;
	t_list	*trav;

	list = (int*)malloc(sizeof(int) * info->max);
	if (list != NULL)
	{
		trav = info->a;
		i = 0;
		while (trav != NULL)
		{
			list[i] = *(int*)trav->data;
			trav = trav->next;
			i++;
		}	
		sort_arr(list, info->max);
		get_optimal(info, list);
		i = 0;
		ret = list[info->max / 2];
		free(list);
		return (ret);
	}
	return (-1);
}

int	get_curpos(t_list *list, t_list *node)
{
	int		i;
	t_list	*trav;

	i = 0;
	trav = list;
	while (trav != NULL)
	{

		if (trav == node)
			return (i);
		i++;
		trav = trav->next;
	}
	return (-1);
}

int	calc_moves_to_op(int opt, int cur, t_info *info)
{
	int		pos;
	int		up;
	int		down;

	pos = cur;
	down = 0;
	up = 0;
	while (pos != opt)
	{
		if (pos == info->max)
			pos = 0;
		else
		{
			pos++;
			up++;
		}
	}
	pos = cur;
	while (pos != opt)
	{
		if (pos == 0)
			pos = info->max;
		else
		{
			pos--;
			down++;
		}
	}
	if (up <= down)
		return (up);
	else
		return (down);
}

int	calc_total_sortdiff(t_info *info)
{
	int		s_diff;
	t_list	*trav;

	s_diff = 0;
	trav = info->a;
	while (trav)
	{
		s_diff += calc_moves_to_op(trav->op_pos, get_curpos(info->a, trav), info);
		trav = trav->next;
	}
	trav = info->b;
	while (trav)
	{
		s_diff += calc_moves_to_op(0, get_curpos(info->b, trav), info) + 1;
		s_diff += calc_moves_to_op(trav->op_pos, 0, info);
		trav = trav->next;
	}
	return (s_diff);
}
