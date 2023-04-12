#include "push_swap.h"

static void	swap(int *array, size_t i, size_t min_index)
{
	int	tmp;

	tmp = array[i];
	array[i] = array[min_index];
	array[min_index] = tmp;
}

void	sort_array(int *array, size_t size)
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
		swap(array, i, min_index);
		i++;
	}
}
