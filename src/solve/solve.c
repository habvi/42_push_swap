#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

bool	is_stack_sorted(t_nums *stack, int *array)
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

void	solve(t_data *data, t_error *error_code)
{
	data->stack_a = compress_number(data->stack_a, data->sorted_array);
	if (is_stack_sorted(data->stack_a, data->sorted_array))
		return ;
	if (data->stack_a->size <= RECURSION_LIMIT)
		solve_le_6(data, error_code);
	else
		solve_over_6(data, error_code);
}
