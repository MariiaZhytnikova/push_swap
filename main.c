/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:01:50 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/17 17:46:24 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv) // need to add the function for error
{
	t_stack stack_a;
	t_stack stack_b;
	int	res;
	int i;

	if (argc < 2)
		return (1);
	stack_a.size = argc - 1; // initialization and argcheck in separate function
	stack_a.arr = calloc(stack_a.size, sizeof(int));
	if (!stack_a.arr)
		return (1);
	if (argc == 2)
		res = ft_parse_one(argv[1], &stack_a);
	else
		res = ft_parse_ml(argv, &stack_a);
	if (res < 0)
	{
		printf("Wrong arguments!\n");
		return (1);
	}
	stack_b.size = stack_a.size;
	stack_b.arr = calloc(stack_b.size, sizeof(int));
	if (!stack_b.arr)
		return (1);
	ft_mapping(&stack_a);
	printf("Stack A\n");
		i = 0;
	while (i < stack_a.size)
	{
		printf("%d\n", stack_a.arr[i]);
		i++;
	}

	printf("Stack B\n");
	i = 0;
	while (i < stack_b.size)
	{
		printf("%d\n", stack_b.arr[i]);
		i++;
	}
//	ft_ra_rb_rr(&stack_a, &stack_a, 3);
//	ft_rra_rrb_rrr(&stack_a, &stack_a, 3);

//	ft_sa_sb_ss(&stack_a, &stack_a, 3);
//	ft_pa_pb(&stack_a, &stack_b, 2);

//	push_swap(&stack_a, &stack_b);
//	free_stack(&stack_a);
//	free_stack(&stack_b);
	return (0);
}
