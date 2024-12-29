/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:42 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/17 17:24:22 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1 ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 
   2 rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 
   3 rr : ra and rb at the same time. 
   11 rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 
   22 rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 
   33 rrr : rra and rrb at the same time */

static void	ft_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->arr[0] && stack->arr[1])
	{
		temp = stack->arr[0];
		i = 0;
		while (i < stack->size)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[stack->size - 1] = temp;
	}
}

static void	ft_rrotate(t_stack *stack)
{
		int	i;
		int	temp;

		temp = stack->arr[stack->size - 1];
		i = stack->size;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = temp;
}


void	ft_ra_rb_rr(t_stack *stack_a, t_stack *stack_b, int act)
{
	if (act == 1)
	{
		ft_rotate(stack_a);
		ft_putstr_fd("ra\n",  1);
	}
	if (act == 2)
	{
		ft_rotate(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (act == 3)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		ft_putstr_fd("rr\n", 1);
	}	
}

void	ft_rra_rrb_rrr(t_stack *stack_a, t_stack *stack_b, int act)
{
	if (act == 1)
	{
		ft_rrotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (act == 2)
	{
		ft_rrotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (act == 3)
	{
		ft_rrotate(stack_a);
		ft_rrotate(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}	
}