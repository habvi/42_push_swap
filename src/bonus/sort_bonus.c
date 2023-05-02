#include <stdlib.h> // free
#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

// no error returns
void	move_op(\
		t_nums *stack_a, t_nums *stack_b, t_operation op, t_error *error_code)
{
	t_data	data;

	data = (t_data){.stack_a = stack_a, .stack_b = stack_b};
	run_operation(op, &data, NONE, error_code);
}

bool	is_stack_a_sorted_bonus(t_nums *stack_a, const size_t size_a)
{
	t_deque	*node;
	int		num;

	node = stack_a->deque->next;
	num = 1;
	while (node)
	{
		if (node->num != num)
			return (false);
		node = node->next;
		num++;
	}
	if ((size_t)num != size_a + 1)
		return (false);
	return (true);
}

t_result	sort_and_judge(\
			t_nums *stack_a, t_nums *ops, int *sorted_a, t_error *error_code)
{
	const size_t	size_a = stack_a->size;
	t_nums			*stack_b;
	t_deque			*node;
	t_operation		op;

	stack_a = compress_number(stack_a, sorted_a);
	stack_b = init_nums(0, error_code);
	if (*error_code)
		return (RESULT_NONE);
	node = ops->deque->next;
	while (node)
	{
		op = node->num;
		move_op(stack_a, stack_b, op, error_code);
		node = node->next;
	}
	free_nums(stack_b);
	if (is_stack_a_sorted_bonus(stack_a, size_a))
		return (OK);
	return (KO);
}
