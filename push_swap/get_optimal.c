/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_optimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:21:01 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 13:32:26 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	get_optimal(t_info *info, int *arr)
{
	int		i;
	t_info	*crawl;

	crawl = info->a;
	while (crawl != NULL)
	{
		i = 0;
		while (i < info->max)
		{
			if (*(int*)crawl->data == arr[i])
				crawl->op_pos = i;
			i++;
		}
		crawl = crawl->next;
	}
}
