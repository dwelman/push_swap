#include "push_swap.h"

void	pa(t_algo *algo)
{
	if (algo->stack_b != NULL)
	{
		ft_lstpushpop(&algo->stack_b, &algo->stack_a);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("pa")));
		algo->op_count++;
		algo->elem_a++;
		algo->elem_b--;
	}
	else
		ft_putstr_fd("Error : Nothing on stack b to pop.", 2);
}

void	pb(t_algo *algo)
{
	if (algo->stack_b != NULL)
	{
		ft_lstpushpop(&algo->stack_a, &algo->stack_b);
		ft_lstappend(&algo->operations, ft_lstnew(ft_strdup("pb")));
		algo->op_count++;
		algo->elem_a--;
		algo->elem_b++;
	}
	else
		ft_putstr_fd("Error : Nothing on stack a to pop.", 2);
}
