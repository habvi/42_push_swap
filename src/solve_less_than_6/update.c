#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

void	update_answer(t_data *data, t_error *error_code)
{
	t_nums	*tmp;
	t_deque	*node;

	tmp = dup_nums(data->now_op, error_code);
	if (*error_code)
		return ;
	node = data->allocated_ptrs->next;
	while (node)
	{
		if (node->ptr == data->answer)
		{
			node->ptr = tmp;
			break ;
		}
		node = node->next;
	}
	free_nums(data->answer);
	data->answer = tmp;
	data->answer->size = data->now_op->size;
}

void	update_min_op(t_data *data, t_error *error_code)
{
	t_nums	*tmp;

	tmp = dup_nums(data->tmp_op, error_code);
	if (*error_code)
		return ;
	free_nums(data->min_op);
	data->min_op = tmp;
	data->min_op->size = data->tmp_op->size;
}
