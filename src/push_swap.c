#include "check.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

void	push_swap(t_nums *nums, t_error *error_code)
{
	int	*array;

	if (deque_is_empty(nums->deque))
		return ;
	if (is_stack_a_sorted(nums, &array, error_code)) // ↓↓ need free_array()
	{
		free_array(array);
		return ;
	}
	// compress();
	// solve();
	free_array(array);
}
