#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include "error.h"

static void	*ft_free(char **saved, char *ps)
{
	if (*saved != NULL)
	{
		free(*saved);
		*saved = NULL;
	}
	if (ps != NULL)
		free(ps);
	return (NULL);
}

static char	*read_buf(\
				char **saved, int fd, bool *finish_read, t_error *error_code)
{
	char	*buf;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		*error_code = ERROR_GNL;
		return (NULL);
	}
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == READ_ERROR)
	{
		*error_code = ERROR_GNL;
		return (ft_free(saved, buf));
	}
	buf[read_size] = '\0';
	if (read_size < BUFFER_SIZE)
		*finish_read = true;
	return (buf);
}

static void	*set_error_and_free(char **saved, char *ps)
{
	ft_free(saved, ps);
	return (NULL);
}

static char	*output(char **saved, t_error *error_code)
{
	char	*ps;
	char	*left;
	char	*tail;

	ps = *saved;
	if (ps == NULL || *ps == '\0')
		return (ft_free(saved, NULL));
	while (*ps && *ps != LF)
		ps++;
	left = ft_substr_for_gnl(*saved, 0, ps - *saved + 1, error_code);
	if (left == NULL)
		return (set_error_and_free(saved, NULL));
	if (*left == '\0')
		return (ft_free(saved, left));
	tail = ps;
	while (*tail)
		tail++;
	if (*ps == LF)
		ps++;
	*saved = ft_memmove_for_gnl(*saved, ps, tail - ps + 1);
	free(*saved);
	*saved = NULL;
	return (left);
}

char	*get_next_line(int fd, t_error *error_code)
{
	static char	*saved = NULL;
	bool		finish_read;
	char		*buf;
	char		*tmp;

	if (!is_valid_args(fd, error_code))
		return (NULL);
	finish_read = false;
	while (!finish_read)
	{
		if (is_new_line(saved))
			break ;
		buf = read_buf(&saved, fd, &finish_read, error_code);
		if (buf == NULL)
			return (set_error_and_free(&saved, NULL));
		tmp = ft_strjoin(saved, buf, error_code);
		if (tmp == NULL)
			return (set_error_and_free(&saved, buf));
		ft_free(&saved, buf);
		saved = tmp;
	}
	return (output(&saved, error_code));
}
