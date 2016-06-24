/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:10:24 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 14:15:46 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_pa(t_info *info)
{
	if (info->a && ft_strcmp(info->diffs->last_b, "pb") != 0)
	{
		ft_lstpushpop(&info->a, &info->b);
		info->diffs->pa = calc_total_sortdiff(info);
		ft_lstpushpop(&info->b, &info->a);
	}
	else
		info->diffs->pa = 2147483647;
}

void	test_pb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last_a, "pa") != 0)
	{
		ft_lstpushpop(&info->b, &info->a);
		info->diffs->pb = calc_total_sortdiff(info);
		ft_lstpushpop(&info->a, &info->b);
	}
	else
		info->diffs->pb = 2147483647;
}
