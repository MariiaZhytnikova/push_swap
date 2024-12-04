#include "push_swap.h"

int parse_args(char **argv, t_stack *stack)
{
    int i;

    i = 0;
    while (argv[i])
    {
        stack->arr[i] = ft_atoi(argv[i]);
        if (stack->arr[i] == 0)
            return (1);
        i++;
    }
    return (0);
}
