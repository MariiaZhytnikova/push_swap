/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:36:27 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 19:04:54 by mzhitnik         ###   ########.fr       */
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
		while (j >= 0 && arr[j] > key)
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
	int	sort[1024];
	int	i[2];

	i[1] = 0;
	while (i[1] < stack->size)
	{
		sort[i[1]] = stack->arr[i[1]];
		i[1]++;
	}
	ft_inssort(sort, stack->size);
	i[1] = 0;
	while (i[1] < stack->size)
	{
		i[0] = 0;
		while (i[0] < stack->size)
		{
			if (stack->arr[i[1]] == sort[i[0]])
			{
				stack->arr[i[1]] = i[0] + 1;
				break ;
			}
			i[0]++;
		}
		i[1]++;
	}
}
