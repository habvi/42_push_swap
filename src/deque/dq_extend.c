#include <stdlib.h>
#include "deque.h"

void	deque_extend(t_deque *deque, t_deque *new_deque)
{
	t_deque	*tail;
	t_deque	*new_head;
	t_deque	*new_tail;

	if (deque_is_empty(new_deque))
	{
		free(new_deque);
		return ;
	}
	tail = deque->prev;
	new_head = new_deque->next;
	new_tail = new_deque->prev;
	deque_set_next(tail, new_head);
	deque_set_prev(new_head, tail);
	deque_set_prev(deque, new_tail);
	free(new_deque);
}
