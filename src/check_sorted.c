#include "array.h"
#include "deque.h"
#include "error.h"
#include "push_swap.h"

bool	is_stack_a_already_sorted(t_nums *nums, int **array, t_error *error_code)
{
	if (deque_is_empty(nums->deque))
		return (true);
	*array = copy_to_array(nums, error_code);
	if (*error_code)
		return (false);
	print_array(*array, nums->size, "array"); // to do: erase
	// sort_array(array);
	// if (is_sorted(array, nums))
	// 	return (true);
	return (false);
}
