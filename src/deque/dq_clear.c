#include <stdlib.h>
#include "deque.h"

void	deque_clear(t_deque *deque)
{
	t_deque	*tmp;

	if (deque_is_empty(deque))
	{
		free(deque);
		return ;
	}
	while (deque)
	{
		tmp = deque;
		deque = deque->next;
		free(tmp);
	}
}
