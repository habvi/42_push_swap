#include <stdlib.h> // free
#include "deque.h"
#include "error.h"

bool	deque_is_empty(t_deque *deque)
{
	if (deque == deque->next)
		return (true);
	return (false);
}

void	deque_append(t_deque *deque, int num, t_error *error)
{
	t_deque	*new_node;
	t_deque	*tail;

	new_node = deque_new(num, error);
	if (*error)
		return ;
	if (deque_is_empty(deque))
	{
		new_node->prev = deque;
		deque->next = new_node;
		deque->prev = new_node;
	}
	else
	{
		tail = deque->prev;
		tail->next = new_node;
		deque->prev = new_node;
		new_node->prev = tail;
	}
}
