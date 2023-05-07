#include <limits.h>
#include "libft.h"
#include "get_next_line_bonus.h"
#include "error.h"

bool	is_valid_args(const int fd, t_error *error_code)
{
	if (fd < 0 || fd >= MY_OPEN_MAX || \
		BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
	{
		*error_code = ERROR_GNL;
		return (false);
	}
	return (true);
}

bool	is_new_line(char *str)
{
	if (str == NULL)
		return (false);
	while (*str)
	{
		if (*str == LF)
			return (true);
		str++;
	}
	return (false);
}

char	*erase_last_new_line(char *line)
{
	const size_t	len = ft_strlen(line);

	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
