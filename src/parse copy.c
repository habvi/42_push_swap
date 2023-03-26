#include <stdlib.h> // malloc, free
#include "push_swap.h"
#include "error.h"
#include "libft.h"

// erase
// static void	print_and_free_split_str(char **str)
// {
// 	int		num;
// 	bool	res;
// 	size_t	i;

// 	num = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		res = ft_atoi_for_pushswap(str[i], &num);
// 		printf("[%s] : %d [%d]\n", str[i], res, num);
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// static size_t	count_strs_length(char **str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

void	strs_to_deque(char **strs, t_deque *deque, t_error *error)
{
	size_t	i;
	t_deque	*new_node;
	bool	result;
	int		num;

	i = 0;
	while (strs[i])
	{
		printf("==================================\n");
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

// void	print_strs(char **strs)
// {
// 	size_t	i;

// 	i = 0;
// 	while (strs[i])
// 	{
// 		printf("[%s]\n", strs[i]);
// 		i++;
// 	}
// }

t_deque set_argv_to_deque(char *const *argv, t_error *error)
{
	t_deque	deque;
	size_t	i;
	char	**strs;

	deque_init(&deque, 0, &deque);
	printf("is_empty 1-1: %d\n", deque_is_empty(&deque));
	i = 0;
	while (argv[i])
	{
		// if (*argv[i] == '\0')
		// {
		// 	i++;
		// 	continue ;
		// }
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
		{
			*error = ERROR_MALLOC;
			return (deque);
		}
		// print_strs(strs);
		strs_to_deque(strs, &deque, error);
		free_all(strs);
		if (*error)
			return (deque);
		i++;
	}
	// convert_to_integer();
	printf("is_empty 1-2: %d\n", deque_is_empty(&deque));
	return (deque);
}

size_t	count_deque_len(t_deque deque)
{
	t_deque	*head;
	size_t	len;

	if (deque_is_empty(&deque))
		return (0);
	printf("=========================\n");
	head = deque.next;
	len = 0;
	while(head)
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
	printf("is_empty 2: %d\n", deque_is_empty(&(nums->deque)));
	if (*error)
	{
		deque_clear(&nums->deque);
		free(nums);
		return (NULL);
	}
	nums->size = count_deque_len(nums->deque);
	printf("deque size : %zu\n", nums->size);
	if (!is_valid_nums(nums))
	{
		*error = ERROR_ARGS;
		deque_clear(&nums->deque);
		free(nums);
		return (NULL);
	}
	deque_print(&nums->deque);
	deque_clear(&nums->deque);
	free(nums);
	return (nums);
}
