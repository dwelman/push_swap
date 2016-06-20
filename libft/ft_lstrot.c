/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:36:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 16:41:24 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrot(t_list **first)
{
	t_list	*temp;
	t_list	*crawl;

	temp = ft_lstnew(ft_lstpop(first));
	crawl = *first;
	while (crawl->next != NULL)
		crawl = crawl->next;
	crawl->next = temp;
}
