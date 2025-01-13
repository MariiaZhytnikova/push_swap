/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:20:01 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/13 14:09:34 by mzhitnik         ###   ########.fr       */
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
	return (num_ch);
}

static void	chunk_push(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size > 0)
	{
		rotate_target(a, NULL, find_cheapest(a, min, max), 0);
		ft_pa_pb(a, b, 2);
		size--;
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num_ch;
	int	ch_size;
	int	min;
	int	max;

	ch_size = chunk_size(stack_a->size);
	num_ch = chunk_num(stack_a->size, ch_size);
	min = 1;
	while (num_ch > 0)
	{
		if (num_ch == 1)
		{
			max = stack_a->arr[find_min_max_index(stack_a, 1)];
			ch_size = max - min + 1;
		}
		else
			max = min + ch_size - 1;
		chunk_push(stack_a, stack_b, min, max);
		min = max + 1;
		num_ch--;
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	num_ch;
	int	ch_size;
	int	ch_max;
	int	ch_min;

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
