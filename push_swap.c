/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/29 16:10:45 by mzhitnik         ###   ########.fr       */
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
	int	index;
	
	if (stack_a->size == 4)
	{
		index = find_min_max_index(stack_a, 0);
		rotate_min_max(stack_a, stack_b, index, 0);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
		ft_pa_pb(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5)
	{
		while (stack_a->size != 3)
		{
			index = find_min_max_index(stack_a, 0);
			rotate_min_max(stack_a, stack_b, index, 0);
			ft_pa_pb(stack_a, stack_b, 2);
		}
		ft_sort_three(stack_a);
		while (stack_b->size > 0)
			ft_pa_pb(stack_a, stack_b, 1);
	}
}

/*void	ft_sort_it(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	ft_pa_pb(stack_a, stack_b, 2); // Push two elements in stack B or push Just one, why push two? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
	ft_pa_pb(stack_a, stack_b, 2); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (stack_a->size > 0)
	{
		find_cheapest(stack_a, stack_b, 0);
		ft_pa_pb(stack_a, stack_b, 2);
	}
	while (stack_b->size > 0) // Push two elements from stack B back to A
	{
		ft_smswap(stack_a, stack_b);  // DELETEEEEEEEEEEEEE CHECKKKKKKKKKKKK	
		index = find_min_max_index(stack_b, 1);
		rotate_min_max(stack_b, stack_a, index, 1);
		ft_pa_pb(stack_a, stack_b, 1);
	}
} */

void	ft_sort_it(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	(void)index;
	int i = 0;
	while (i < stack_b->size)
	{
		printf("Stack B after sort: %d\n", stack_b->arr[i]);
		i++;
	}
	//ft_pa_pb(stack_a, stack_b, 2); // Push two elements in stack B or push Just one, why push two? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
	//ft_pa_pb(stack_a, stack_b, 2); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (stack_a->size > 2)
	{
		find_cheapest(stack_a, stack_b, 0);
		printf("stack_b->size: %d <------> stack_a->size: %d\n", stack_b->size, stack_a->size);
		printf("Zero problem: %d\n", stack_b->arr[0]);
		ft_pa_pb(stack_a, stack_b, 2);
		if (stack_b->size >= 2 && stack_b->arr[0] < stack_b->arr[1])
			ft_sa_sb_ss(NULL, stack_b, 2);
		else if (stack_b->size >= 2 && stack_b->arr[0] < stack_b->arr[1] && stack_b->arr[0] < stack_b->arr[stack_b->size - 1])
			rotate(stack_b, NULL, 1, 1);	
	}
	if (stack_a->arr[0] > stack_a->arr[1])
		ft_sa_sb_ss(stack_a, NULL, 1);	
	// int i = 0;
	// while (i < stack_b->size)
	// {
	// 	printf("Stack B after sort: %d\n", stack_b->arr[i]);
	// 	i++;
	// }
	// while (stack_b->size > 0)
	// {
	// 	if (stack_b->size >= 2 && stack_b->arr[0] < stack_b->arr[1])
	// 		ft_sa_sb_ss(NULL, stack_b, 2);
	// 	index = find_min_max_index(stack_b, 1);
	// 	rotate_min_max(stack_b, stack_a, index, 1);
	// 	ft_pa_pb(stack_a, stack_b, 1);
	// }
}

void	push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;
	
	stack_b = malloc(sizeof(t_stack));
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
}
