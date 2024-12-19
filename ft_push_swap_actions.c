/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:50:42 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/17 17:42:58 by mzhitnik         ###   ########.fr       */
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

static void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	
	if (stack_b->arr[0])
	{
		i = stack_a->size;
		while ( i > 0)
		{
			stack_a->arr[i] = stack_a->arr[i - 1];
			i--;
		}
		stack_a->arr[0] = stack_b->arr[0];
		i = 0;
		while (stack_b->arr[i])
		{
			stack_b->arr[i] = stack_b->arr[i + 1];
			i++;
		}
		stack_b->arr[i] = 0;
	}	
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

/*
static void	ft_arr_copy(int **in, int **from, int size)
{
	int	i;
	
	while (i < size)
	{
		in[i] = from[i];
		i++;
	}
}

static void	ft_push(t_stack *in, t_stack *from) // where from
{
	int	i;
	t_stack	temp_from;
	t_stack	temp_in;
	
	if (from->size > 0)
	{
		i = in->size;
		temp_in.size = in->size + 1;
		temp_in.arr = calloc(in->size + 1, sizeof(int));
		if (!temp_in.arr)
			return ;
		while ( i > 0)
		{
			temp_in.arr[i] = in->arr[i - 1];
			i--;
		}
		temp_in.arr[0] = from->arr[0];
		free(in->arr);
		in->arr = temp_in.arr;
		in->size++;
		i = 0;
		while (i < in->size)
		{
			printf("stack IN after push: %d\n", in->arr[i]);
			i++;
		}
	 	temp_from.size = from->size - 1;
	 	temp_from.arr = calloc(from->size - 1, sizeof(int));
	 	if (!temp_from.arr)
	 		return ;
		i = 0;
	 	while (i < temp_from.size)
	 	{
	 		temp_from.arr[i] = from->arr[i + 1];
	 		i++;
	 	}
		from->size--;
	 	free(from->arr);		
	 	from->arr = temp_from.arr;
		ft_arr_copy(&from->arr, &temp_from.arr, temp_from.size);
	 	free(temp_from.arr);
	 	i = 0;
	 	while (i < from->size)
	 	{
	 		printf("stack from after push: %d\n", from->arr[i]);
	 		i++;
	 	}
	}
}

*/
