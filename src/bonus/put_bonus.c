#include <unistd.h>
#include "ft_dprintf.h"
#include "checker_bonus.h"

void	put_result(t_result result)
{
	if (result == OK)
		ft_dprintf(STDOUT_FILENO, "OK\n");
	else if (result == KO)
		ft_dprintf(STDOUT_FILENO, "KO\n");
}
