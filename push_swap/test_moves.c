/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 07:37:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 08:21:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_sa(t_info *info)
{
	ft_lstswap(info->a);
	info->diffs->sa = calc_total_sortdiff(info);
	ft_lstswap(info->a);
}

void	test_sb(t_info *info)
{
	ft_lstswap(info->b);
	info->diffs->sb = calc_total_sortdiff(info);
	ft_lstswap(info->b);
}

void	test_ss(t_info *info)
{
	ft_lstswap(info->b);
	ft_lstswap(info->a);
	info->diffs->ss = calc_total_sortdiff(info);
	ft_lstswap(info->b);
	ft_lstswap(info->a);
}

void	test_ra(t_info *info)
{
	ft_lstrot(&info->a, info->max);
	info->diffs->ra = calc_total_sortdiff(info);
	ft_lstrotrev(&info->a, info->max);
}

void	test_rra(t_info *info)
{
	ft_lstrotrev(&info->a, info->max);
	info->diffs->rra = calc_total_sortdiff(info);
	ft_lstrot(&info->a, info->max);
}
