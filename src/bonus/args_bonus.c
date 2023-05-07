#include "deque.h"
#include "push_swap.h"

static bool	has_duplicate_numbers_bonus(t_nums *stack_a)
{
	t_deque	*now_node;
	t_deque	*cmp_node;

	now_node = stack_a->deque->next;
	while (now_node)
	{
		cmp_node = now_node->next;
		while (cmp_node)
		{
			if (now_node->num == cmp_node->num)
				return (true);
			cmp_node = cmp_node->next;
		}
		now_node = now_node->next;
	}
	return (false);
}

bool	is_valid_argv_bonus(t_nums *stack_a)
{
	if (is_stack_a_empty(stack_a->size))
		return (false);
	if (has_duplicate_numbers_bonus(stack_a))
		return (false);
	return (true);
}
