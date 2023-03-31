#include <stdlib.h> // free
#include "deque.h"
#include "free.h"
#include "push_swap.h"

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

void	free_all(int *array, t_nums *nums)
{
	free(array);
	free_nums(nums);
}
