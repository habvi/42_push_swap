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

	op_i = get_op_num(line);
	new_node = deque_new_node(op_i, NULL, error_code);
	if (*error_code)
		return (NULL);
	deque_add_back(op->deque, new_node);
	return (op);
}

static void	read_and_add_valid_op(t_nums *ops, t_error *error_code)
{
	char	*saved;
	char	*line;

	saved = NULL;
	while (true)
	{
		line = get_next_line(STDIN_FILENO, &saved, error_code);
		if (*error_code)
		{
			free(line);
			return ;
		}
		if (line == NULL)
			return ;
		if (!is_valid_op(line, error_code))
		{
			free(saved);
			free(line);
			return ;
		}
		ops = add_back_new_op(ops, line, error_code);
		free(line);
		if (*error_code)
			return ;
	}
}

void	push_swap_checker(t_nums *stack_a, t_error *error_code)
{
	t_nums	*ops;

	ops = init_nums(0, error_code);
	if (*error_code)
		return ;
	read_and_add_valid_op(ops, error_code);
	if (*error_code)
	{
		free_nums(ops);
		return ;
	}
	move_op(stack_a, ops, error_code);
	free_nums(ops);
	if (*error_code)
		return ;
	if (is_stack_a_sorted_bonus(stack_a))
		put_result(OK_MSG);
	else
		put_result(KO_MSG);
}
