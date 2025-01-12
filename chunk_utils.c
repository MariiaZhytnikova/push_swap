/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:20:01 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 19:41:48 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	if (n < 10)
		return (3);
	if (n < 30)
		return (5);
	else if (n < 50)
		return (10);
	else if (n < 100)
		return (15);
	else
		return (20);
}

static int	chunk_num(int stack_size, int ch_size)
{
	int	num_ch;
	
	num_ch = stack_size / ch_size;
	if (stack_size > num_ch * ch_size)
		num_ch++;
	return(num_ch);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num_ch;
	int	ch_size;
	int	min_max[2];
	int	temp_size;

	ch_size = chunk_size(stack_a->size);
	num_ch = chunk_num(stack_a->size, ch_size);
	min_max[0] = 1;
	while (num_ch > 0)
	{
		temp_size = ch_size;
		if (num_ch == 1)
		{
			min_max[1] = stack_a->arr[find_min_max_index(stack_a, 1)];
			temp_size = min_max[1] - min_max[0] + 1;
		}
		else
			min_max[1] = min_max[0] + ch_size - 1;
		while (temp_size > 0)
		{
			rotate_target(stack_a, NULL, find_cheapest(stack_a, min_max[0], min_max[1]), 0);
			ft_pa_pb(stack_a, stack_b, 2);
			temp_size--;
		}
		min_max[0] = min_max[1] + 1;
		num_ch--;
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	num_ch;
	int	ch_size;
	int	ch_max;
	int	ch_min;
	int	temp_size;

	ch_size = chunk_size(stack_b->size);
	num_ch = stack_b->size / ch_size;
	if (stack_b->size > num_ch * ch_size)
		num_ch++;
	ch_max = stack_b->size;
	while (num_ch > 0)
	{
		if (num_ch == 1)
		{
			ch_min = 1;
			ch_size = ch_max - ch_min + 1;
		}
		else
			ch_min = ch_max - ch_size + 1;
		push_sort(stack_a, stack_b, ch_min, ch_max);
		ch_max = ch_max - ch_size;
		num_ch--;
	}
	rotate_target(stack_a, NULL, find_min_max_index(stack_a, 0), 0);
}
