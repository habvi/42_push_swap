#include <stdlib.h> // EXIT_
#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

static bool	is_valid_argc(const int argc)
{
	if (argc <= 1)
		return (false);
	return (true);
}

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

static bool	is_valid_argv_bonus(t_nums *stack_a)
{
	if (is_stack_a_empty(stack_a->size))
		return (false);
	if (has_duplicate_numbers_bonus(stack_a))
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_nums	*stack_a;
	t_error	error_code;

	error_code = 0;
	if (!is_valid_argc(argc))
		return (EXIT_SUCCESS);
	stack_a = parse_nums_from_argv(&argv[1], &error_code);
	if (error_code)
		return (error_exit(stack_a));
	if (!is_valid_argv_bonus(stack_a))
		return (error_exit(stack_a));
	push_swap_checker(stack_a, &error_code);
	if (error_code)
		return (error_exit(stack_a));
	free_nums(stack_a);
	return (EXIT_SUCCESS);
}
