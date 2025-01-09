/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:54:55 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/30 12:46:40 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_outlimits(t_stack stack, char **res)
{
	int		i;
	char	*cmp;

	i = 0;
	while (i < stack.size)
	{
		cmp = ft_itoa(stack.arr[i]);
		if (ft_strncmp(res[i], cmp, ft_strlen(res[i])) != 0)
		{
			free(res);
			return (-1);
		}
		free(cmp);
		i++;
	}
	return (0);	
}

static int	ft_duplicates(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.size)
	{
		j = 0;
		while (j < stack.size)
		{
			if (stack.arr[i] == stack.arr[j] && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_args_check(char *res)
{
	size_t j;
	
	j = 0;
	while (res[j])
	{
		if (ft_isdigit(res[j]))
			{
				j++;
				if (res[j] && !ft_isdigit(res[j]))
					return (-1);
			}
		else
			if((res[j] == '+' || res[j] == '-') && ft_isdigit(res[j+1]))
				j++;
		else
			return (-1);
	}
	return (0);
}

t_stack *ft_parse_one(char *argv)
{
	int	i;
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
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(1), NULL);
	stack->size = i;
	stack->arr = calloc(stack->size, sizeof(int));
	if (!stack->arr)
		return (ft_error(1), NULL);
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
	int	i;
	t_stack	*stack;
	
	i = 1;
	while (argv[i])
	{
		if (ft_args_check(argv[i]) < 0)
			return (NULL);
		i++;
	}
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(1), NULL);
	stack->size = i - 1;
	stack->arr = calloc(stack->size, sizeof(int));
	if (!stack->arr)
		return (ft_error(1), NULL);
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
