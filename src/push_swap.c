#include "check.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

void	push_swap(t_nums *nums, t_error *error_code)
{
	int	*array;

	if (is_stack_a_already_sorted(nums, &array, error_code))
		return ;
	// ↓↓ need free_array()
	// compress();
	// solve();
	free_array(array);
}
