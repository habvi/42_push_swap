#include "array.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

void	push_swap(t_nums *nums, t_error *error_code)
{
	int	*array;

	if (deque_is_empty(nums->deque))
		return ;
	array = copy_to_array(nums, error_code);
	if (*error_code)
		return ;
	print_array(array, nums->size); // to do: erase
	// ↓↓ need free_array()
	// sort_array(array);
	// if (is_stack_a_already_sorted(array, nums))
	// 	return (free_array(array, true));
	// compress();
	// solve();
	free_array(array);
}
