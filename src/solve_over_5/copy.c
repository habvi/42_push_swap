#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

int	*alloc_and_copy_stack_a(t_nums *stack_a, t_error *error_code)
{
	int		*array_a;
	t_deque	*node;
	size_t	i;

	array_a = (int *)malloc(sizeof(int) * stack_a->size);
	if (array_a == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	node = stack_a->deque->next;
	i = 0;
	while (i < stack_a->size)
	{
		array_a[i] = node->num;
		node = node->next;
		i++;
	}
	return (array_a);
}
