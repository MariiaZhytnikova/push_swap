#include "push_swap.h"

int	closest_above(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->array[i] > n && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

int	closest_below(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n < min(a))
		return (n);
	i = 0;
	k = min(a);
	while (i <= a->top)
	{
		if (a->array[i] < n && a->array[i] > k)
			k = a->array[i];
		i++;
	}
	return (k);
}

/*
** Put the number 'n' at the top of the stack,
** in the least amount of moves possible (RRA
** or RA). Do nothing if 'n' isn't on stack;
*/

void	smart_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		run_n(RRA, a, NULL, find + 1);
	else
		run_n(RA, a, NULL, a->top - find);
}

void	smart_rotate_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (b->array[find] != n && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		run_n(RRB, NULL, b, find + 1);
	else
		run_n(RB, NULL, b, b->top - find);
}

void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	smart_rotate_a(a, to_move);
	run(PA, a, b);
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_min_or_max_to_top(b); // HERE
		put_in_position(a, b);
	}
}

void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		run(PB, a, b);
		size--;
	}
}

size_t	get_chunks(t_stack *a)
{
	size_t	chunks;

	chunks = (a->top + 1) / CHUNK_CONSTANT + 1;
	return (chunks);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int		limit_min;
	int		limit_max;
	size_t	chunks;
	size_t	step;

	chunks = get_chunks(a);
	limit_max = max(a);
	step = (a->top + 1) / chunks;
	while (chunks >= 1)
	{
		if (chunks == 1)
			limit_min = min(a);
		else
			limit_min = limit_max - step + 1;
		move_chunk(a, b, limit_min, limit_max);
		sort_chunk(a, b);
		limit_max = limit_min - 1;
		chunks--;
	}
	smart_rotate_a(a, min(a));
}

int	closest_above(t_stack *a, int n);
int	closest_below(t_stack *a, int n);
void	smart_rotate_a(t_stack *a, int n);
void	smart_rotate_b(t_stack *a, int n);
void	put_in_position(t_stack *a, t_stack *b);
void	sort_chunk(t_stack *a, t_stack *b);
void	move_chunk(t_stack *a, t_stack *b, int min, int max);
size_t	get_chunks(t_stack *a);
void	sort_complex(t_stack *a, t_stack *b);


 min // need to search it
 max // need to search it
 run_n
 run


static int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (between(a->array[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (between(a->array[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = find_from_top(a, min, max);
	index[1] = find_from_bottom(a, min, max);
	if (index[0] < a->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate_a(a, a->array[i]);
}

void	move_min_or_max_to_top(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = _index(b, min(b));
	index[1] = _index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate_b(b, b->array[i]);
}
