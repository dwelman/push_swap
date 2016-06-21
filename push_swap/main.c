/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 09:57:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	error_check(argc, argv);
	store_stack(&info.a, argc, argv);
	check_dup(info.a);
	t_list *trav = info.a;
	while (trav)
	{
		ft_printf("%d\n", *(int*)trav->data);
		trav = trav->next;
	}
	return (0);
}
