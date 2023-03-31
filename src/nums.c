#include <stdlib.h> // malloc
#include "push_swap.h"
#include "error.h"

t_nums	*nums_new(t_error *error_code)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	nums->deque = NULL;
	nums->size = 0;
	return (nums);
}

bool	is_valid_nums(t_nums *nums, t_error *error_code)
{
	(void)nums;
	(void)error_code;
	// if not
	// *error_code = ERROR_ARGS;
	return (true);
}
