/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:07 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/22 21:54:59 by mzhitnik         ###   ########.fr       */
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
void	ft_sort_big(t_stack *a, t_stack *b);
int		ft_find_closest_in_range(t_stack *stack, int min, int max);
void	ft_rotate_to_top(t_stack *stack, int num);
int		ft_find_position(t_stack *stack, int num);
int		ft_find_max(t_stack *stack);
int ft_find_first(t_stack *stack, int chunk, int chunk_size);
int ft_find_second_max(t_stack *stack);


#endif
