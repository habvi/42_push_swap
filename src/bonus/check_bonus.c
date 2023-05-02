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

void	check_op(t_nums *stack_a, t_error *error_code)
{
	t_nums		*op;
	char		*line;
	t_result	result;
	t_deque		*new_node;
	t_operation	op_i;

	deque_print(stack_a->deque, "stackA");
	op = init_nums(0, error_code);
	if (*error_code)
		return ;
	result = OK;
	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		printf("%s", line);
		if (line == NULL)
			break ;
		if (!is_valid_op(line))
		{
			result = KO;
			free(line);
			break ;
		}
		op_i = get_op_i(line);
		new_node = deque_new_node(op_i, NULL, error_code);
		if (*error_code)
		{
			result = KO;
			free(line);
			break ;
		}
		deque_add_back(op->deque, new_node);
		free(line);
	}
	if (result == OK)
		result = sort_and_judge(stack_a, op, error_code);
	free_nums(op);
	put_result(result);
}
