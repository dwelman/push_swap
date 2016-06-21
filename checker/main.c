/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 08:37:59 by ddu-toit         ###   ########.fr       */
/*   Updated: 2016/06/20 16:00:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list(t_list *list)
{
	int	*num;
	while (list != NULL)
	{
		num = list->data;
		ft_printf("%d\n", *num);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	error_check(argc, argv);
	info.elem_a = store_stack(&info.a, argc, argv);
	print_list(info.a);
}
