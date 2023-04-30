#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	append_op(t_nums *op_deque, t_operation op, t_error *error_code)
{
	t_deque	*new_node;

	new_node = deque_new_node(op, NULL, error_code);
	if (*error_code)
		return ;
	deque_add_back(op_deque->deque, new_node);
	op_deque->size += 1;
}
