/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:45:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/21 09:50:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../utils/utils.h"

typedef struct		s_info
{
	t_list	*a;
	t_list	*b;
	int		elem_a;
	int		elem_b;
}					t_info;

#endif
