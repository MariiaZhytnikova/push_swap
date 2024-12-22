
#include "push_swap.h"

void ft_sort_big(t_stack *a, t_stack *b)
{
    int chunk_count;
    int chunk_size;
    int i;
    int min;
    int max;

    // Adjust chunk sizes based on array size
    chunk_count = (a->size <= 100) ? 5 : 11;
    chunk_size = a->size / chunk_count;
    max = chunk_size - 1;
    
    // Push numbers in chunks, smallest to largest
    while (a->size > 0)
    {
        min = ft_find_closest_in_range(a, 0, max);
        while (min != -1)
        {
            ft_rotate_to_top(a, min);
            ft_pa_pb(a, b, 2);  // pb
            min = ft_find_closest_in_range(a, 0, max);
        }
        max += chunk_size;
    }
    
    // Push back all numbers to A
    while (b->size > 0)
    {
        ft_rotate_to_top(b, ft_find_max(b));
        ft_pa_pb(a, b, 1);  // pa
    }
}
