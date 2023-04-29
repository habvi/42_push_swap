#include <stdlib.h>
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

t_block	init_block(void)
{
	t_block			block;
	unsigned int	i;

	block.wait_blocks = NULL;
	block.block_range = NULL;
	i = 0;
	while (i + 1 < TOTAL_STACK_ENTRY)
	{
		block.movable_stack_place[i] = 0;
		i++;
	}
	i = 0;
	while (i < OTHER_STACK_NUMS_RANGE)
	{
		block.nums_range_per_blocks[i] = 0;
		i++;
	}
	block.base_block_size = 0;
	block.total_block_count = 0;
	return (block);
}

static t_deque	*deque_new_node_for_block(\
					unsigned int first, unsigned int last, t_error *error)
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

t_deque	*allocate_deque_for_block(t_data *data, t_error *error_code)
{
	t_deque	*wait_blocks;
	t_deque	*new_node;

	wait_blocks = deque_new_head(FOR_BLOCK, NULL, error_code);
	if (*error_code)
		return (NULL);
	new_node = deque_new_node_for_block(1, data->stack_a->size, error_code);
	if (*error_code)
		return (NULL);
	deque_add_back(wait_blocks, new_node);
	deque_print(wait_blocks, "wating block"); // to do: erase
	deque_print4(data); // to do: erase
	return (wait_blocks);
}
