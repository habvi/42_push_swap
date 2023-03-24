#include <stdlib.h>
#include "deque.h"

void	deque_clear(t_deque *deque)
{
	t_deque	*node;
	t_deque	*tmp;

	node = deque->next;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	deque->next = NULL;
	deque->prev = NULL;
}
