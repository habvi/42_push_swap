#include "deque.h"

void	deque_init(t_deque *deque, int num)
{
	deque->num = num;
	deque->next = deque;
	deque->prev = deque;
}
