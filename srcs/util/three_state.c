#include "push_swap.h"

void	lst_index(t_bclst **lst, int *i0, int *i1, int *i2)
{
	*i0 = ((t_content *)((*lst)->content))->index;
	*i1 = ((t_content *)((*lst)->next->content))->index;
	*i2 = ((t_content *)((*lst)->next->next->content))->index;
}

bool	is_012(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 < i1 && i1 < i2 && i0 < i2);
}

bool	is_021(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 < i1 && i1 > i2 && i0 < i2);
}

bool	is_102(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 > i1 && i1 < i2 && i0 < i2);
}

bool	is_120(t_bclst	**lst)
{
	int	i0;
	int	i1;
	int	i2;

	lst_index(lst, &i0, &i1, &i2);
	return (i0 < i1 && i1 > i2 && i0 > i2);
}

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
