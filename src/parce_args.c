/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:54:55 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:47 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr, t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		free(stack->arr);
		free(stack);
	}
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static t_stack	*init(t_stack *stack, int size)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(1), NULL);
	stack->size = size;
	stack->arr = calloc(stack->size, sizeof(int));
	if (!stack->arr)
	{
		free(stack);
		return (ft_error(1), NULL);
	}
	return (stack);
}

void	stack_atoi(t_stack *stack, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		stack->arr[i] = ft_atoi(str[i]);
		i++;
	}
}

t_stack	*ft_parse_one(char *argv)
{
	int		i;
	char	**res;
	t_stack	*stack;

	res = ft_split(argv, ' ');
	if (!*res)
		return (free(res), NULL);
	i = 0;
	while (res[i])
	{
		if (ft_args_check(res[i++]) < 0)
		{
			free_arr(res, NULL);
			return (NULL);
		}
	}
	stack = NULL;
	stack = init(stack, i);
	stack_atoi(stack, res);
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, res) < 0)
		return (free_arr(res, stack), NULL);
	return (free_arr(res, NULL), stack);
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
	stack = NULL;
	stack = init(stack, i - 1);
	stack_atoi(stack, argv + 1);
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, ++argv) < 0)
	{
		free(stack->arr);
		free(stack);
		return (NULL);
	}
	return (stack);
}
