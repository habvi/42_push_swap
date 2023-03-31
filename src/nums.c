#include <stdlib.h> // malloc
#include "deque.h"
#include "push_swap.h"
#include "error.h"

t_nums	*nums_new(t_error *error_code)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	nums->deque = NULL;
	nums->size = 0;
	return (nums);
}

static bool	is_same_number_in_stack_a(t_deque *node, t_deque *stack_a)
{
	while (stack_a)
	{
		if (stack_a == node)
		{
			stack_a = stack_a->next;
			continue ;
		}
		if (node->num == stack_a->num)
			return (true);
		stack_a = stack_a->next;
	}
	return (false);
}

static bool	is_duplicate_numbers(t_nums *nums, t_error *error_code)
{
	t_deque	*stack_a;
	t_deque	*node;

	stack_a = nums->deque->next;
	node = stack_a;
	while (node)
	{
		if (is_same_number_in_stack_a(node, stack_a))
		{
			*error_code = ERROR_ARGS;
			return (true);
		}
		node = node->next;
	}
	return (false);
}

bool	is_valid_nums(t_nums *nums, t_error *error_code)
{
	if (deque_is_empty(nums->deque))
		return (true);
	if (is_duplicate_numbers(nums, error_code))
		return (false);
	return (true);
}
