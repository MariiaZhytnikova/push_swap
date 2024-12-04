/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/04 15:43:37 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void push_swap(t_stack *stack_a, t_stack *stack_b) {
    int size = stack_size(stack_a);

    if (size <= 1)
        return;
    else if (size == 2)
        sort_2_elements(stack_a);
    else if (size == 3)
        sort_3_elements(stack_a);
    else if (size <= 5)
        sort_4_5_elements(stack_a, stack_b);
    else if (size <= 100)
        sort_chunking(stack_a, stack_b, 20); // Разделите на чанки по 20 элементов
    else
        sort_radix(stack_a, stack_b);
}
/*
Algorithm/Sort Checklist

Check if the order of the list is correct or if it should be sorted

Make a small algorithm for small numbers (5 and less)

Implement a condition for 2 numbers

Create an algorithm for 3 numbers

Create an algorithm for 4 numbers

    Create an algorithm for 5 numbers

Create another algorithm for all other numbers


*/
