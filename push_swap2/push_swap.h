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
}				t_algo;

typedef struct	s_ps
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		elem_a;
	int		elem_b;
	int		median;
	int		max_val;
	int		min_val;
	int		max_steps;	
}				t_ps;

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
