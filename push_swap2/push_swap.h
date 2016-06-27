#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../checker/checker.h"
# include <stdio.h> //Remove me

/*
** Stored values for an algorithm - copies of stacks, number of operations
** it took to sort.
*/

typedef struct	s_algo
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		elem_a;
	int		elem_b;
	t_list	*operations;
	int		op_count;
	int		max;
	int		valid;
	t_diff	*diffs;
}				t_algo;

enum
{
	DUMB,
	BUBBLE,
	MERGE,
	SELECT
};

void			rollback_sort(t_info *info);

void			split_sort(t_algo *algo, t_info *info);

int				smallest(t_list *list, int *pos);

int				stack_sorted(t_list *stack);

int				stack_sorted_desc(t_list *stack);

int				dumb_sort(t_algo *algo, t_info *info);

void			bubble_sort(t_algo *algo, t_info *info);

void			init_info(t_info *info);

t_algo			*new_algo(t_info *info);

void			sa(t_algo *algo);

void			sb(t_algo *algo);

void			ss(t_algo *algo);

void			ra(t_algo *algo);

void			rb(t_algo *algo);

void			rr(t_algo *algo);

void			rra(t_algo *algo);

void			rrb(t_algo *algo);

void			rrr(t_algo *algo);

void			pa(t_algo *algo);

void			pb(t_algo *algo);

#endif
