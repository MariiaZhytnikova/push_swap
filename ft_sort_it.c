/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:09:07 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/28 23:06:30 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void ft_smrotate(t_stack *stack) 
 {
 		if (stack->size <= 0) 
    return; // Or handle gracefully
		int val = ((stack->size >= 2 && (stack->arr[0] < stack->arr[1]) || 
              stack->arr[0] < stack->arr[stack->size - 1])); // Condition for stack b

    if (val)
		{
        ft_ra_rb_rr(NULL, stack, 2); // Perform combined rotation
    }
}

void ft_smswap(t_stack *a, t_stack *b) {
    // Implement swap logic
    int swap_a;
    int swap_b;

    swap_a = (a->size >= 2 && a->arr[0] > a->arr[1]);
    swap_b = (b->size >= 2 && b->arr[0] < b->arr[1]);

    if (swap_a && swap_b)
        ft_sa_sb_ss(a, b, 3);  // ss
    else if (swap_a)
        ft_sa_sb_ss(a, NULL, 1);  // sa
    else if (swap_b)
        ft_sa_sb_ss(NULL, b, 2);  // sb
}

int find_min_index(t_stack *stack) {
    int min_index = 0;
    for (int i = 1; i < stack->size; i++) {
        if (stack->arr[i] < stack->arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

// Find the index of the maximum value in stack
int find_max_index(t_stack *stack) {
    int max_index = 0;
    for (int i = 1; i < stack->size; i++) {
        if (stack->arr[i] > stack->arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// Calculate the minimal moves needed to position element at correct index
int calculate_cost(t_stack *stack, int index) {
    int size = stack->size;
    int cost;

    // Calculate the number of moves required to bring the element at 'index' to the top
    if (index <= size / 2) {
        // If the element is closer to the top, rotate forward (ra)
        cost = index;
    } else {
        // If the element is closer to the bottom, reverse rotate (rra)
        cost = size - index;
    }

    return cost;
}

int find_cheapest(t_stack *stack)
{
    int min_index, max_index;
    int min_cost, max_cost;

    // Find the index of the minimum and maximum elements
    min_index = find_min_index(stack);
    max_index = find_max_index(stack);

    // Calculate the cost for moving the min and max elements to the top
    min_cost = calculate_cost(stack, min_index); // Replace with the actual cost function for min
    max_cost = calculate_cost(stack, max_index); // Replace with the actual cost function for max

    // Return the index of the element with the lowest cost
		if (min_cost <= max_cost)
			return (min_cost);
		return (max_cost);
}

void	ft_sort_it(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	index;
	
	// Push two elements in stack B
	ft_pa_pb(stack_a, stack_b, 2);
	ft_pa_pb(stack_a, stack_b, 2);
	
	while (stack_a->size > 0)
	{
		index = find_cheapest(stack_a);
    int size = stack_a->size;
    // If the index is closer to the top (less than half the stack size)
		if (index <= size / 2)
		{
      // Perform forward rotations (ra)
      while (index-- > 0)
			{ // smart rotation? 
        //ft_rotate(stack_a, stack_b);
				ft_ra_rb_rr(stack_a, NULL, 1);  // Perform ra: rotate the stack
      }
    } 
		else
		{
      // Perform reverse rotations (rra)
      index = size - index;  // Convert index to the reverse distance
      while (index-- > 0)
			{
        ft_rra_rrb_rrr(stack_a, NULL, 1);  // Perform rra: reverse rotate the stack
			}
    }
		ft_pa_pb(stack_a, stack_b, 2);
		ft_smrotate(stack_b);	
	}
	while (stack_b->size > 0)
		{
		ft_smswap(stack_a, stack_b);
		index = find_max_index(stack_b);
    int size = stack_b->size;
    // If the index is closer to the top (less than half the stack size)
		if (index <= size / 2)
		{
      // Perform forward rotations (ra)
      while (index-- > 0)
			{ // smart rotation? 
        //ft_rotate(stack_a, stack_b);
				ft_ra_rb_rr(NULL, stack_b, 2);  // Perform ra: rotate the stack
      }
    } 
		else
		{
      // Perform reverse rotations (rra)
      index = size - index;  // Convert index to the reverse distance
      while (index-- > 0)
			{
        ft_rra_rrb_rrr(NULL, stack_b, 2);  // Perform rra: reverse rotate the stack
			}
    }
		ft_pa_pb(stack_a, stack_b, 1);
	}
	if (!ft_issorted(stack_a))
		ft_sort_it(stack_a, stack_b);
}
