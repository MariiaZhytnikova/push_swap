/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:02:51 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 18:22:49 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int code)
{
	if (code == 1)
	{
		write(2, "Error\n", 6);
	}
}

int	ft_ifsorted(t_stack *stack)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = ft_parse_one(argv[1]);
	else
		stack_a = ft_parse_ml(argv);
	if (!stack_a)
		return (ft_error(1), 0);
	ft_mapping(stack_a);
	if (!ft_ifsorted(stack_a))
		push_swap(stack_a);
	if (ft_ifsorted(stack_a))
		printf("sorted");
	free(stack_a->arr);
	free(stack_a);
	return (0);
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