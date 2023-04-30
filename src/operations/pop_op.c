#include "deque.h"
#include "push_swap.h"
#include "solve.h"

void	pop_op(t_nums *op)
{
	t_deque	*pop_node;

	pop_node = deque_pop_back(op->deque);
	deque_clear(pop_node);
	op->size -= 1;
}
