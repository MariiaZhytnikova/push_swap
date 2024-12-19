/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/19 21:59:40 by mzhitnik         ###   ########.fr       */
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

static void ft_min_first(t_stack *stack)
{
	int	min;

	min = 0;
	while (min < stack->size)
	{
		if (stack->arr[min] == 1)
			break ;
		min++;
	}
	if (min < 2)
	{
		while (stack->arr[0] != 1)
			ft_ra_rb_rr(stack, NULL, 1);
	}
	else
	{
		while (stack->arr[0] != 1)
			ft_rra_rrb_rrr(stack, NULL, 1);
	}
}

static void ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4 && !ft_ifsorted(stack_a))
	{
		ft_min_first(stack_a);
		ft_pa_pb(stack_a, stack_b, 2);
		ft_sort_three(stack_a);
		ft_pa_pb(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5 && !ft_ifsorted(stack_a))
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
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2) // Sort two
	{
		if (stack_a->arr[0] > stack_a->arr[1])
			ft_sa_sb_ss(stack_a, NULL, 1);
		return ;
	}
	else if (stack_a->size == 3) // Sort three
		ft_sort_three(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_five(stack_a, stack_b);
//	else if (size <= 100)
//		sort_chunking(stack_a, stack_b, 20);
//	else
//		sort_radix(stack_a, stack_b);
}

/*required: sort   3 numbers with <=     3 operations
required: sort   5 numbers with <=    12 operations
scored:   sort 100 numbers with <=   700 operations   max score
                                     900 operations
                                    1100 operations
                                    1300 operations
                                    1500 operations   min score
scored:   sort 500 numbers with <=  5500 operations   max score
                                    7000 operations
                                    8500 operations
                                   10000 operations
                                   11500 operations   min score*/
