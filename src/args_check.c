/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:29:34 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/01/13 18:01:53 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	skip_zeros(char *res)
{
	int	i;

	i = 0;
	if (res[0] == '+' || res[0] == '-')
		i++;
	while (res[i] == '0' && res[i + 1] != '\0')
		i++;
	if (res[i] == '0')
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
	{
		if (res[0] == '-')
			ft_memmove(res + 1, res + i, ft_strlen(res) - i + 1);
		else
			ft_memmove(res, res + i, ft_strlen(res) - i + 1);
	}
}

int	ft_outlimits(t_stack stack, char **res)
{
	int		i;
	char	*cmp;

	i = 0;
	while (i < stack.size)
	{
		cmp = ft_itoa(stack.arr[i]);
		skip_zeros(res[i]);
		if (ft_strncmp(res[i], cmp, ft_strlen(res[i])) != 0)
		{
			free(cmp);
			return (-1);
		}
		free(cmp);
		i++;
	}
	return (0);
}

int	ft_duplicates(t_stack stack)
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
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_args_check(char *res)
{
	size_t	j;

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
			if ((res[j] == '+' || res[j] == '-') && ft_isdigit(res[j + 1]))
				j++;
		else
		{
			return (-1);
		}
	}
	return (0);
}
