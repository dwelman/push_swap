/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:37:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 11:57:34 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_sa(t_info *info)
{
	if (info->a && ft_strcmp(info->diffs->last, "sa") != 0)
	{
		ft_lstswap(info->a);
		info->diffs->sa = calc_total_sortdiff(info);
		ft_lstswap(info->a);
		ft_strcpy(info->diffs->last, "sa");
	}
	else
		info->diffs->sa = 2147483647;
}

void	test_sb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last, "sb") != 0)
	{
		ft_lstswap(info->b);
		info->diffs->sb = calc_total_sortdiff(info);
		ft_lstswap(info->b);
		ft_strcpy(info->diffs->last, "sb");
	}
	else
		info->diffs->sb = 2147483647;
}

void	test_ss(t_info *info)
{
	if (info->a && info->b && ft_strcmp(info->diffs->last, "ss") != 0)
	{
		ft_lstswap(info->b);
		ft_lstswap(info->a);
		info->diffs->ss = calc_total_sortdiff(info);
		ft_lstswap(info->b);
		ft_lstswap(info->a);
		ft_strcpy(info->diffs->last, "ss");
	}
	else
		info->diffs->ss = 2147483647;
}

void	test_ra(t_info *info)
{
	if (info->a && info->b && ft_strcmp(info->diffs->last, "rra") != 0)
	{
		ft_lstrot(&info->a, info->max);
		info->diffs->ra = calc_total_sortdiff(info);
		ft_lstrotrev(&info->a, info->max);
		ft_strcpy(info->diffs->last, "ra");
	}
	else
		info->diffs->ra = 2147483647;
}

void	test_rra(t_info *info)
{
	if (info->a && ft_strcmp(info->diffs->last, "ra") != 0)
	{
		ft_lstrotrev(&info->a, info->max);
		info->diffs->rra = calc_total_sortdiff(info);
		ft_lstrot(&info->a, info->max);
		ft_strcpy(info->diffs->last, "rra");
	}
	else
		info->diffs->rra = 2147483647;
}
