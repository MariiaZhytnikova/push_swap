/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:54:55 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/16 10:45:59 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_outlimits(t_stack stack, char **res)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		if (ft_strncmp(res[i], ft_itoa(stack.arr[i]), ft_strlen(res[i])) != 0)
			return (-1);
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

int	ft_parse_one(char *argv, t_stack *stack)
{
	int	i;
	char	**res;
	
	res = ft_split(argv, ' ');
	i = 0;
	while (res[i])
	{
		if (ft_args_check(res[i]) < 0)
			return (-1);
		i++;
	}
	i = 0;
	while (res[i])
	{
		stack->arr[i] = ft_atoi(res[i]);
		i++;
	}
	stack->size = i;
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, res) < 0)
		return (-1);
	return (0);
}


int	ft_parse_ml(char **argv, t_stack *stack)
{
	int	i;
	int	temp;

	i = 1;
	while (argv[i])
	{
		if (ft_args_check(argv[i]) < 0)
			return (-1);
		i++;
	}
	stack->size = i - 1;
	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_duplicates(*stack) < 0 || ft_outlimits(*stack, ++argv) < 0)
		return (-1);
	return (0);
}

/* Checks: NOT work if OVERFLOW should give ERROR
test cases:

1 +3 -3 6 5465-4645 
1 -- 5 6 8 -4
6 7 8 ++ 5 5
1 2 3 4 - 5
1 2 3 + 5 8
2 56a67 5 7 9
6 d 4 8 0
a
0
./push_swap 2147483647 2 4 7

./push_swap 99 -2147483648 23 545

./push_swap "2147483647 843 56544 24394"

./push_swap 54867543867438 3

./push_swap -2147483647765 4 5

./push_swap "214748364748385 28 47 29"

Nothing has been specified when strings and int are mixed. It's up to you what you want to do

./push_swap "1 2 4 3" 76 90 "348 05
*/
