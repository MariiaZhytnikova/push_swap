/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:36:27 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/17 10:59:14 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_inssort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;
	
	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >=0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	ft_mapping(t_stack *stack)
{
	int	sort[stack->size];
	int	i;
	int	j;
	
	i = 0;
	while (i < stack->size)
	{
		sort[i] = stack->arr[i];
		i++;
	}
	ft_inssort(sort, stack->size);
	i = 0;
	while(i < stack->size)
	{
		j = 0;
		while(j < stack->size)
		{
			if (stack->arr[i] == sort[j])
			{
				stack->arr[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}
