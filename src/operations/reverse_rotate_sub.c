#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	rotate_tail_to_head(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_back(stack);
	deque_add_front(stack, move_node);
}

void	rra(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_tail_to_head(stack_a);
}

void	rrb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_tail_to_head(stack_b);
}
