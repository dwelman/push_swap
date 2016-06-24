/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:10:24 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 10:38:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_pa(t_info *info)
{
	if (info->a && ft_strcmp(info->diffs->last, "pb") != 0)
	{
		ft_lstpushpop(&info->a, &info->b);
		info->diffs->pa = calc_total_sortdiff(info);
		ft_lstpushpop(&info->b, &info->a);
		ft_strcpy(info->diffs->last, "pa");
	}
	else
		info->diffs->pa = 2147483647;
}

void	test_pb(t_info *info)
{
	if (info->b && ft_strcmp(info->diffs->last, "pa") != 0)
	{
		ft_lstpushpop(&info->b, &info->a);
		info->diffs->pb = calc_total_sortdiff(info);
		ft_lstpushpop(&info->a, &info->b);
		ft_strcpy(info->diffs->last, "pb");
	}
	else
		info->diffs->pb = 2147483647;
}
