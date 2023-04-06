#include "deque.h"
#include "push_swap.h"

// to do: bisect?
static size_t	get_sorted_index(int num, int *array, size_t array_size)
{
	size_t	i;

	i = 0;
	while (i < array_size)
	{
		if (array[i] == num)
			return (i + 1);
		i++;
	}
	return (0);
}

t_nums	*compress_number(t_nums *nums, int *array)
{
	t_deque	*node;
	size_t	i;
	size_t	sorted_index;

	node = nums->deque->next;
	i = 0;
	while (i < nums->size)
	{
		sorted_index = get_sorted_index(node->num, array, nums->size);
		node->num = sorted_index;
		node = node->next;
		i++;
	}
	return (nums);
}
