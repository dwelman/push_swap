/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:52:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/21 12:17:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int		store_stack(t_list **list, int argc, char **argv)
{
	int	*num;
	int	elem;

	elem = 1;
	if (argc > 1)
	{
		num = (int*)malloc(sizeof(int));
		*num = check_int(argv[--argc]);
		*list = ft_lstnew(num);
		while (argc > 1)
		{
			num = (int*)malloc(sizeof(int));
			*num = check_int(argv[--argc]);
			ft_lstpush(list, ft_lstnew(num));
			elem++;
		}
	}
	return (elem);
}
