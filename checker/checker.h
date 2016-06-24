/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/24 07:45:59 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

/*
 * diffs:
 * 0 = swap
 * 1 = rotate up
 * 2 = rotate down
 * 3 = push
 */

typedef struct	s_diff
{
	int			sa;
	int			sb;
	int			ss;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			pa;
	int			pb;
}				t_diff;

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
	int				old_diff;
	t_diff			*diffs;
}				t_info;

void			get_optimal(t_info *info, int *arr);

int				check_stack(t_info *info);

int				check_stack_desc(t_info *info);

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

int				calc_moves_to_op(int opt, int cur, t_info *info);

int				get_curpos(t_list *list, t_list *node);

int				calc_total_sortdiff(t_info *info);

#endif
