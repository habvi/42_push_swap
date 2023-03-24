#include "deque.h"

void	deque_init(t_deque *deque)
{
	deque->num = 0;
	deque->next = NULL;
	deque->prev = NULL;
}
