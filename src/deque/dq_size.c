#include "deque.h"
#include <stdio.h>

size_t	dq_size(t_deque *deque)
{
	t_deque	*head;
	size_t	size;

	size = 0;
	if (deque_is_empty(deque))
		return (size);
	head = deque->next;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
