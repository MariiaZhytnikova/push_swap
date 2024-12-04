## Push Swap
Push_swap is a project that teaches you about sorting algorithms and how to optimize them. The project involves sorting a stack of integers using a limited set of operations (push, swap and rotate) and minimizing the number of moves. 

At the beginning, you must have one stack, called stack a with all your numbers placed next to each other. With the help of the operations below, at the very end, all the numbers in your stack a will have to be sorted. 

To do this, you can have a second empty stack, called the stack b, on which you can temporarily send elements. Here are the operations you can use (and that you will have to code):

    sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 

    sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 

    ss : sa and sb at the same time. 

    pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 

    pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

    ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 

    rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 

    rr : ra and rb at the same time. 

    rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 

    rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 

    rrr : rra and rrb at the same time.
