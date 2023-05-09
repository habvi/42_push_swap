#include <stdlib.h>
#include "deque.h"

// unlink the sentinel and add_back from the next node
void	deque_extend(t_deque *deque, t_deque *new_deque)
{
	t_deque	*new_head;
	t_deque	*new_tail;

	if (deque_is_empty(new_deque))
	{
		free(new_deque);
		return ;
	}
	new_head = new_deque->next;
	new_tail = new_deque->prev;
	deque_add_back(deque, new_head);
	deque_set_prev(deque, new_tail);
	free(new_deque);
}
