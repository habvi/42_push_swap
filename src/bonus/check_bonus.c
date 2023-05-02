#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h> // free
#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "get_next_line_bonus.h"
#include "operations.h"
#include "push_swap.h"

static bool	is_valid_op(const char *line)
{
	static const char	*ops[] = {"sa\n", "sb\n", "ss\n", \
								"pa\n", "pb\n", \
								"ra\n", "rb\n", "rr\n", \
								"rra\n", "rrb\n", "rrr\n", NULL};
	uint8_t				i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(line, ops[i], MAX_OP_LEN) == 0)
			return (true);
		i++;
	}
	return (false);
}

static t_operation	get_op_i(const char *op)
{
	static const char	*ops[] = {"sa\n", "sb\n", "ss\n", \
								"pa\n", "pb\n", \
								"ra\n", "rb\n", "rr\n", \
								"rra\n", "rrb\n", "rrr\n", NULL};
	uint8_t				i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(op, ops[i], MAX_OP_LEN) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

void	check_op(t_nums *stack_a, t_error *error_code)
{
	t_nums		*op;
	char		*line;
	t_result	result;
	t_deque		*new_node;
	int			op_i;

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
		result = sort_and_judge(stack_a, op);
	free_nums(op);
	put_result(result);
}
