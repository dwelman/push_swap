/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 07:43:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 08:38:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*link;
	t_list	*top;
	t_list	*crawl;
	t_list	*b;
	i = 0;

	top = ft_lstnew((void *)1);
	b = ft_lstnew((void *)2);
	while (i < 5)
	{
		link = ft_lstnew((void *)(i * 5));
		ft_lstpush(&top, link);
		i++;
	}
	ft_lstpushpop(&top, &b);
	crawl = b;
	while (crawl != NULL)
	{
		ft_printf("%d\n", crawl->data);
		crawl = crawl->next;
	}
	crawl = top;
	while (crawl != NULL)
	{
		ft_printf("%d\n", crawl->data);
		crawl = crawl->next;
	}
	
	return (0);
}
