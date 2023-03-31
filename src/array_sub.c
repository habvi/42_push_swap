#include <stdlib.h> // free
#include "push_swap.h"

void	print_array(int *array, size_t size)
{
	size_t	i;

	printf("[array : ");
	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("]\n");
}

bool	free_array(int *array, bool ret)
{
	free(array);
	return (ret);
}

void	free_all(int *array, t_nums *nums)
{
	free(array);
	free_nums(nums);
}
