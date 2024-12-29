/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:33:13 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/29 15:24:27 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *target, t_stack *stack, int direction, int a) 
{
	int	val_target;
	int	val_stack;
	 // CASE B rotate_min_max(stack_b, stack_a, index, 1); // a = 1
	 // CASE A rotate_min_max(stack_a, stack_b, index, 0); // a = 0
	val_target = (target->size >= 2);	
	if (a == 0 && direction > 0) // ANY WAY ROTATE A
	{
		val_stack = (stack->size >= 2 && stack->arr[0] < stack->arr[1] && stack->arr[0] < stack->arr[stack->size - 1]);
		if (val_stack && val_target)
			ft_ra_rb_rr(target, stack, 3); // Perform combined rotation (rr)
		else if (val_target)
			ft_ra_rb_rr(target, stack, 1); // rotate the TARGET stack anyway
	}
	if (a == 0 && direction < 0) // ANY WAY REVROTATE A
	{
		val_stack = (stack->size >= 2 && stack->arr[stack->size - 1] > stack->arr[0] && stack->arr[stack->size - 1] > stack->arr[stack->size - 2]);
		if (val_stack && val_target)
			ft_rra_rrb_rrr(target, stack, 3); // Perform combined rotation (rr)
		else if (val_target)
			ft_rra_rrb_rrr(target, stack, 1); // rotate the TARGET stack anyway
	}
	if (a == 1 && direction > 0)
		if (val_target)
			ft_ra_rb_rr(target, stack, 1); // rotate the TARGET stack anyway
	if (a == 1 && direction < 0)
		ft_rra_rrb_rrr(target, stack, 1); // rotate the TARGET stack anyway

}

void    rotate_min_max(t_stack *target, t_stack *stack, int index, int a)
{
    if (index <= target->size / 2) // If the index is closer to the top (less than half the stack size)
	{
		while (index-- > 0) // Perform forward rotations (ra)
			rotate(target, stack, 1, a);  // Perform ra: rotate the stack
	}
	else
	{
		index = target->size - index;  // Convert index to the reverse distance from bottom
		while (index-- > 0) // Perform reverse rotations (rra)
			rotate(target, stack, -1, a);  // Perform rra: reverse rotate the stack
	}
}

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
	return index;
}

void	find_cheapest(t_stack *target, t_stack *stack, int a)
{
	int	min_cost;
	int	max_cost;
	int	min_pos;
	int	max_pos;
    int	size;

    // Calculate the cost for moving the min and max elements to the top
    size = target->size;
	min_pos = find_min_max_index(target, 0);
	if (min_pos <= size / 2) // If the element is closer to the top, rotate forward (ra)
		min_cost = min_pos;
	else
		min_cost = size - min_pos; // If the element is closer to the bottom, reverse rotate (rra)
	max_pos = find_min_max_index(target, 1);
	if (max_pos <= size / 2) // If the element is closer to the top, rotate forward (ra)
		max_cost = max_pos;
	else
		max_cost = size - max_pos; // If the element is closer to the bottom, reverse rotate (rra)
	if (min_cost <= max_cost)
		rotate_min_max (target, stack, min_pos, a);
	else
		rotate_min_max (target, stack, max_pos, a);
}
