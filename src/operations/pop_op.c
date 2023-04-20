#include "deque.h"
#include "push_swap.h"
#include "solve.h"

void	pop_now_op(t_nums *now_op)
{
	t_deque	*pop_node;

	pop_node = deque_pop_back(now_op->deque);
	deque_clear(pop_node);
	now_op->size -= 1;
}
