#include <stdlib.h> // malloc
#include "push_swap.h"
#include "error.h"

t_nums	*nums_new(t_error *error)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
	{
		*error = ERROR_MALLOC;
		return (NULL);
	}
	nums->deque = NULL;
	nums->size = 0;
	return (nums);
}

bool	is_valid_nums(t_nums *nums, t_error *error)
{
	(void)nums;
	(void)error;
	// if not
	// *error = ERROR_ARGS;
	return (true);
}
