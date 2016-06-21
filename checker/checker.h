/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/21 09:24:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../utils/utils.h"

typedef struct	s_info
{
	t_list			*a;
	t_list			*b;
	int				elem_a;
	int				elem_b;
	unsigned int	in_count;
}				t_info;

int				get_next_instruction(t_list **a, t_list **b);

#endif
