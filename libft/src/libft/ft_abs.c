#include "libft.h"

ssize_t	ft_abs(ssize_t x)
{
	if (x < 0)
		return (-x);
	return (x);
}
