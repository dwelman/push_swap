/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/25 15:42:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	info_mask(t_info *src, t_info *mask)
{
	t_diff	*ret;

	*mask = *src;
	ret = (t_diff*)malloc(sizeof(t_diff));
	ret->sa = src->diffs->sa;
	ret->sb = src->diffs->sb;
	ret->ss = src->diffs->ss;
	ret->ra = src->diffs->ra;
	ret->rb = src->diffs->rb;
	ret->rr = src->diffs->rr;
	ret->rra = src->diffs->rra;
	ret->rrb = src->diffs->rrb;
	ret->rrr = src->diffs->rrr;
	ret->pa = src->diffs->pa;
	ret->pb = src->diffs->pb;
	mask->diffs = ret;
	mask->a = ft_lstcpy(src->a);
	mask->b = ft_lstcpy(src->b);
	//rememer to clean mem for all masks!
}

int		try_next(t_info *info, int moves, int first_move, int *moves_done)
{
	t_list	*move_buffer;
	int		i;
	int		*b_index;
	int		s_diff;
	t_info	temp;

	i = 0;
	info_mask(info, &temp);
	while (i < moves && i < info->max && calc_total_sortdiff(&temp) != 0)
	{
		do_tests(&temp);
		if ((b_index = (int*)malloc(sizeof(int))) == NULL)
			ft_printf("Error allocating memory, Aborting...\n");
		if (i == 0)
		{
			*b_index = first_move;
			move_buffer = ft_lstnew(b_index);
		}
		else
		{
			*b_index =  get_best(&temp);
			ft_lstpush(&move_buffer, ft_lstnew(b_index));
		}
		do_best(&temp, *b_index, 0);
		i++;
	}
	*moves_done = i;
	s_diff = calc_total_sortdiff(&temp);
	roll_back_moves(&temp, move_buffer);
	free(temp.diffs);
//	ft_lstdel(temp.a);
//	ft_lstdel(temp.b);
	return (s_diff);
}
