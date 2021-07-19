#include "push_swap.h"

bool	is_201(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 > i1 && i1 < i2 && i0 > i2);
}

bool	is_210(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 > i1 && i1 > i2 && i0 > i2);
}
