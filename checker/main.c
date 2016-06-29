/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/29 17:16:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_info(t_info *info)
{
	info->elem_a = 0;
	info->elem_b = 0;
	info->elem_steps = 0;
	info->b = NULL;
	info->a = NULL;
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		n;

	init_info(&info);
	n = check_args(argc, argv);
	if (n)
		info.elem_a = store_stack(&info.a, n, ft_strsplit(argv[1], ' '), !(n));
	else
		info.elem_a = store_stack(&info.a, argc, argv, !(n));
	info.max = info.elem_a;
	print_stacks(info.a, info.b, &info);
	get_next_instruction(&info);
	validate(&info);
	return (0);
}
