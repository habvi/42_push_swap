#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"
#include "push_swap.h"

static int	*allocate_array(\
			size_t size, t_deque *allocated_ptrs, t_error *error_code)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	set_allocated_pointer(allocated_ptrs, POINTER_1D, array, error_code);
	return (array);
}

static void	copy_stack_a_to_array(t_nums *stack, int *array)
{
	t_deque	*stack_a;
	size_t	size;
	size_t	i;

	stack_a = stack->deque->next;
	size = stack->size;
	i = 0;
	while (i < size)
	{
		array[i] = stack_a->num;
		stack_a = stack_a->next;
		i++;
	}
}

int	*copy_to_array(t_nums *stack, t_deque *allocated_ptrs, t_error *error_code)
{
	int	*array;

	array = allocate_array(stack->size, allocated_ptrs, error_code);
	if (*error_code)
		return (NULL);
	copy_stack_a_to_array(stack, array);
	return (array);
}
