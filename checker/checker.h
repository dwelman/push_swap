/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/22 15:05:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct	s_info
{
	t_list			*a;
	t_list			*b;
	int				elem_a;
	int				elem_b;
	int				max;
	unsigned int	in_count;
	t_list			*steps;
	int				elem_steps;
}				t_info;

int				validate(t_info *info);

int				get_next_instruction(t_info *info);

void			inc_elems(t_info *info, int order);

void			error_check(int argc, char **argv);

int				check_int(char *arg);

void			error_print(void);

int				store_stack(t_list **list, int argc, char **argv);

void			check_dup(t_list *list);

void			print_stacks(t_info *info);

#endif
