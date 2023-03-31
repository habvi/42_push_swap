#include <stdlib.h> // malloc, free
#include "push_swap.h"
#include "deque.h"
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

void	*free_nums(t_nums *nums)
{
	deque_clear(nums->deque);
	free(nums);
	return (NULL);
}
