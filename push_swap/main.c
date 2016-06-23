/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 08:41:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	init_info(t_info *info)
{
	  info->elem_a = 0;
	  info->elem_b = 0;
	  info->elem_steps = 0; 
}

int		main(int argc, char **argv)
{
	t_info	info;

	init_info(&info);
	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	info.max = info.elem_a;
	check_dup(info.a);
	print_stacks(&info);
//	sort_stack(&info.a, &info);
	dumb_sort(&info);
	print_steps(&info);
	return (0);
}
