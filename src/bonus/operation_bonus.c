#include "libft.h"
#include "checker_bonus.h"
#include "error.h"
#include "operations.h"

t_operation	get_op_num(const char *op)
{
	static const char	*ops[] = {"sa\n", "sb\n", "ss\n", \
								"pa\n", "pb\n", \
								"ra\n", "rb\n", "rr\n", \
								"rra\n", "rrb\n", "rrr\n", NULL};
	t_operation			i;

	i = 0;
	while (ops[i])
	{
		if (ft_strcmp(op, ops[i]) == SAME_STRING)
			return (i + 1);
		i++;
	}
	return (OP_NONE);
}

bool	is_valid_op(const char *line, t_error *error_code)
{
	const t_operation	op = get_op_num(line);

	if (op == OP_NONE)
	{
		*error_code = ERROR_GNL;
		return (false);
	}
	return (true);
}
