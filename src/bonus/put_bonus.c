#include <unistd.h>
#include "ft_dprintf.h"
#include "checker_bonus.h"

void	put_result(const char *result_message)
{
	ft_dprintf(STDOUT_FILENO, result_message);
}
