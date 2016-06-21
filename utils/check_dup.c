/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 08:56:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/21 09:11:38 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_dup(t_list *list)
{
	t_list	*trav;
	t_list	*cur;

	cur = list;
	while (cur)
	{
		trav = cur->next;
		while (trav)
		{
			if (*(int*)trav->data == *(int*)cur->data)
				error_print();
			trav = trav->next;
		}
		cur = cur->next;
	}
}
