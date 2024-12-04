#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

void push_swap(t_stack *stack_a, t_stack *stack_b);
void swap(t_stack *stack);
void push(t_stack *stack_from, t_stack *stack_to);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void sort_three(t_stack *stack); // < 3 perebor 4?
void sort_five(t_stack *stack_a, t_stack *stack_b); // 5-100 // chunking
void sort_big(t_stack *stack_a, t_stack *stack_b); // > 100 // Radix sort
void free_stack(t_stack *stack);
int parse_args(char **argv, t_stack *stack); // check

#endif
