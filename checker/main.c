/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:41:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 16:46:59 by daviwel          ###   ########.fr       */
/*   Updated: 2016/06/20 16:00:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*first;
	t_list	*link;
	t_list	*temp;

	first = ft_lstnew((void *)42);
	link = ft_lstnew((void *)5);
	temp = ft_lstnew((void *)36);
	first->next = link;
	ft_lstpush(&first, temp);
	print_list(first);
	ft_printf("\n");
	ft_lstrotrev(&first);
	ft_lstrotrev(&first);
	print_list(first);
}

int	main(int argc, char **argv)
{
	char	*ins;

	error_check(argc, argv);
	while (get_next_instruction() != -1)
	{
	}
	return (0);
}
