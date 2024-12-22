/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:07 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/22 14:02:33 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h> // TO DELETE

typedef struct	s_stack
{
	int	*arr;
	int	size;
}	t_stack;

int		ft_parse_one(char *argv, t_stack *stack);
int		ft_parse_ml(char **argv, t_stack *stack);
void	ft_mapping(t_stack *stack);
void	ft_ra_rb_rr(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_rra_rrb_rrr(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_sa_sb_ss(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_pa_pb(t_stack *stack_a, t_stack *stack_b, int act);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
int		ft_ifsorted(t_stack *stack);
void 	ft_min_first(t_stack *stack);
void	ft_sort_it(t_stack *stack_a, t_stack *stack_b);

#endif
