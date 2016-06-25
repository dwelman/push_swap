/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:47:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/25 10:10:47 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

int	check_stack_desc(t_info *info)
{
	int		i;
	t_list	*crawl;

	i = 0;
	crawl = info->b;
	while (crawl != NULL)
	{
		if (crawl->next != NULL)
		{
			if (*(int *)crawl->data <= *(int *)crawl->next->data)
				return (0);
		}
		crawl = crawl->next;
		i++;
	}
	return (1);
}

int	check_stack(t_info *info)
{
	int		i;
	t_list	*crawl;

	i = 0;
	crawl = info->a;
	while (crawl != NULL)
	{
		if (crawl->next != NULL)
		{
			if (*(int *)crawl->data >= *(int *)crawl->next->data)
				return (0);
		}
		crawl = crawl->next;
		i++;
	}
	return (1);
}

int	look_below_median(t_info *info)
{
	t_list	*crawl;

	crawl = info->a;
	while (crawl != NULL)
	{
		if (*(int *)crawl->data <= info->median)
			return (1);
		crawl = crawl->next;
	}
	return (0);
}
