#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# define MY_OPEN_MAX 1024
# define LF         '\n'
# define READ_ERROR -1

typedef enum e_error	t_error;

// gnl.c
char	*get_next_line(int fd, t_error *error_code);

// gnl_check.c
bool	is_valid_args(const int fd, t_error *error_code);
bool	is_new_line(char *str);

// gnl_utils.c
char	*ft_strjoin(char const *s1, char const *s2, t_error *error_code);
char	*ft_substr_for_gnl(\
			char const *s, unsigned int start, size_t len, t_error *error_code);
void	*ft_memmove_for_gnl(void *dst, const void *src, size_t len);

#endif
