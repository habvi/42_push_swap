#include "deque.h"
#include "error.h"

void	deque_add_back(t_deque *deque, int num, t_error *error)
{
	t_deque	*new_node;
	t_deque	*tail;

	new_node = deque_new(num, error);
	if (*error)
		return ;
	tail = deque->prev;
	deque_set_next(tail, new_node);
	deque_set_prev(new_node, tail);
	deque_set_prev(deque, new_node);
}
