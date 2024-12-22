/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:42 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/22 20:46:20 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1 sa (swap a): If there are 2 numbers, swap the first 2 elements at the top of the stack a.
   2 sb (swap b ) :  If there are 2 numbers, swap the first 2 elements at the top of the stack b.
   3 ss : sa and sb at the same time. */

static void ft_swap(t_stack *stack)
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
	int	temp;
	
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

/* 1 pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
   2 pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. */

static int	*ft_arr_copy(int *src, int size)
{
	int	i;
	int	*temp;

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
	int	new_dest[dest->size + 1];
	int	new_src[src->size];
	
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
	if (!stack_a || !stack_b)
		return ;	
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
