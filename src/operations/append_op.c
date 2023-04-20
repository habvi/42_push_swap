#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	append_now_op(t_data *data, t_operation op, t_error *error_code)
{
	t_deque	*new_node;

	new_node = deque_new_node(op, NULL, error_code);
	if (*error_code)
		return ;
	deque_add_back(data->now_op->deque, new_node);
	data->now_op->size += 1;
}
