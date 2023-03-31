#include <stdlib.h> // free
#include "deque.h"
#include "free.h"
#include "push_swap.h"

void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	*free_nums(t_nums *nums)
{
	deque_clear(nums->deque);
	free(nums);
	return (NULL);
}

void	free_array(int *array)
{
	free(array);
}
