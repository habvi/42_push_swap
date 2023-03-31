#include "array.h"
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include <stdio.h> // to do: erase

static void	swap(int **array, size_t i, size_t min_index)
{
	int	tmp;

	tmp = (*array)[i];
	(*array)[i] = (*array)[min_index];
	(*array)[min_index] = tmp;
}

static void	sort_array(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		min_num;
	size_t	min_index;

	i = 0;
	while (i < size)
	{
		min_num = array[i];
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < min_num)
			{
				min_num = array[j];
				min_index = j;
			}
			j++;
		}
		swap(&array, i, min_index);
		i++;
	}
}

static bool	is_sorted(t_nums *nums, int *array)
{
	t_deque	*node;
	size_t	i;

	node = nums->deque->next;
	i = 0;
	while (i < nums->size)
	{
		if (node->num != array[i])
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}

bool	is_stack_a_sorted(t_nums *nums, int **array, t_error *error_code)
{
	*array = copy_to_array(nums, error_code);
	if (*error_code)
		return (false);
	print_array(*array, nums->size, "array before"); // to do: erase
	sort_array(*array, nums->size);
	print_array(*array, nums->size, "array after "); // to do: erase
	if (is_sorted(nums, *array))
		return (true);
	return (false);
}
