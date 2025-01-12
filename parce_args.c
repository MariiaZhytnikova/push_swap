/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:54:55 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/12 18:33:38 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init(t_stack *stack, int size)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(1), NULL);
	stack->size = size;
	stack->arr = calloc(stack->size, sizeof(int));
	if (!stack->arr)
		return (ft_error(1), NULL);
	return (stack);
}

t_stack	*ft_parse_one(char *argv)
{
	int		i;
	char	**res;
	t_stack	*stack;

	res = ft_split(argv, ' ');
	i = 0;
	while (res[i])
	{
		if (ft_args_check(res[i]) < 0)
			return (NULL);
		i++;
	}
	stack = init(stack, i);
	i = 0;
	while (res[i])
	{
		stack->arr[i] = ft_atoi(res[i]);
		i++;
	}
	stack->size = i;
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, res) < 0)
		return (NULL);
	return (stack);
}

t_stack	*ft_parse_ml(char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	while (argv[i])
	{
		if (ft_args_check(argv[i]) < 0)
			return (NULL);
		i++;
	}
	stack = init(stack, i - 1);
	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, ++argv) < 0)
		return (NULL);
	return (stack);
}
