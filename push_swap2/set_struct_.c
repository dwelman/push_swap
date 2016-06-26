#include "push_swap.h"

void    init_info(t_info *info)
{
    info->elem_a = 0;
    info->elem_b = 0;
    info->elem_steps = 0;
    info->b = NULL;
    info->a = NULL;
    info->median = median(info);
}

t_algo	*new_algo(t_info *info)
{
	t_algo *new;

	new = (t_algo*)malloc(sizeof(t_algo));
	new->stack_a = ft_lstcpy(info->a);
	new->stack_b = ft_lstcpy(info->b);
	new->elem_a = info->elem_a;
	new->elem_b = info->elem_b;
	algo>op_count = 0;
	new->operations = NULL;
}

void	delete_algo(t_algo **valgo)
{
	if (*algo->stack_a)
		ft_lstdel(*algo->stack_a);
	if (*algo->stack_b)
		ft_lstdel(*algo->stack_b);
	if (*algo->operations)
		ft_lstdel(*algo->operations);
	*algo->stack_a = NULL;
	*algo->stack_b = NULL;
	*algo->stack_operations = NULL;
	algo = NULL;
}
