/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 18:28:22 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max_index(t_stack *stack, int flag)
{
	int	index;
	int	i;

	index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (flag == 0 && stack->arr[i] < stack->arr[index])
			index = i;
		if (flag == 1 && stack->arr[i] > stack->arr[index])
			index = i;
		i++;
	}
	return (index);
}

static void	ft_sort_three(t_stack *stack)
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

static void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
	{
		rotate_target(stack_a, NULL, find_min_max_index(stack_a, 0), 0);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
		ft_pa_pb(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5)
	{
		while (stack_a->size != 3)
		{
			rotate_target(stack_a, NULL, find_min_max_index(stack_a, 0), 0);
			ft_pa_pb(stack_a, stack_b, 2);
		}
		ft_sort_three(stack_a);
		while (stack_b->size > 0)
			ft_pa_pb(stack_a, stack_b, 1);
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
	if (stack_a->size == 2)
		ft_sa_sb_ss(stack_a, NULL, 1);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size > 5)
	{
		push_a(stack_a, stack_b);
		push_b(stack_a, stack_b);
	}
	free (stack_b->arr);
	free(stack_b);
}
