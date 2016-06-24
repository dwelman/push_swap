/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:37:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 09:50:47 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_sa(t_info *info)
{
	if (info->a)
	{
		ft_lstswap(info->a);
		info->diffs->sa = calc_total_sortdiff(info);
		ft_lstswap(info->a);
	}
	else
		info->diffs->sa = 2147483647;
}

void	test_sb(t_info *info)
{
	if (info->b)
	{
		ft_lstswap(info->b);
		info->diffs->sb = calc_total_sortdiff(info);
		ft_lstswap(info->b);
	}
	else
		info->diffs->sb = 2147483647;
}

void	test_ss(t_info *info)
{
	if (info->a && info->b)
	{
		ft_lstswap(info->b);
		ft_lstswap(info->a);
		info->diffs->ss = calc_total_sortdiff(info);
		ft_lstswap(info->b);
		ft_lstswap(info->a);
	}
	else
		info->diffs->ss = 2147483647;
}

void	test_ra(t_info *info)
{
	if (info->a)
	{
		ft_lstrot(&info->a, info->max);
		info->diffs->ra = calc_total_sortdiff(info);
		ft_lstrotrev(&info->a, info->max);
	}
	else
		info->diffs->ra = 2147483647;
}

void	test_rra(t_info *info)
{
	if (info->a)
	{
		ft_lstrotrev(&info->a, info->max);
		info->diffs->rra = calc_total_sortdiff(info);
		ft_lstrot(&info->a, info->max);
	}
	else
		info->diffs->rra = 2147483647;
}
