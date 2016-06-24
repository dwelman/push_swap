/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:55:08 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 10:36:37 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_rb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last, "rrb") != 0)
	{
		ft_lstrot(&info->b, info->max);
		info->diffs->rb = calc_total_sortdiff(info);
		ft_lstrotrev(&info->b, info->max);
		ft_strcpy(info->diffs->last, "rb");
	}
	else
		info->diffs->rb = 2147483647;
}

void	test_rrb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last, "rb") != 0)
	{
		ft_lstrotrev(&info->b, info->max);
		info->diffs->rrb = calc_total_sortdiff(info);
		ft_lstrot(&info->b, info->max);
		ft_strcpy(info->diffs->last, "rrb");
	}
	else
		info->diffs->rrb = 2147483647;
}

void	test_rrr(t_info *info)
{
	if (info->a && info->b && ft_strcmp(info->diffs->last, "rrr") != 0)
	{
		ft_lstrotrev(&info->b, info->max);
		ft_lstrotrev(&info->a, info->max);
		info->diffs->rrr = calc_total_sortdiff(info);
		ft_lstrot(&info->b, info->max);
		ft_lstrot(&info->a, info->max);
		ft_strcpy(info->diffs->last, "rrr");
	}
	else
		info->diffs->rrr = 2147483647;
}

void	test_rr(t_info *info)
{
	if (info->a && info->b && ft_strcmp(info->diffs->last, "rr") != 0)
	{
		ft_lstrot(&info->b, info->max);
		ft_lstrot(&info->a, info->max);
		info->diffs->rr = calc_total_sortdiff(info);
		ft_lstrotrev(&info->b, info->max);
		ft_lstrotrev(&info->a, info->max);
		ft_strcpy(info->diffs->last, "rr");
	}
	else
		info->diffs->rr = 2147483647;
}
