
#include "push_swap.h"

int ft_find_first(t_stack *stack, int chunk, int chunk_size)
{
    int i;
    int min;
    int max;

    min = chunk * chunk_size;
    max = min + chunk_size;
    i = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] >= min && stack->arr[i] < max)
            return (i);
        i++;
    }
    return (-1);
}

int ft_find_second(t_stack *stack, int chunk, int chunk_size)
{
    int i;
    int min;
    int max;
    int first;

    min = chunk * chunk_size;
    max = min + chunk_size;
    first = 0;
    i = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] >= min && stack->arr[i] < max)
        {
            if (first == 0)
                first = 1;
            else
                return (i);
        }
        i++;
    }
    return (-1);
}

int ft_find_second_max(t_stack *stack)
{
    int i;
    int max;
    int second_max;

    if (!stack || stack->size < 2)
        return (-1);
    i = 0;
    max = ft_find_max(stack);
    second_max = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] > second_max && stack->arr[i] < max)
            second_max = stack->arr[i];
        i++;
    }
    return (second_max);
}

void ft_push_back(t_stack *a, t_stack *b)
{
    int max;
    int second_max;

    while (b->size > 0)
    {
        max = ft_find_max(b);
        second_max = ft_find_second_max(b);
        
        if (ft_find_position(b, max) <= b->size / 2)
        {
            while (b->arr[0] != max)
                ft_ra_rb_rr(NULL, b, 2);
        }
        else
        {
            while (b->arr[0] != max)
                ft_rra_rrb_rrr(NULL, b, 2);
        }
        ft_pa_pb(a, b, 1);
    }
}