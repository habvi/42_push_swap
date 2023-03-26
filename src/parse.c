#include <stdlib.h> // malloc, free
#include "push_swap.h"
#include "error.h"
#include "libft.h"

void	strs_to_deque(char **strs, t_deque *deque, t_error *error)
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
			*error = ERROR_ARGS;
			return ;
		}
		new_node = deque_new(num, error);
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

t_deque	set_argv_to_deque(char *const *argv, t_error *error)
{
	t_deque	deque;
	size_t	i;
	char	**strs;

	deque_init(&deque, 0, &deque);
	i = 0;
	while (argv[i])
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
		{
			*error = ERROR_MALLOC;
			return (deque);
		}
		strs_to_deque(strs, &deque, error);
		free_all(strs);
		if (*error)
			return (deque);
		i++;
	}
	// convert_to_integer();
	return (deque);
}

size_t	count_deque_len(t_deque deque)
{
	t_deque	*head;
	size_t	len;

	if (deque_is_empty(&deque))
		return (0);
	head = deque.next;
	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

bool	is_valid_nums(t_nums *nums)
{
	(void)nums;
	return (true);
}

t_nums	*parse_nums_from_argv(char *const *argv, t_error *error)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
	{
		*error = ERROR_MALLOC;
		return (NULL);
	}
	nums->deque = set_argv_to_deque(argv, error);
	if (*error)
	{
		free_nums(nums);
		return (NULL);
	}
	nums->size = count_deque_len(nums->deque);
	printf("deque size : %zu\n", nums->size);
	if (!is_valid_nums(nums))
	{
		*error = ERROR_ARGS;
		free_nums(nums);
		return (NULL);
	}
	deque_print(&nums->deque);
	return (nums);
}
