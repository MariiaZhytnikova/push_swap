/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:42 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 16:37:39 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->arr[0] && stack->arr[1])
	{
		tmp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = tmp;
	}
}

void	ft_sa_sb_ss(t_stack *stack_a, t_stack *stack_b, int act)
{
	if (act == 1)
	{
		ft_swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (act == 2)
	{
		ft_swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	if (act == 3)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		ft_putstr_fd("ss\n", 1);
	}
}

int	*ft_arr_copy(int *src, int size)
{
	int	i;
	int	*temp;

	if (!src)
		return (NULL);
	temp = calloc(size, sizeof(int));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp[i] = src[i];
		i++;
	}
	return (temp);
}

static void	ft_push(t_stack *dest, t_stack *src)
{
	int	i;
	int	new_dest[1024];
	int	new_src[1024];

	if (src->size == 0 && !src->arr)
		return ;
	new_dest[0] = src->arr[0];
	i = 0;
	while (i < dest->size)
	{
		new_dest[i + 1] = dest->arr[i];
		i++;
	}
	i = 0;
	while (i < src->size - 1)
	{
		new_src[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	free(src->arr);
	src->arr = ft_arr_copy(new_src, src->size);
	dest->size++;
	free(dest->arr);
	dest->arr = ft_arr_copy(new_dest, dest->size);
}

void	ft_pa_pb(t_stack *stack_a, t_stack *stack_b, int act)
{
	if (act == 1)
	{
		ft_push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	}
	if (act == 2)
	{
		ft_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
	}
}
