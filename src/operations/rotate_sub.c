#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	rotate_head_to_tail(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_front(stack);
	deque_add_back(stack, move_node);
}

void	ra(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_head_to_tail(stack_a);
}

void	rb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_head_to_tail(stack_b);
}
