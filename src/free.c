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

void	free_by_each_types(t_type type, void *ptr)
{
	if (type == POINTER_1D)
		free(ptr);
	else if (type == T_DEQUE)
		deque_clear((t_deque *)ptr);
	else if (type == T_NUMS)
		free_nums((t_nums *)ptr);
}

void	*free_all_pointers(t_deque *deque)
{
	t_deque	*tmp;

	if (deque_is_empty(deque))
	{
		free(deque);
		return (NULL);
	}
	while (deque)
	{
		free_by_each_types(deque->num, deque->ptr);
		tmp = deque;
		deque = deque->next;
		free(tmp);
	}
	return (NULL);
}
