
#include "push_swap.h"

int ft_find_max(t_stack *stack)
{
    int i;
    int max;

    if (!stack || stack->size == 0)
        return (-1);
    i = 0;
    max = stack->arr[0];
    while (i < stack->size)
    {
        if (stack->arr[i] > max)
            max = stack->arr[i];
        i++;
    }
    return (max);
}

int ft_find_closest_in_range(t_stack *stack, int min, int max)
{
    int i;
    int top_dist;
    int bottom_dist;
    int closest_num;

    closest_num = -1;
    top_dist = stack->size;
    bottom_dist = stack->size;
    i = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] >= min && stack->arr[i] <= max)
        {
            if (i < top_dist)
            {
                top_dist = i;
                closest_num = stack->arr[i];
            }
            if ((stack->size - i) < bottom_dist)
            {
                bottom_dist = stack->size - i;
                if (bottom_dist < top_dist)
                    closest_num = stack->arr[i];
            }
        }
        i++;
    }
    return (closest_num);
}

void ft_rotate_to_top(t_stack *stack, int num)
{
    int pos;
    
    pos = ft_find_position(stack, num);
    while (stack->arr[0] != num)
    {
        if (pos <= stack->size / 2)
            ft_ra_rb_rr(stack, NULL, 1);  // ra
        else
            ft_rra_rrb_rrr(stack, NULL, 1);  // rra
    }
}

int ft_find_position(t_stack *stack, int num)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] == num)
            return (i);
        i++;
    }
    return (-1);
}
