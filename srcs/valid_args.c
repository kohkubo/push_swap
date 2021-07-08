#include "../includes/push_swap.h"

void	valid_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnum(av[i]))
			ft_error_exit("Error");
		i++;
	}
}