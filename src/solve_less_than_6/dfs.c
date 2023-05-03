#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

bool	is_operation_exceeded_answer_size(t_data *data)
{
	if (data->now_op->size >= data->answer->size)
		return (true);
	return (false);
}

static bool	is_stack_sorted(t_nums *stack, int *array)
{
	t_deque	*node;
	size_t	i;

	node = stack->deque->next;
	i = 0;
	while (i < stack->size)
	{
		if (node->num != array[i])
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}

bool	is_stack_a_sorted(t_nums *stack_a, t_nums *stack_b, int *sorted_array)
{
	if (!deque_is_empty(stack_b->deque))
		return (false);
	if (is_stack_sorted(stack_a, sorted_array))
		return (true);
	return (false);
}

bool	is_limit_operation_size(size_t size)
{
	if (size == OPERATION_LIMIT_LESS_THAN_6)
		return (true);
	return (false);
}
