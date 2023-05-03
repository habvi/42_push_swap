#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h> // free
#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "get_next_line_bonus.h"
#include "operations.h"
#include "push_swap.h"

t_result	read_input(t_nums *op, t_error *error_code)
{
	char		*line;
	t_deque		*new_node;
	t_operation	op_i;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			return (OK);
		if (!is_valid_op(line))
		{
			free(line);
			return (ERROR);
		}
		op_i = get_op_index(line);
		new_node = deque_new_node(op_i, NULL, error_code);
		if (*error_code)
		{
			free(line);
			return (RESULT_NONE);
		}
		deque_add_back(op->deque, new_node);
		free(line);
	}
	return (OK);
}

void	check_op(t_nums *stack_a, int *sorted_a, t_error *error_code)
{
	t_nums		*op;
	t_result	result;

	op = init_nums(0, error_code);
	if (*error_code)
		return ;
	result = read_input(op, error_code);
	if (result == OK)
		result = sort_and_judge(stack_a, op, sorted_a, error_code);
	free_nums(op);
	free(sorted_a);
	put_result(result);
}
