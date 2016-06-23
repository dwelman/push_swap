/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/23 09:57:34 by ddu-toit         ###   ########.fr       */
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
	int				median;
}				t_info;

int				check_stack(t_info *info);

void			ft_lstappend(t_list **list, t_list *node);

int				validate(t_info *info);

int				get_next_instruction(t_info *info);

void			inc_elems(t_info *info, int order);

void			error_check(int argc, char **argv);

int				check_int(char *arg);

void			error_print(void);

int				store_stack(t_list **list, int argc, char **argv);

void			check_dup(t_list *list);

void			print_stacks(t_info *info);

void			print_steps(t_info *info);

void			dumb_sort(t_info *info);

void			sort_stack(t_list **start, t_info *info);

int				median(t_info *info);

#endif
