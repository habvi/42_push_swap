#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"

void	move_op(t_nums *stack_a, t_nums *stack_b, t_operation op)
{
	(void)stack_a;
	(void)stack_b;
	(void)op;
	return ;
}

bool	is_stack_a_sorted_bonus(t_nums *stack_a, const size_t size_a)
{
	(void)stack_a;
	(void)size_a;
	return (true);
}

t_result	sort_and_judge(t_nums *stack_a, t_nums *ops, t_error *error_code)
{
	const size_t	size_a = stack_a->size;
	t_nums			*stack_b;
	t_deque			*node;
	t_operation		op;

	stack_b = init_nums(0, error_code);
	if (*error_code)
		return (RESULT_ERROR);
	node = ops->deque->next;
	while (node)
	{
		op = node->num;
		move_op(stack_a, stack_b, op);
		node = node->next;
	}
	if (is_stack_a_sorted_bonus(stack_a, size_a))
		return (OK);
	return (KO);
}
