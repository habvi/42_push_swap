#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

bool	is_stack_a_sorted_bonus(t_nums *stack_a)
{
	t_deque			*node;
	size_t			i;
	const size_t	size = stack_a->size;

	node = stack_a->deque->next;
	i = 0;
	while (i + 1 < size)
	{
		if (node->num > node->next->num)
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}

// run_operation: no error returns
void	move_op(t_nums *stack_a, t_nums *ops, t_error *error_code)
{
	t_data	data;
	t_deque	*node;
	t_nums	*stack_b;

	if (deque_is_empty(ops->deque))
		return ;
	stack_b = init_nums(0, error_code);
	if (*error_code)
		return ;
	data = (t_data){.stack_a = stack_a, .stack_b = stack_b};
	node = ops->deque->next;
	while (node)
	{
		run_operation(node->num, &data, NONE, error_code);
		node = node->next;
	}
	free_nums(stack_b);
}
