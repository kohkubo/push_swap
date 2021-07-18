#include "push_swap.h"

void	pa_all_n_ra(t_bclst **lst_a, t_bclst **lst_b, int n)
{
	pa_all(lst_a, lst_b);
	while (n-- > 0)
		ft_ra(lst_a, lst_b);
}

void	func_exec(t_bclst **lst_a, t_bclst **lst_b, \
void(f1)(t_bclst **, t_bclst **), void(f2)(t_bclst **, t_bclst **))
{
	f1(lst_a, lst_b);
	f2(lst_a, lst_b);
}
