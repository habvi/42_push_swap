#include <stdlib.h>
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_deque	*deque_new_node_for_block(unsigned int first, unsigned int last, t_error *error)
{
	t_deque	*node;

	node = (t_deque *)malloc(sizeof(t_deque));
	if (node == NULL)
	{
		*error = ERROR_MALLOC;
		return (NULL);
	}
	node->num = FOR_BLOCK;
	node->ptr = NULL;
	node->first = first;
	node->last = last;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static t_deque	*allocate_deque_for_block(t_data *data, t_error *error_code)
{
	t_deque	*waiting_block;
	t_deque	*new_node;

	waiting_block = deque_new_head(FOR_BLOCK, NULL, error_code);
	if (*error_code)
		return (NULL);
	new_node = deque_new_node_for_block(1, data->stack_a->size, error_code);
	if (*error_code)
		return (NULL);
	deque_add_back(waiting_block, new_node);
	deque_print(waiting_block, "wating block");
	return (waiting_block);
}

// stack dfs
t_nums	*divide_block_sort(t_data *data, t_error *error_code)
{
	t_deque	*waiting_block;

	waiting_block = allocate_deque_for_block(data, error_code);
	if (*error_code)
		return (NULL);
	deque_clear(waiting_block);
	return (data->now_op);
}
