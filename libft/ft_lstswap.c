/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:37:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 14:07:10 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *first)
{
	void	*temp;

	if (first->next != NULL)
	{
		temp = first->data;
		first->data = first->next->data;
		first->next->data = temp;
	}
}
