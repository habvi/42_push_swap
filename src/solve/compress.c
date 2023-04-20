#include "libft.h"
#include "deque.h"
#include "push_swap.h"

static size_t	get_sorted_index(int num, int *sorted_array, size_t array_size)
{
	ssize_t	ng_idx;
	ssize_t	ok_idx;
	ssize_t	middle_idx;

	ng_idx = -1;
	ok_idx = array_size;
	while (ft_abs(ok_idx - ng_idx) > 1)
	{
		middle_idx = (ok_idx + ng_idx) / 2;
		if (sorted_array[middle_idx] >= num)
			ok_idx = middle_idx;
		else
			ng_idx = middle_idx;
	}
	return (ok_idx);
}

static void	compress_sorted_array(size_t size, int *sorted_array)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		sorted_array[i] = i + 1;
		i++;
	}
}

t_nums	*compress_number(t_nums *stack_a, int *sorted_array)
{
	t_deque	*node;
	size_t	sorted_index;

	node = stack_a->deque->next;
	while (node)
	{
		sorted_index = get_sorted_index(node->num, sorted_array, stack_a->size);
		node->num = sorted_index + 1;
		node = node->next;
	}
	compress_sorted_array(stack_a->size, sorted_array);
	return (stack_a);
}
