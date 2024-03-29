#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>

ssize_t	ft_abs(ssize_t x);
bool	ft_atoi_for_pushswap(const char *str, int *num);
bool	ft_isdigit(int c);
size_t	ft_max(size_t x, size_t y);
size_t	ft_min(size_t x, size_t y);
void	ft_putstr_fd(const char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int int_c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);

#endif
