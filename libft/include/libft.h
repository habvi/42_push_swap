#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>

bool	ft_atoi_with_bool(const char *str, int *num);
bool	ft_isdigit(int c);
size_t	ft_min(const size_t x, const size_t y);
void	ft_putstr_fd(const char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
