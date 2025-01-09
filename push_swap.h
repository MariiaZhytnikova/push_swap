/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:07 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/09 19:04:12 by mzhitnik         ###   ########.fr       */
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

void	ft_error(int code);
int		ft_ifsorted(t_stack *stack);
int		*ft_arr_copy(int *src, int size);
t_stack *ft_parse_one(char *argv);
t_stack	*ft_parse_ml(char **argv);
void	ft_mapping(t_stack *stack);
void	ft_ra_rb_rr(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_rra_rrb_rrr(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_sa_sb_ss(t_stack *stack_a, t_stack *stack_b, int act);
void	ft_pa_pb(t_stack *stack_a, t_stack *stack_b, int act);
void	rotate_target(t_stack *stack_a, t_stack *stack_b, int index, int dir);
int		find_min_max_index(t_stack *stack, int flag);
int		find_cheapest(t_stack *stack_a, int min, int max);
void	push_sort(t_stack *stack_a, t_stack *stack_b, int min, int max);
void	push_swap(t_stack *stack_a);

#endif
