/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:42 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 16:38:10 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	int	i;
	int	temp[1024];

	if (stack->size < 2)
		return ;
	i = 0;
	while (i < stack->size - 1)
	{
		temp[i] = stack->arr[i + 1];
		i++;
	}
	temp[i] = stack->arr[0];
	free(stack->arr);
	stack->arr = ft_arr_copy(temp, stack->size);
}

static void	ft_rrotate(t_stack *stack)
{
	int	i;
	int	temp[1024];

	if (stack == NULL || stack->arr == NULL)
		return ;
	temp[0] = stack->arr[stack->size - 1];
	i = 1;
	while (i < stack->size)
	{
		temp[i] = stack->arr[i - 1];
		i++;
	}
	free(stack->arr);
	stack->arr = ft_arr_copy(temp, stack->size);
}

void	ft_ra_rb_rr(t_stack *stack_a, t_stack *stack_b, int act)
{
	if (act == 1)
	{
		ft_rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
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
	if (act == 1 && stack_a->size > 1)
	{
		ft_rrotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (act == 2 && stack_b->size > 1)
	{
		ft_rrotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (act == 3 && stack_a->size > 1 && stack_b->size > 1)
	{
		ft_rrotate(stack_a);
		ft_rrotate(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}
