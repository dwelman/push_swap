/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:09:19 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/23 09:36:01 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	sort_arr(int *arr, int elem)
{
	int	*ptr;
	int	swapped;
	int	i;
	int	temp;

	swapped = 1;
	i = 0;
	ptr = arr;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < elem)
		{
			if (ptr[i] > ptr[i + 1])
			{
				temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	median(t_info *info)
{
	int		*list;
	int		i;
	int		ret;
	t_list	*trav;

	list = (int*)malloc(sizeof(int) * info->max);
	if (list != NULL)
	{
		trav = info->a;
		i = 0;
		while (trav != NULL)
		{
			list[i] = *(int*)trav->data;
			trav = trav->next;
			i++;
		}	
		sort_arr(list, info->max);
		i = 0;
		ret = list[info->max / 2];
		free(list);
		return (ret);
	}
	return (-1);
}
