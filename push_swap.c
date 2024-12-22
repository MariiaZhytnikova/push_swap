/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/22 14:02:23 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_ifsorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i - 1] > stack->arr[i])
			return (0);
		i++;
	}
	return (1);
}

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

void ft_min_first(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->arr[0];
	i = 0;
	while (i < stack->size)
	{
	if (stack->arr[i] < min)
		min = stack->arr[i];
		i++;
	}
	if (i < 3)
	{
		while (stack->arr[0] != min)
			ft_ra_rb_rr(stack, NULL, 1);
	}
	else
	{
		while (stack->arr[0] != min)
			ft_rra_rrb_rrr(stack, NULL, 1);
	}
}

static void ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
	{
		ft_min_first(stack_a);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
		ft_pa_pb(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5)
	{
		ft_min_first(stack_a);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_min_first(stack_a);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
		ft_pa_pb(stack_a, stack_b, 1);
		ft_pa_pb(stack_a, stack_b, 1);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2 && !ft_ifsorted(stack_a))
	{
		ft_sa_sb_ss(stack_a, NULL, 1);
	}
	else if (stack_a->size == 3 && !ft_ifsorted(stack_a))
		ft_sort_three(stack_a);
	else if (stack_a->size < 6 && !ft_ifsorted(stack_a))
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size > 5 && !ft_ifsorted(stack_a))
		ft_sort_it(stack_a, stack_b);
}
