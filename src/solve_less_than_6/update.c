#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

static t_nums	*dup_nums(t_nums *nums, t_error *error_code)
{
	t_nums	*dup_nums;
	t_deque	*node;
	t_deque	*new_node;

	dup_nums = init_nums(nums->size, error_code);
	if (*error_code)
		return (NULL);
	node = nums->deque->next;
	while (node)
	{
		new_node = deque_new_node(node->num, NULL, error_code);
		deque_add_back(dup_nums->deque, new_node);
		node = node->next;
	}
	return (dup_nums);
}

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
