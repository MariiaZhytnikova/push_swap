## PushSwap

PushSwap is a sorting algorithm implemented as part of the 42 curriculum, designed to sort a stack of integers using a limited set of operations. The goal is to use the fewest number of moves to sort the stack, showcasing algorithm optimization and the efficient use of basic stack operations.

PushSwap is a challenge from the 42 coding school that requires students to implement an efficient sorting algorithm with a stack-based approach. The sorting must be done with only four operations:

-    Push (p): Move the top element from one stack to the other.
-    Swap (s): Swap the top two elements of a stack.
-    Rotate (r): Move the top element of the stack to the bottom.
-    Reverse Rotate (rr): Move the bottom element of the stack to the top.

The objective is to sort the stack with the fewest number of operations, which requires the implementation of an efficient sorting algorithm.
How It Works

The sorting is done on two stacks: Stack A and Stack B. Stack A contains the unsorted elements, while Stack B is used as auxiliary storage for moving elements between stacks during the sorting process.

The program must:

-    Sort the stack in ascending order with the fewest moves.
-    Implement custom algorithms (e.g., optimized versions of selection sort, bubble sort, quicksort, etc.) using only the allowed operations.

Operations

The program uses the following operations:

    sa (Swap A): Swap the top two elements of stack A.
    sb (Swap B): Swap the top two elements of stack B.
    ss (Swap Both): Perform sa and sb simultaneously.
    pa (Push A): Push the top element of stack B to stack A.
    pb (Push B): Push the top element of stack A to stack B.
    ra (Rotate A): Rotate stack A (move the top element to the bottom).
    rb (Rotate B): Rotate stack B (move the top element to the bottom).
    rr (Rotate Both): Perform ra and rb simultaneously.
    rra (Reverse Rotate A): Reverse rotate stack A (move the bottom element to the top).
    rrb (Reverse Rotate B): Reverse rotate stack B (move the bottom element to the top).
    rrr (Reverse Rotate Both): Perform rra and rrb simultaneously.

Algorithm Complexity

The complexity of the push-swap algorithm depends on the number of elements to be sorted. While the worst-case time complexity is generally O(n²) using basic sorting strategies, optimizations can be made to improve performance, potentially reaching O(n log n).

![image](https://github.com/user-attachments/assets/a1438aa9-73a6-4f6e-88fb-2b5c1807ba6c)

Time complexity: O(nlog⁡n)  
    The algorithm uses efficient sorting techniques that divide the problem into smaller parts, resulting in a log-linear growth pattern.

Space complexity: O(n)
    The algorithm only uses two stacks (A and B) for sorting, and since it’s using a limited amount of additional memory (excluding the input stack), the space used grows linearly with the number of elements.

Usage

To use the PushSwap program:

Compile the program:

    make

Run the program with a list of integers:

    ./push_swap 10 3 8 1 2 5 4

The program will output the sequence of moves that sorts the stack using the fewest number of operations.

Example:

    sa
    pb
    ra
    ...

The above sequence of moves sorts the stack with the fewest moves.
Contributing
