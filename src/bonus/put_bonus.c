#include <unistd.h>
#include "ft_dprintf.h"
#include "checker_bonus.h"
#include "error.h"

void	put_result(t_result result)
{
	if (result == OK)
		ft_dprintf(STDOUT_FILENO, OK_MSG);
	else if (result == KO)
		ft_dprintf(STDOUT_FILENO, KO_MSG);
	else
		ft_dprintf(STDERR_FILENO, ERROR_MSG);
}
