/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 08:00:23 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 08:35:35 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushpop(t_list **a, t_list **b)
{
	t_list	*link;
	void	*data;

	data = ft_lstpop(a);
	link = ft_lstnew(data);
	ft_lstpush(b, link);
}