#include "libft.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

static int	convert_str_to_integer(char *str, t_error *error_code)
{
	int		num;
	bool	result;

	result = ft_atoi_for_pushswap(str, &num);
	if (!result)
		*error_code = ERROR_ARGS;
	return (num);
}

static void	add_strs_to_deque(char **strs, t_deque *deque, t_error *error_code)
{
	size_t	i;
	t_deque	*new_node;
	int		num;

	if (strs[0] == NULL)
	{
		*error_code = ERROR_ARGS;
		return ;
	}
	i = 0;
	while (strs[i])
	{
		num = convert_str_to_integer(strs[i], error_code);
		if (*error_code)
			return ;
		new_node = deque_new_node(num, NULL, error_code);
		if (*error_code)
			return ;
		deque_add_back(deque, new_node);
		i++;
	}
}

static char	**split_strs(char *strs, t_error *error_code)
{
	char	**split_strs;

	split_strs = ft_split(strs, ' ');
	if (split_strs == NULL)
		*error_code = ERROR_MALLOC;
	return (split_strs);
}

static t_deque	*set_argv_to_deque(\
				char *const *argv, t_deque *deque, t_error *error_code)
{
	size_t	i;
	char	**strs;

	i = 0;
	while (argv[i])
	{
		strs = split_strs(argv[i], error_code);
		if (*error_code)
			return (deque);
		add_strs_to_deque(strs, deque, error_code);
		free_strs(strs);
		if (*error_code)
			return (deque);
		i++;
	}
	return (deque);
}

t_nums	*parse_nums_from_argv(char *const *argv, t_error *error_code)
{
	t_nums	*nums;

	nums = init_nums(0, error_code);
	if (*error_code)
		return (nums);
	set_argv_to_deque(argv, nums->deque, error_code);
	if (*error_code)
		return (nums);
	nums->size = deque_size(nums->deque);
	return (nums);
}
