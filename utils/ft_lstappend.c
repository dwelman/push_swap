/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:41:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/22 14:43:15 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstappend(t_list **list, t_list *new)
{
	t_list	*trav;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	trav = *list;
	while (trav->next != NULL)
		trav = trav->next;
	trav->next = new;
}
