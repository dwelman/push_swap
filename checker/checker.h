/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 09:31:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/20 14:37:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../utils/utils.h"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_info
{
	t_list			*a;
	t_list			*b;
	int				elem_a;
	int				elem_b;
	unsigned int	in_count;
}				t_info;

#endif
