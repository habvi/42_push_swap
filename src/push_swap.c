#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

void	push_swap(t_nums *nums, t_error *error_code)
{
	int	*array;

	array = NULL;
	if (!is_valid_nums(nums, &array, error_code))
	{
		free_array(array);
		return ;
	}
	solve(nums, array);
	free_array(array);
}
