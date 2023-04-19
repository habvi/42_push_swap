#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"
#include "push_swap.h"

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

t_nums	*init_nums(t_error *error_code)
{
	t_nums	*stack;

	stack = nums_new(error_code);
	if (*error_code)
		return (NULL);
	stack->deque = deque_new_head(0, NULL, error_code);
	if (*error_code)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
