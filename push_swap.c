/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/09 19:04:41 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_three(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		ft_sa_sb_ss(stack, NULL, 1);
		ft_rra_rrb_rrr(stack, NULL, 1);
	}
	else if (stack->arr[0] < stack->arr[2] && !ft_ifsorted(stack))
	{
		ft_sa_sb_ss(stack, NULL, 1);
		if (stack->arr[0] > stack->arr[1] && !ft_ifsorted(stack))
			ft_ra_rb_rr(stack, NULL, 1);
	}
	else if (stack->arr[0] > stack->arr[2])
	{
		if (stack->arr[1] > stack->arr[2])
			ft_rra_rrb_rrr(stack, NULL, 1);
		else
		ft_ra_rb_rr(stack, NULL, 1);
	}
}

static void ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	
	if (stack_a->size == 4)
	{
		min = find_min_max_index(stack_a, 0);
	 	rotate_target(stack_a, NULL, min, 1);
	 	ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
	 	ft_pa_pb(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5)
	{
		while (stack_a->size != 3)
		{
			min = find_min_max_index(stack_a, 0);
			rotate_target(stack_a, NULL, min, 1);
			ft_pa_pb(stack_a, stack_b, 2);
		}
		ft_sort_three(stack_a);
		while (stack_b->size > 0)
			ft_pa_pb(stack_a, stack_b, 1);
	}
}

// The chunk size calculation function can be here
static int	calculate_chunk_size(int n)
{
	if (n < 10)
		return 3;  // For 6–9 elements, chunk size 3
	if (n < 30)
		return 5;  // For 10–19 elements, chunk size 5
	else if (n < 50)
		return 10;  // For 20–49 elements, chunk size 5
	else if (n < 100)
		return 15; // For 50–99 elements, chunk size 10
	else
		return 20; // For 100+ elements, chunk size 20
}

static void	ft_sort_it(t_stack *stack_a, t_stack *stack_b)
{
	int	num_ch;
	int	ch_size;
	int	ch_max;
	int	ch_min;
	int	temp_size;

	ch_size = calculate_chunk_size(stack_a->size);
	num_ch = stack_a->size / ch_size;
	if (stack_a->size > num_ch * ch_size)
		num_ch++;
	ch_min = 1;
	while (num_ch > 0)
	{
			temp_size = ch_size;
		if (num_ch == 1)
		{
			ch_max = stack_a->arr[find_min_max_index(stack_a, 1)];
			temp_size = ch_max - ch_min + 1;
		}
		else
			ch_max = ch_min + ch_size - 1;
		while (temp_size > 0) // Push CHUNK to B
		{
			rotate_target(stack_a, NULL, find_cheapest(stack_a, ch_min, ch_max), 1);
			ft_pa_pb(stack_a, stack_b, 2);
			temp_size--;
		}
		ch_min = ch_max + 1;
		num_ch--; // can be add to while condition to remove line if needed
	}
	// int j = 0;
	// while (j < stack_b->size)
	// {
	// 	printf("stack B: %d\n", stack_b->arr[j]);
	// 	j++;
	// }
	ch_size = calculate_chunk_size(stack_b->size);
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
		ch_min = ch_max + 1;
		num_ch--; // can be add to while condition to remove line if needed
	}
}

void	push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;
	stack_b = malloc(sizeof(t_stack));
	stack_b->arr = malloc(sizeof(int) * 1);
	stack_b->size = 0;
	if (!stack_b)
		return (ft_error(1));
	if (stack_a->size == 2 && !ft_ifsorted(stack_a))
		ft_sa_sb_ss(stack_a, NULL, 1);
	else if (stack_a->size == 3 && !ft_ifsorted(stack_a))
		ft_sort_three(stack_a);
	else if (stack_a->size <= 5 && !ft_ifsorted(stack_a))
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size > 5 && !ft_ifsorted(stack_a))
		ft_sort_it(stack_a, stack_b);
	free (stack_b->arr);
	free(stack_b);
}
