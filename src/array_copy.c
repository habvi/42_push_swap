#include <stdlib.h> // malloc
#include "push_swap.h"
#include "deque.h"
#include "error.h"

static int	*allocate_array(size_t size, t_error *error_code)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	return (array);
}

static void	copy_stack_a_to_array(t_nums *nums, int *array)
{
	t_deque	*stack_a;
	size_t	i;

	stack_a = nums->deque->next;
	i = 0;
	while (i < nums->size)
	{
		array[i] = stack_a->num;
		stack_a = stack_a->next;
		i++;
	}
}

int	*copy_to_array(t_nums *nums, t_error *error_code)
{
	int	*array;

	array = allocate_array(nums->size, error_code);
	if (*error_code)
		return (NULL);
	copy_stack_a_to_array(nums, array);
	return (array);
}
