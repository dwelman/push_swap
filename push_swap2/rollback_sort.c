/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:28:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/27 15:28:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int		count_valid(t_diff *diffs)
{
	int valid;

	valid = 11;
	valid -= (2147483647 == diffs->sa);
	valid -= (2147483647 == diffs->sb);
	valid -= (2147483647 == diffs->ss);
	valid -= (2147483647 == diffs->ra);
	valid -= (2147483647 == diffs->rb);
	valid -= (2147483647 == diffs->rr);
	valid -= (2147483647 == diffs->rra);
	valid -= (2147483647 == diffs->rrb);
	valid -= (2147483647 == diffs->rrr); 
	valid -= (2147483647 == diffs->pa); 
	valid -= (2147483647 == diffs->pb);
/*	ft_printf("sa = %d\n", diffs->sa);
    ft_printf("sb = %d\n", diffs->sb);
    ft_printf("ss = %d\n", diffs->ss);
    ft_printf("ra = %d\n", diffs->ra);
    ft_printf("rb = %d\n", diffs->rb);
    ft_printf("rr = %d\n", diffs->rr);
    ft_printf("rra = %d\n", diffs->rra);
    ft_printf("rrb = %d\n", diffs->rrb);
    ft_printf("rrr = %d\n", diffs->rrr);
    ft_printf("pa = %d\n", diffs->pa);
    ft_printf("pb = %d\n", diffs->pb);
*/	return (valid);
}


int		pick_option(int	options[12][2], int option_c)
{
	int i;
	int	small;

	i = 0;
	small = 0;
	while (i < option_c)
	{
		if (options[i][0] < options[small][0])
			small = i;
		i++;
	}
	if (options[small][0] == 1)
		exit(0);
	return (options[small][1]);
}

t_diff	diff_copy(t_diff *src)
{
	t_diff	ret;

	ret.sa = src->sa;
	ret.sb = src->sb;
	ret.ss = src->ss;
	ret.ra = src->ra;
	ret.rb = src->rb;
	ret.rr = src->rr;
	ret.rra = src->rra;
	ret.rrb = src->rrb;
	ret.rrr = src->rrr;
	ret.pa = src->pa;
	ret.pb = src->pb;
	return (ret);
}

void	rollback_sort(t_info *info)
{
	int cur_move;
	int valid;
	int	option_c;
	int	options[12][2];
	int	moves_done;
	t_info	mask;

	ft_strcpy(info->diffs->last_a,"qq");
	ft_strcpy(info->diffs->last_b,"qq");
	info->choice_diff = calc_total_sortdiff(info);
	while (calc_total_sortdiff(info) != 0 && info->elem_steps < info->in_count)
	{
		valid = count_valid(info->diffs);
		do_tests(info);
		option_c = 0;
		info_mask(info, &mask);
		moves_done = 42;
		while (valid > 0 && moves_done > 1)
		{
			cur_move = get_best(&mask);
			options[option_c][0] = try_next(info, 2, cur_move, &moves_done);
			options[option_c][1] = cur_move;
			do_function(mask.diffs, cur_move, &set_to_max);
			valid = count_valid(mask.diffs);
			option_c++;
		}
		do_best(info, pick_option(options, option_c), 1);
	}
}
