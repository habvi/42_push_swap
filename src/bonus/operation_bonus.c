#include <stdint.h>
#include "libft.h"
#include "checker_bonus.h"
#include "operations.h"

bool	is_valid_op(const char *line)
{
	static const char	*ops[] = {"sa\n", "sb\n", "ss\n", \
								"pa\n", "pb\n", \
								"ra\n", "rb\n", "rr\n", \
								"rra\n", "rrb\n", "rrr\n", NULL};
	t_operation			i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(line, ops[i], ft_strlen(line)) == SAME_STRING)
			return (true);
		i++;
	}
	return (false);
}

t_operation	get_op_index(const char *op)
{
	static const char	*ops[] = {"sa\n", "sb\n", "ss\n", \
								"pa\n", "pb\n", \
								"ra\n", "rb\n", "rr\n", \
								"rra\n", "rrb\n", "rrr\n", NULL};
	t_operation			i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(op, ops[i], ft_strlen(op)) == SAME_STRING)
			return (i + 1);
		i++;
	}
	return (0);
}
