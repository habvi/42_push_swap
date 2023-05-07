#include "array.h"
#include "error.h"
#include "deque.h"
#include "push_swap.h"

static bool	is_stack_a_empty(size_t	size)
{
	if (size)
		return (false);
	return (true);
}

static bool	is_duplicate_numbers(\
			int *sorted_array, size_t array_size, t_error *error_code)
{
	size_t	i;

	i = 0;
	while (i + 1 < array_size)
	{
		if (sorted_array[i] == sorted_array[i + 1])
		{
			*error_code = ERROR_ARGS;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	has_valid_stack_nums(\
	t_nums *stack, int **array, t_deque *allocated_ptrs, t_error *error_code)
{
	if (is_stack_a_empty(stack->size))
		return (false);
	*array = copy_to_array_and_set(stack, allocated_ptrs, error_code);
	if (*error_code)
		return (false);
	sort_array(*array, stack->size);
	if (is_duplicate_numbers(*array, stack->size, error_code))
		return (false);
	return (true);
}
