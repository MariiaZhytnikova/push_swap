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

void	ft_smswap(t_stack *a, t_stack *b)
{
	int	swap_a;
	int	swap_b;

	swap_a = (a->size >= 2 && a->arr[0] > a->arr[1]);
	swap_b = (b->size >= 2 && b->arr[0] < b->arr[1]);
	if (swap_a && swap_b)
	{
		ft_sa_sb_ss(a, b, 3);  // ss
		printf("I use ft_smswap to sort\n"); // DELETE MEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee
	}
	else if (swap_a)
	{
		ft_sa_sb_ss(a, NULL, 1);  // sa
		printf("I use SA to sort\n"); // DELETE MEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee
	}
	else if (swap_b)
	{
		ft_sa_sb_ss(NULL, b, 2);  // sb
	}
}

void	sm_rotate(t_stack *target, t_stack *stack, int direction, int a) 
{
	if (direction > 0)
	{
		if (a == 0 && stack->size >= 2 && stack->arr[0] < stack->arr[1] && stack->arr[0] < stack->arr[stack->size - 1])
		{
			ft_ra_rb_rr(target, stack, 3); // Perform combined rotation (rr)
			printf("I use ft_smrotate to sort\n"); // DELETE MEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee
		}
		else
			ft_ra_rb_rr(target, NULL, 1); // rotate the TARGET stack anyway
	}
	if (direction < 0)
	{
		if (a == 0 && stack->size >= 2 && stack->arr[stack->size - 1] > stack->arr[1] && stack->arr[stack->size - 1] > stack->arr[0])
		{
			ft_rra_rrb_rrr(target, stack, 3); // Perform combined rotation (rr)
			printf("I use ft_smrotate to sort\n"); // DELETE MEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee
		}
		else
			ft_rra_rrb_rrr(target, NULL, 1); // rotate the TARGET stack anyway
	}
}

void    rotate_min_max(t_stack *target, t_stack *stack, int index, int a)
{
    if (index <= target->size / 2) // If the index is closer to the top (less than half the stack size)
	{
		while (index-- > 0) // Perform forward rotations (ra)
			sm_rotate(target, stack, 1, a);  // Perform ra: rotate the stack
	}
	else
	{
		index = target->size - index;  // Convert index to the reverse distance from bottom
		while (index-- > 0) // Perform reverse rotations (rra)
			sm_rotate(target, stack, -1, a);  // Perform rra: reverse rotate the stack
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
	rotate_min_max (target, stack, max_pos, a);
}
