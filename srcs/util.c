#include "../includes/push_swap.h"

void	pa_all(t_bclst **lst_a, t_bclst **lst_b)
{
	while ((*lst_b)->content != NULL)
		ft_pb(lst_a, lst_b);
}