#include <stdlib.h> // free
#include "deque.h"
#include "error.h"
#include "free.h"
#include "operations.h"
#include "push_swap.h"

t_nums	*init_stack(t_error *error_code)
{
	t_nums	*stack;

	stack = nums_new(error_code);
	if (*error_code)
		return (NULL);
	stack->deque = deque_new_head(0, error_code);
	if (*error_code)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	solve(t_nums *nums, int *sorted_array, t_error *error_code)
{
	t_nums	*stack_a;
	t_nums	*stack_b;

	stack_a = nums;
	stack_b = init_stack(error_code);
	if (*error_code)
		return ;
	stack_a = compress_number(stack_a, sorted_array);

	// test
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB"); // to do: erase
	sa(stack_a);
	sb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB"); // to do: erase
	ss(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB"); // to do: erase

	free_nums(stack_b);
}
