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

static bool	is_stack_a_sorted(t_nums *nums, int *array)
{
	t_deque	*node;
	size_t	i;

	node = nums->deque->next;
	i = 0;
	while (i < nums->size)
	{
		if (node->num != array[i])
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}

bool	is_valid_nums(t_nums *nums, int **array, t_error *error_code)
{
	if (is_stack_a_empty(nums->size))
		return (false);
	*array = copy_to_array(nums, error_code);
	if (*error_code)
		return (false);
	sort_array(*array, nums->size);
	if (is_duplicate_numbers(*array, nums->size, error_code))
		return (false);
	if (is_stack_a_sorted(nums, *array))
		return (false);
	return (true);
}
