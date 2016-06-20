/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:56:05 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 14:45:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **first)
{
	t_list	*crawl;
	void	*temp;

	temp = NULL;
	crawl = *first;
	if (crawl != NULL)
	{
		*first = crawl->next;
		temp = crawl->data;
		free(crawl);
	}
	return (temp);
}
