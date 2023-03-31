#include "push_swap.h"
#include "deque.h"
#include "array.h"
#include "error.h"

bool	push_swap(t_nums *nums, t_error *error_code)
{
	int	*array;

	if (deque_is_empty(nums->deque))
		return (true);
	array = copy_to_array(nums, error_code);
	if (*error_code)
		return (free_array(array, false));
	print_array(array, nums->size);
	// sort_array(array);
	// if (is_stack_a_already_sorted(array, nums))
	// 	return (free_array(array, true));
	// compress();
	// solve();
	free_all(array, nums);
	return (true);
}
