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

static t_nums	*add_back_new_op(t_nums *op, char *line, t_error *error_code)
{
	t_operation	op_i;
	t_deque		*new_node;

	op_i = get_op_index(line);
	new_node = deque_new_node(op_i, NULL, error_code);
	if (*error_code)
		return (NULL);
	deque_add_back(op->deque, new_node);
	return (op);
}

t_result	read_input(t_nums *op, t_error *error_code)
{
	char	*line;

	while (true)
	{
		line = get_next_line(STDIN_FILENO, error_code);
		if (*error_code)
			return (RESULT_ERROR);
		if (line == NULL)
			break ;
		if (!is_valid_op(line))
		{
			free(line);
			return (RESULT_ERROR);
		}
		op = add_back_new_op(op, line, error_code);
		if (*error_code)
		{
			free(line);
			return (RESULT_ERROR);
		}
		free(line);
	}
	return (RESULT_OK);
}

void	check_operations(t_nums *stack_a, int *sorted_a, t_error *error_code)
{
	t_nums		*op;
	t_result	result;

	op = init_nums(0, error_code);
	if (*error_code)
		return ;
	result = read_input(op, error_code);
	if (result == RESULT_ERROR)
		return ;
	result = sort_and_judge(stack_a, op, sorted_a, error_code);
	put_result(result);
	free_nums(op);
	free(sorted_a);
}
