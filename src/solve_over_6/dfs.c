#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

// static bool	is_dfs_end(t_block *block, t_data *data, t_error *error_code)
// {
// 	(void)block;
// 	(void)data;
// 	(void)error_code;
// 	return (true);
// }

t_nums	*last_nums_dfs(t_block *block, t_data *data, t_error *error_code)
{
	// unsigned int	i;

	// if (is_dfs_end(block, data, error_code))
	// 	return (data->now_op);
	// i = 0;
	// while (i < TOTAL_OPERATIONS)
	// {
	// 	if (!is_unnecessary_op())
	// 	{
	// 		i++;
	// 		continue ;
	// 	}
	// 	run_operation(RUN);
	// 	data->now_op = last_nums_dfs();
	// 	run_operation(UNDO);
	// 	i++;
	// }
	// return (min_op);
	(void)block;
	(void)error_code;
	return (data->now_op);
}