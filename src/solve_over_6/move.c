#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static int	get_move_num(t_stack_place stack_place, t_data *data)
{
	if (stack_place == STACK_A_HEAD)
		return (data->stack_a->deque->next->num);
	if (stack_place == STACK_A_TAIL)
		return (data->stack_a->deque->prev->num);
	if (stack_place == STACK_B_HEAD)
		return (data->stack_b->deque->next->num);
	if (stack_place == STACK_B_TAIL)
		return (data->stack_b->deque->prev->num);
	return (STACK_NONE);
}

static t_nums	*move_nums(\
			t_block *block, unsigned int i, t_data *data, t_error *error_code)
{
	const int	before_place = block->stack_place;
	const int	after_place = block->movable_stack_place[i];

	if (before_place == STACK_A_HEAD)
		data->now_op = move_from_stack_a_head(after_place, data, error_code);
	else if (before_place == STACK_A_TAIL)
		data->now_op = move_from_stack_a_tail(after_place, data, error_code);
	else if (before_place == STACK_B_HEAD)
		data->now_op = move_from_stack_b_head(after_place, data, error_code);
	else if (before_place == STACK_B_TAIL)
		data->now_op = move_from_stack_b_tail(after_place, data, error_code);
	if (*error_code)
		return (NULL);
	return (data->now_op);
}

/* to do
index: 0 1 2 3 4 5 6
       1 2 3 4 5 6 0
       1 2 3 4 0
*/
t_nums	*move_for_divide_nums(t_block *block, const unsigned int nums_range, \
								t_data *data, t_error *error_code)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	int				total;
	int				num;

	i = 0;
	while (i < nums_range)
	{
		num = get_move_num(block->stack_place, data);
		total = block->total_block_count;
		k = 0;
		while (total)
		{
			j = (total - 1) * 2;
			if (is_num_in_range(num, \
								block->nums_range_per_blocks[j], \
								block->nums_range_per_blocks[j + 1]))
			{
				data->now_op = move_nums(block, k, data, error_code);
				if (*error_code)
					return (NULL);
				break ;
			}
			total--;
			k++;
		}
		i++;
	}
	return (data->now_op);
}
