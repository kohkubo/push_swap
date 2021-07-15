#include "push_swap.h"

bool	ft_isnum(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (false);
	return (true);
}
