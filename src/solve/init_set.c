#include "error.h"
#include "free.h"
#include "push_swap.h"

t_nums	*init_and_set_pointer(\
		t_deque *allocated_ptrs, size_t init_num, t_error *error_code)
{
	t_nums	*nums;

	nums = init_nums(init_num, error_code);
	if (*error_code)
		return (NULL);
	set_allocated_pointer(allocated_ptrs, T_NUMS, nums, error_code);
	if (*error_code)
	{
		free_nums(nums);
		return (NULL);
	}
	return (nums);
}
