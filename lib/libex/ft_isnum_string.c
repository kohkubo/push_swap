#include "libex.h"

bool	ft_isnum_string(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
		if (!ft_isdigit(*s++))
			return (false);
	return (true);
}
