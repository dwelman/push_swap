/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:10:24 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 08:23:07 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	test_pa(t_info *info)
{
	ft_lstpushpop(&info->a, &info->b);
	info->diffs->pa = calc_total_sortdiff(info);
	ft_lstpushpop(&info->b, &info->a);
}

void	test_pb(t_info *info)
{
	ft_lstpushpop(&info->b, &info->a);
	info->diffs->pb = calc_total_sortdiff(info);
	ft_lstpushpop(&info->a, &info->b);
}
