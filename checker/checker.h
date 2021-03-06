/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/29 16:34:47 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

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
	char		last_a[4];
	char		last_b[4];
}				t_diff;

typedef struct	s_info
{
	t_list			*a;
	t_list			*b;
	int				elem_a;
	int				elem_b;
	int				max;
	int				in_count;
	int				selection;
	t_list			*steps;
	int				elem_steps;
	int				median;
	int				old_diff;
	int				choice_i;
	int				choice_diff;
	t_diff			*diffs;
}				t_info;

void			info_mask(t_info *src, t_info *mask);

t_list			*ft_lstcpy(t_list *start_src);

int				look_below_median(t_info *info);

void			roll_back_moves(t_info *info, t_list *move_buffer);

int				try_next(t_info *info, int moves, int first_move, int *moves_done);

void			do_tests(t_info *info);

void			do_best(t_info *info, int i, int save);

int				get_best(t_info *info);

void			get_optimal(t_info *info, int *arr);

int				check_stack(t_info *info);

int				check_stack_desc(t_info *info);

void			ft_lstappend(t_list **list, t_list *node);

void			ft_lstdel(t_list *start);

int				validate(t_info *info);

int				get_next_instruction(t_info *info);

void			inc_elems(t_info *info, int order);

void			error_check(int argc, char **argv);

int				check_args(int argc, char **argv);

int				check_int(char *arg);

void			error_print(void);

int				store_stack(t_list **list, int argc, char **argv, int u_arg);

void			check_dup(t_list *list);

void			print_stacks(t_list *a, t_list *b, t_info *info);

void			print_steps(t_list *steps);

int				median(t_info *info);

int				calc_moves_to_op(int opt, int cur, t_info *info);

int				get_curpos(t_list *list, t_list *node);

int				calc_total_sortdiff(t_info *info);

void			test_sa(t_info *info);

void			test_sb(t_info *info);

void			test_ss(t_info *info);

void			test_ra(t_info *info);

void			test_rb(t_info *info);

void			test_rr(t_info *info);

void			test_rra(t_info *info);

void			test_rrb(t_info *info);

void			test_rrr(t_info *info);

void			test_pa(t_info *info);

void			test_pb(t_info *info);

t_info			*sort_stacks(t_info *info);

void			do_function(t_diff *diff, int i, void (f)(int *));

void			set_to_max(int *num);

void			rollback_sort(t_info *info);

#endif
