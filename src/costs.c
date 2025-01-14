/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:59:52 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 17:27:59 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mini_cost(t_stack *stack, int ind)
{
	if (!stack)
		return (0);
	if (ind <= stack->size / 2)
		return (ind);
	return (stack->size - ind);
}

int	mini_direction(t_stack *stack, int ind)
{
	if (!stack)
		return (0);
	if (ind <= stack->size / 2)
		return (1);
	return (-1);
}

int	cost_calc(t_stack *stack_a, t_stack *stack_b, int ind_a, int ind_b)
{
	int	cost_a[2];
	int	cost_b[2];
	int	combined;

	cost_a[0] = mini_cost(stack_a, ind_a);
	cost_b[0] = mini_cost(stack_b, ind_b);
	cost_a[1] = mini_direction(stack_a, ind_a);
	cost_b[1] = mini_direction(stack_b, ind_b);
	combined = 0;
	if (cost_a[1] == cost_b[1])
	{
		if (cost_a[0] < cost_b[0])
			combined = cost_a[0];
		else
			combined = cost_b[0];
	}
	return (cost_a[0] + cost_b[0] - combined);
}

int	find_cheapest(t_stack *stack, int min, int max)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < stack->size)
	{
		if (stack->arr[top] >= min && stack->arr[top] <= max)
			break ;
		top++;
	}
	bottom = stack->size - 1;
	while (bottom >= 0)
	{
		if (stack->arr[bottom] >= min && stack->arr[bottom] <= max)
			break ;
		bottom--;
	}
	if (top <= (stack->size - 1 - bottom))
		return (top);
	else
		return (bottom);
}
