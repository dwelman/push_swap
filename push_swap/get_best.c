/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:58:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/25 15:00:00 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int	cont_best(t_info *info, int small_i, int small)
{
	if (small > info->diffs->rrb)
	{
		small_i = 8;
		small = info->diffs->rrb;
	}
	if (small > info->diffs->rrr)
	{
		small_i = 9;
		small = info->diffs->rrr;
	}
	if (small > info->diffs->pa)
	{
		small_i = 10;
		small = info->diffs->pa;
	}
	if (small > info->diffs->pb)
	{
		small_i = 11;
		small = info->diffs->pb;
	}
	return (small_i);
}

int	get_best(t_info *info)
{
	int	small_i;
	int	small;

	small_i = 1;
	small = info->diffs->sa;
	if (small > info->diffs->sb)
	{
		small_i = 2;
		small = info->diffs->sb;
	}
	if (small > info->diffs->ss)
	{
		small_i = 3;
		small = info->diffs->ss;
	}
	if (small > info->diffs->ra)
	{
		small_i = 4;
		small = info->diffs->ra;
	}
	if (small > info->diffs->rb)
	{
		small_i = 5;
		small = info->diffs->rb;
	}
	if (small > info->diffs->rr)
	{
		small_i = 6;
		small = info->diffs->rr;
	}
	if (small > info->diffs->rra)
	{
		small_i = 7;
		small = info->diffs->rra;
	}
	return (cont_best(info, small_i, small));
}
