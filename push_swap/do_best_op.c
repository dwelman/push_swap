/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:20:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/24 17:00:48 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	do_best_cont(t_info *info, int i, int save)
{
	if (i == 8)
	{
		ft_lstrotrev(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("rrb"));
		ft_strcpy(info->diffs->last_b, "rrb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else if (i == 9)
	{
		ft_lstrotrev(&info->a, info->elem_a);
		ft_lstrotrev(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("rrr"));
		ft_strcpy(info->diffs->last_a, "rrr");
		ft_strcpy(info->diffs->last_b, "rrr");
	}
	else if (i == 10)
	{
		ft_lstpushpop(&info->a, &info->b);
		inc_elems(info, 0);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("pa"));
		ft_strcpy(info->diffs->last_a, "pa");
	}
	else if (i == 11)
	{
		ft_lstpushpop(&info->b, &info->a);
		inc_elems(info, 1);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("pb"));
		ft_strcpy(info->diffs->last_b, "pb");
	}
}

void	do_best(t_info *info, int i, int save)
{
	info->elem_steps++;
	if (i == 1)
	{
		ft_lstswap(info->a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("sa"));
		ft_strcpy(info->diffs->last_a, "sa");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else if (i == 2)
	{
		ft_lstswap(info->b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("sb"));
		ft_strcpy(info->diffs->last_b, "sb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else if (i == 3)
	{
		ft_lstswap(info->a);
		ft_lstswap(info->b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("ss"));
		ft_strcpy(info->diffs->last_a, "ss");
		ft_strcpy(info->diffs->last_b, "ss");
	}
	else if (i == 4)
	{
		ft_lstrot(&info->a, info->elem_a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("ra"));
		ft_strcpy(info->diffs->last_a, "ra");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else if (i == 5)
	{
		ft_lstrot(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("rb"));
		ft_strcpy(info->diffs->last_b, "rb");
		if (ft_strcmp(info->diffs->last_a, "pa") == 0)
			ft_strcpy(info->diffs->last_a, "qq");
	}
	else if (i == 6)
	{
		ft_lstrot(&info->a, info->elem_a);
		ft_lstrot(&info->b, info->elem_b);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("rr"));
		ft_strcpy(info->diffs->last_a, "rr");		
		ft_strcpy(info->diffs->last_b, "rr");
	}
	else if (i == 7)
	{
		ft_lstrotrev(&info->a, info->elem_a);
		if (save)
			ft_lstappend(&info->steps, ft_lstnew("rra"));
		ft_strcpy(info->diffs->last_a, "rra");
		if (ft_strcmp(info->diffs->last_b, "pb") == 0)
			ft_strcpy(info->diffs->last_b, "qq");
	}
	else
		do_best_cont(info, i, save);
}

void	add_move_to_buff(t_list *buff, int i)
{
	if (i == 1)
		ft_lstpush(&buff, ft_lstnew("sa"));
	if (i == 2)
		ft_lstpush(&buff, ft_lstnew("sb"));
	else if (i == 3)
		ft_lstpush(&buff, ft_lstnew("ss"));
	else if (i == 4)
		ft_lstpush(&buff, ft_lstnew("ra"));
	else if (i == 5)
		ft_lstpush(&buff, ft_lstnew("rb"));
	else if (i == 6)
		ft_lstpush(&buff, ft_lstnew("rr"));
	else if (i == 7)
		ft_lstpush(&buff, ft_lstnew("rra"));
	else if (i == 8)
		ft_lstpush(&buff, ft_lstnew("rrb"));
	else if (i == 9)
		ft_lstpush(&buff, ft_lstnew("rrr"));
	else if (i == 10)
		ft_lstpush(&buff, ft_lstnew("pa"));
	else if (i == 11)
		ft_lstpush(&buff, ft_lstnew("pb"));
}
