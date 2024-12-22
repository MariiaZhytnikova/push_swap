
#include "push_swap.h"

int ft_get_chunk_size(int size)
{
    if (size <= 100)
        return (size / 5);  // 20 numbers per chunk for 100
    return (size / 11);     // ~45 numbers per chunk for 500
}

int ft_chunk_is_empty(t_stack *stack, int chunk, int chunk_size)
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
            return (0);
        i++;
    }
    return (1);
}

void ft_sort_big(t_stack *a, t_stack *b)
{
    int chunk;
    int chunk_size;
    int hold_first;
    int hold_second;

    chunk_size = ft_get_chunk_size(a->size);
    chunk = 0;
    while (a->size > 0)
    {
        hold_first = ft_find_first(a, chunk, chunk_size);
        hold_second = ft_find_second(a, chunk, chunk_size);
        
        if (hold_first <= hold_second)
        {
            ft_rotate_to_top(a, a->arr[hold_first]);
            ft_pa_pb(a, b, 2);
        }
        else
        {
            ft_rotate_to_top(a, a->arr[hold_second]);
            ft_pa_pb(a, b, 2);
            if (b->size > 1)
                ft_ra_rb_rr(NULL, b, 2);
        }
        if (ft_chunk_is_empty(a, chunk, chunk_size))
            chunk++;
    }
}
