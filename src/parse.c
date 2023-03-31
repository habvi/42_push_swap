#include <stdlib.h> // free
#include "push_swap.h"
#include "deque.h"
#include "error.h"
#include "libft.h"

void	add_strs_to_deque(char **strs, t_deque *deque, t_error *error_code)
{
	size_t	i;
	t_deque	*new_node;
	bool	result;
	int		num;

	i = 0;
	while (strs[i])
	{
		result = ft_atoi_for_pushswap(strs[i], &num);
		if (!result)
		{
			*error_code = ERROR_ARGS;
			return ;
		}
		new_node = deque_new(num, error_code);
		if (new_node == NULL)
			return ;
		deque_add_back(deque, new_node);
		i++;
	}
}

void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

t_deque	*set_argv_to_deque(char *const *argv, t_error *error_code)
{
	t_deque	*deque;
	size_t	i;
	char	**strs;

	deque = deque_init_head(0, error_code);
	if (deque == NULL)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
		{
			*error_code = ERROR_MALLOC;
			return (deque);
		}
		add_strs_to_deque(strs, deque, error_code);
		free_all(strs);
		if (*error_code)
			return (deque);
		i++;
	}
	// convert_to_integer();
	return (deque);
}

t_nums	*parse_nums_from_argv(char *const *argv, t_error *error_code)
{
	t_nums	*nums;

	nums = nums_new(error_code);
	if (*error_code)
		return (nums);
	nums->deque = set_argv_to_deque(argv, error_code);
	if (*error_code)
		return (nums);
	nums->size = deque_size(nums->deque);
	deque_print(nums->deque); // to do: erase
	return (nums);
}
