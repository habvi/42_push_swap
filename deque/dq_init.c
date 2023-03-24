#include "deque.h"

void	deque_init(t_deque *deque)
{
	deque->num = 0;
	deque->next = deque;
	deque->prev = deque;
}
