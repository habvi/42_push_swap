#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static int	get_move_num(t_stack_place stack_place, t_data *data)
{
	if (stack_place == STACK_A_HEAD)
		return (data->stack_a->deque->next->num);
	if (stack_place == STACK_A_TAIL)
		return (data->stack_a->deque->prev->num);
	if (stack_place == STACK_B_HEAD)
		return (data->stack_a->deque->next->num);
	if (stack_place == STACK_B_TAIL)
		return (data->stack_a->deque->prev->num);
	return (NONE);
}

t_nums	*move_for_divide_nums(t_block *block, const unsigned int nums_range, t_data *data, t_error *error_code)
{
	uint8_t	i;
	int		num;

	i = 0;
	while (i < nums_range)
	{
		num = get_move_num(block->stack_place, data);
		printf("%d\n", num);
		i++;
	}
	(void)error_code;
	return (data->now_op);
}
