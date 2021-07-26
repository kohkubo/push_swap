#include "libex.h"

void	ft_error_exit(const char *emsg)
{
	ft_putstr_fd((char *)emsg, 2);
	exit(1);
}
