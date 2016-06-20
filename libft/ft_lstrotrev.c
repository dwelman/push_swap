/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:00:10 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 16:41:50 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrotrev(t_list **first)
{
	t_list	*crawl;
	t_list	*cur;

	crawl = *first;
	crawl = crawl->next;
	cur = crawl;
	while (crawl->next != NULL)
		crawl = crawl->next;
	crawl->next = *first;
	*first = cur->next;
	cur->next = NULL;
}
