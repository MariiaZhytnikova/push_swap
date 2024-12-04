/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:01:50 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/12/04 15:42:44 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if (argc < 2)
        return (1);

    stack_a.size = argc - 1;
    stack_a.arr = malloc(sizeof(int) * stack_a.size);
    if (!stack_a.arr)
        return (1);
    stack_b.size = 0;
    stack_b.arr = malloc(sizeof(int) * stack_b.size);
    if (!stack_b.arr)
        return (1);
    if (parse_args(argv, &stack_a))
        return (1);
    push_swap(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}


/* Checks:
The program must work with several numerical arguments

    ./push_swap 1 3 5 +9 20 -4 50 60 04 08

The program also works if you receive a single character list as a parameter

    ./push_swap "3 4 6 8 9 74 -56 +495"

The program should NOT work if it encounters another character

./push_swap 1 3 dog 35 80 -3

./push_swap a

./push_swap 1 2 3 5 67b778 947

.push_swap " 12 4 6 8 54fhd 4354"

./push_swap 1 --    45 32

        these examples should return "Error\n"

The program should NOT work if it encounters a double number

./push_swap 1 3 58 9 3

./push_swap 3 03

./push_swap " 49 128     50 38   49"

    these examples should return "Error\n"

./push_swap "95 99 -9 10 9"

        this example should work because -9 & 9 are not equal

The program should work with INT MAX & INT MIN

./push_swap 2147483647 2 4 7

./push_swap 99 -2147483648 23 545

./push_swap "2147483647 843 56544 24394"

    these examples should work and sort your list

./push_swap 54867543867438 3

./push_swap -2147483647765 4 5

./push_swap "214748364748385 28 47 29"

        these examples should return "Error\n"

Nothing has been specified when strings and int are mixed. It's up to you what you want to do

./push_swap "1 2 4 3" 76 90 "348 05


sa (swap a): If there are 2 numbers, swap the first 2 elements at the top of the stack a.

sb (swap b ) :  If there are 2 numbers, swap the first 2 elements at the top of the stack b.

ss : sa and sb at the same time. 

pa (push a): If b is not empty it takes the first element on top of b and puts it on a.

pb (push b): If a is not empty, it takes the first element on top of a and puts it on b.

ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 

rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 

rr : ra and rb at the same time. 

rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 

rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 

rrr : rra and rrb at the same time


*/
