#include <stdlib.h> // malloc
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
