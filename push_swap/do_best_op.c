/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:20:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/24 11:57:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	do_best_cont(t_info *info, int i)
{
	if (i == 8)
	{
		ft_lstrotrev(&info->b, info->max);
		ft_lstappend(&info->steps, ft_lstnew("rrb"));
	}
	else if (i == 9)
	{
		ft_lstrotrev(&info->a, info->max);
		ft_lstrotrev(&info->b, info->max);
		ft_lstappend(&info->steps, ft_lstnew("rrr"));
	}
	else if (i == 10)
	{
		ft_lstpushpop(&info->a, &info->b);
		ft_lstappend(&info->steps, ft_lstnew("pa"));
		inc_elems(info, 0);
	}
	else if (i == 11)
	{
		ft_lstpushpop(&info->b, &info->a);
		ft_lstappend(&info->steps, ft_lstnew("pb"));
		inc_elems(info, 1);
	}
}

void	do_best(t_info *info, int i)
{
	ft_printf ("i = %d\n", i);
	if (i == 1)
	{
		ft_lstswap(info->a);
		ft_lstappend(&info->steps, ft_lstnew("sa"));
	}
	else if (i == 2)
	{
		ft_lstswap(info->b);
		ft_lstappend(&info->steps, ft_lstnew("sb"));
	}
	else if (i == 3)
	{
		ft_lstswap(info->a);
		ft_lstswap(info->b);
		ft_lstappend(&info->steps, ft_lstnew("ss"));
	}
	else if (i == 4)
	{
		ft_lstrot(&info->a, info->max);
		ft_lstappend(&info->steps, ft_lstnew("ra"));
	}
	else if (i == 5)
	{
		ft_lstrot(&info->b, info->max);
		ft_lstappend(&info->steps, ft_lstnew("rb"));
	}
	else if (i == 6)
	{
		ft_lstrot(&info->a, info->max);
		ft_lstrot(&info->b, info->max);
		ft_lstappend(&info->steps, ft_lstnew("rr"));
	}
	else if (i == 7)
	{
		ft_lstrotrev(&info->a, info->max);
		ft_lstappend(&info->steps, ft_lstnew("rra"));
	}
	else
		do_best_cont(info, i);
}
