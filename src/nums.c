#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"
#include "push_swap.h"

t_nums	*nums_new(size_t init_size, t_error *error_code)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	nums->deque = NULL;
	nums->size = init_size;
	return (nums);
}

t_nums	*init_nums(size_t init_size, t_error *error_code)
{
	t_nums	*nums;

	nums = nums_new(init_size, error_code);
	if (*error_code)
		return (NULL);
	nums->deque = deque_new_head(0, NULL, error_code);
	if (*error_code)
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
