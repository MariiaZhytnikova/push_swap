/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:19:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/09 19:12:47 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

int	find_cheapest(t_stack *stack_a, int min, int max)
{
	int	top;
	int	bottom;
	
	top = 0;
	while (top < stack_a->size)
	{
		if (stack_a->arr[top] >= min && stack_a->arr[top] <= max)
			break ;
		top++;
	}
	bottom = stack_a->size - 1;
	while (bottom >= 0)
	{
		if (stack_a->arr[bottom] >= min && stack_a->arr[bottom] <= max)
			break ;
		bottom--;
	}
	if (top <= (stack_a->size - 1 - bottom))
		return (top);
	else
		return (bottom);
}

void	rotate_target(t_stack *stack_a, t_stack *stack_b, int index, int arr)
{
	if (index == 0)
		return ;
	if (arr == 1)
	{
		if (index <= stack_a->size / 2) // If the index is closer to the top (less than half the stack size)
			while (index-- > 0) // Perform forward rotations (ra)
				ft_ra_rb_rr(stack_a, NULL, arr);
		else
			index = stack_a->size - index;
		while (index-- > 0) // Perform reverse rotations (rra)
			ft_rra_rrb_rrr(stack_a, NULL, arr);
	}
	if (arr == 2)
	{
		if (index <= stack_b->size / 2) // If the index is closer to the top (less than half the stack size)
			while (index-- > 0) // Perform forward rotations (ra)
				ft_ra_rb_rr(NULL, stack_b, arr);
		else
			index = stack_b->size - index;
		while (index-- > 0) // Perform reverse rotations (rra)
			ft_rra_rrb_rrr(NULL, stack_b, arr);	
	}
}

static int	find_best_target(t_stack *stack, int val) // best position for element from b
{
	int	i;
	
	//printf("----> val %d\n", val);
	if (stack->size == 0)
        return (0);
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > val)
			return (i);
		i++;
	}
	return (stack->size);
}

static int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int ind_a, int ind_b) // index is target_a (place in a for element from B) 
{
	int	cost_a_top;
	int	cost_b_top;
	int	dir_a;
	int	dir_b;
	int	combined;
		
	if (ind_a == stack_a->size)
	{	
		cost_a_top = 1;
		dir_a = 1;
	}
	else
	{
		if (ind_a <= stack_a->size / 2) // should incllude the bring a back min to up
		{
			cost_a_top = ind_a * 2;
			dir_a = 1;
		}
		else if (ind_a == stack_a->size)
		{	
			cost_a_top = 1;
			dir_a = 1;
		}
		else
		{
			cost_a_top = (stack_a->size - ind_a) * 2;
			dir_a = -1;
		}
	}
	if (ind_b <= stack_b->size / 2) //ind = 1
	{
		cost_b_top = ind_b;
		dir_b = 1;
	}
	else
	{	
		cost_b_top = stack_b->size - ind_b;
		dir_b = -1;
	}
	combined = 0;
	if (dir_a == dir_b)
	{
		if (cost_a_top < cost_b_top)
			combined = cost_a_top;
		else
			combined = cost_b_top;
	}
	//printf("cost_a_top %d, cost_b_top %d, combined %d\n", cost_a_top, cost_b_top, combined);
	return (cost_a_top + cost_b_top - combined);
}

static void	rotate_both(t_stack *stack_a, t_stack *stack_b, int a, int b)  // A[0] became target_a = 2
{
	int	steps_a;
	int	steps_b;
	int	dir_a;
	int	dir_b;
	
	if (a <= stack_a->size / 2)  // a = 2 == stack_a->size -> RA cost 1
	{
		steps_a = a;
		dir_a = 1;
	}
	else
	{
		steps_a = stack_a->size - a;
		dir_a = -1;
	}
	
	if (b <= stack_b->size / 2)
	{
		steps_b = b;
		dir_b = 1;
	}
	else
	{
		steps_b = stack_b->size - b;
		dir_b = -1;
	}
	while (steps_a > 0 && steps_b > 0 && dir_a == dir_b)
	{
		if (dir_a == 1)
			ft_ra_rb_rr(stack_a, stack_b, 3);
		else
			ft_rra_rrb_rrr(stack_a, stack_b, 3);
		steps_a--;
		steps_b--;
	}
	rotate_target(stack_a, stack_b, steps_a, 1);
	rotate_target(stack_a, stack_b, steps_b, 2);
}

void	push_sort(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	target_a;
	int	target_b;
	int	cost_min;
	int	cost_cur;
	int target_cur;
	int	i;
	int	ch_size;
	
	ch_size = max - min + 1;
	while (ch_size > 0)
	{
		target_a = 0;
		target_b = 0; // = val = 25
		cost_min = INT_MAX;
		i = 0;
		while (i < stack_b->size) // chunk by chunk
		{
			if (stack_b->arr[i] >= min && stack_b->arr[i] <= max)
			{
				target_cur = find_best_target(stack_a, stack_b->arr[i]); // 0 position for B in A
				cost_cur = calculate_cost(stack_a, stack_b, target_cur, i);
				printf("-----> cost_cur %d, target_cur: %d, stack_b->arr[%d] %d\n", cost_cur, target_cur, i, stack_b->arr[i]);
				if (cost_cur < cost_min)
				{
					cost_min = cost_cur;
					target_b = i;
					target_a = target_cur; // position for B in A
				}
			}
			i++;
		}
		printf("cost_min: %d; target_a: %d, target_b: %d stack_b->arr[target_b]: %d\n", cost_min, target_a, target_b, stack_b->arr[target_b]); // A[0] became target_a
		if (target_a == stack_a->size && target_b == 0)
		{	
			ft_pa_pb(stack_a, stack_b, 1);
			rotate_both(stack_a, stack_b, target_a, target_b);
		}
		else
		{
			rotate_both(stack_a, stack_b, target_a, target_b);
			ft_pa_pb(stack_a, stack_b, 1);
		}
		rotate_target(stack_a, stack_b, find_min_max_index(stack_a, 0), 1);
		//rotate_both(stack_a, stack_b, target_a, target_b);
		int j = 0;
		while (j < stack_a->size)
		{
			printf("stack A: %d\n", stack_a->arr[j]);
			j++;
		}
		ch_size--;
	}
}
