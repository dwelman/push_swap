/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:41:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/25 14:00:07 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstdel(t_list *start)
{
	t_list	*trav;
	t_list	*prev;

	trav = start;
	while (trav)
	{
		if (trav->data)
		{
			free(trav->data);
			trav->data = NULL;
		}
		prev = trav;
		trav = trav->next;
		if (prev)
			free(prev);
		prev = NULL;
	}
}
