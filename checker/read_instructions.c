/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:20:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/20 16:55:20 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parse_instruction(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		printf("instruction sa found\n");
	else if (ft_strcmp(line, "sb") == 0)
		printf("instruction sb found\n");
	else if (ft_strcmp(line, "ss") == 0)
		printf("instruction ss	found\n");	
	else if (ft_strcmp(line, "pa") == 0)
		printf("instruction pa found\n");
	else if (ft_strcmp(line, "pb") == 0)
		printf("instruction pb found\n");
	else if (ft_strcmp(line, "ra") == 0)
		printf("instruction ra found\n");
	else if (ft_strcmp(line, "rb") == 0)
		printf("instruction rb found\n");
	else if (ft_strcmp(line, "rr") == 0)
		printf("instruction rr found\n");
	else if (ft_strcmp(line, "rra") == 0)
		printf("instruction rra found\n");
	else if (ft_strcmp(line, "rrb") == 0)
		printf("instruction rrb found\n");
	else if (ft_strcmp(line, "rrr") == 0)
		printf("instruction rrr found\n");
	else
		return (-1);
	return (1);
}

int		get_next_instruction(void)
{
	char	*line;
	int		ret;

	get_next_line(1, &line);
	if (line != NULL)
	{
		ret = parse_instruction(line);
		free(line);
	}
	return (ret);
}
