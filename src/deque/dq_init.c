#include "deque.h"

void	deque_init(t_deque *deque, int init_num, t_deque *init_node)
{
	if (deque->num != FOR_BLOCK)
		deque->num = init_num;
	deque->ptr = NULL;
	if (deque->num != FOR_BLOCK)
	{
		deque->first = 0;
		deque->last = 0;
	}
	deque->next = init_node;
	deque->prev = init_node;
}
