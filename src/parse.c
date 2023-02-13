#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h> // todo

// erase
static void	print_and_free_split_str(char **str)
{
	int		num;
	bool	res;
	size_t	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		res = ft_atoi_with_bool(str[i], &num);
		printf("[%s] : %d [%d]\n", str[i], res, num);
		free(str[i]);
		i++;
	}
	free(str);
}

static size_t	count_strs_length(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	parse_nums_from_argv(char *const *argv, t_nums *nums)
{
	size_t	i;
	char	**strs;

	nums->size = 0;
	i = 1;
	while (argv[i])
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
			return (false);
		nums->size += count_strs_length(strs);
		print_and_free_split_str(strs);
		i++;
	}
	printf("nums size : %zu\n", nums->size);
	// set_argv_to_list();
	// nums->list = convert_to_nums();
	// compress
	return (true);
}
