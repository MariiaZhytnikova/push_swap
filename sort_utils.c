/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:19:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 19:05:46 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	find_best_target(t_stack *stack, int val)
{
	int	i;
	int	ind;
	int	res;

	if (stack->size == 0)
		return (0);
	i = 0;
	ind = 0;
	res = INT_MAX;
	while (i < stack->size)
	{
		if (stack->arr[i] > val && stack->arr[i] < res)
		{
			res = stack->arr[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}

int	rotate_both(t_stack *stack_a, t_stack *stack_b, int *steps_a, int *steps_b)
{
	int	combined;

	combined = 0;
	if (steps_a[1] == steps_b[1] && steps_a[0] && steps_b[0])
	{
		if (steps_a[0] < steps_b[0])
			combined = steps_a[0];
		else
			combined = steps_b[0];
	}
	while (steps_a[0] > 0 && steps_b[0] > 0 && steps_a[1] == steps_b[1])
	{
		if (steps_a[1] == 1)
			ft_ra_rb_rr(stack_a, stack_b, 3);
		else
			ft_rra_rrb_rrr(stack_a, stack_b, 3);
		steps_a[0]--;
		steps_b[0]--;
	}
	return (combined);
}

void	rotate_target(t_stack *stack_a, t_stack *stack_b, int a, int b)
{
	int	steps_a[2];
	int	steps_b[2];
	int	combined;

	steps_a[0] = mini_cost(stack_a, a);
	steps_b[0] = mini_cost(stack_b, b);
	steps_a[1] = mini_direction(stack_a, a);
	steps_b[1] = mini_direction(stack_b, b);
	combined = rotate_both(stack_a, stack_b, steps_a, steps_b);
	while (steps_a[0] > 0)
	{
		if (steps_a[1] == 1)
			ft_ra_rb_rr(stack_a, NULL, 1);
		else
			ft_rra_rrb_rrr(stack_a, NULL, 1);
		steps_a[0]--;
	}
	while (steps_b[0] > 0)
	{
		if (steps_b[1] == 1)
			ft_ra_rb_rr(NULL, stack_b, 2);
		else
			ft_rra_rrb_rrr(NULL, stack_b, 2);
		steps_b[0]--;
	}
}

static int	get_targets(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	targets[2];
	int	current[2];
	int	cost_min;
	int	i;

	i = 0;
	targets[0] = 0;
	targets[1] = 0;
	cost_min = INT_MAX;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] >= min && stack_b->arr[i] <= max)
		{
			current[0] = find_best_target(stack_a, stack_b->arr[i]);
			current[1] = cost_calc(stack_a, stack_b, current[0], i);
			if (current[1] < cost_min)
			{
				cost_min = current[1];
				targets[1] = i;
				targets[0] = current[0];
			}
		}
		i++;
	}
	return (targets[1]);
}

void	push_sort(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	targets[2];
	int	ch_size;

	ch_size = max - min + 1;
	while (ch_size)
	{
		targets[1] = get_targets(stack_a, stack_b, min, max);
		targets[0] = find_best_target(stack_a, stack_b->arr[targets[1]]);
		rotate_target(stack_a, stack_b, targets[0], targets[1]);
		ft_pa_pb(stack_a, stack_b, 1);
		ch_size--;
	}
}
