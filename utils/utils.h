/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 10:02:41 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/21 11:14:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "../checker/checker.h"
# include "../push_swap/push_swap.h"

void	error_check(int argc, char **argv);

int		check_int(char *arg);

void	error_print(void);

int		store_stack(t_list **list, int argc, char **argv);

void    check_dup(t_list *list);

#endif
