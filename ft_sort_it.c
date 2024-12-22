/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:09:07 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/22 14:19:46 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_it(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	
	while (stack_a->size != 0)
	{
		ft_min_first(stack_a);
		ft_pa_pb(stack_a, stack_b, 2);
	}
	while (stack_b->size != 0)
		ft_pa_pb(stack_a, stack_b, 1);
}