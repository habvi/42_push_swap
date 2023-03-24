#include <stdlib.h> // free
#include "deque.h"
#include "error.h"

bool	deque_is_empty(t_deque deque)
{
	if (deque.next == NULL)
	{
		return (true);
	}
	return (false);
}

void	deque_append(t_deque *deque, int num, t_error *error)
{
	t_deque	*node;
	t_deque	*tail;

	node = deque_new(num, error);
	if (*error)
		return ;
	if (deque_is_empty(*deque))
	{
		node->prev = deque;
		deque->next = node;
		deque->prev = node;
	}
	else
	{
		tail = deque->prev;
		tail->next = node;
		node->prev = tail;
		deque->prev = node;
	}
}
