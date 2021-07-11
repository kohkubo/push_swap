#include "../includes/push_swap.h"

void	ps_do(t_bclst **lst_a, t_bclst **lst_b)
{
	// divide(lst_a, lst_b, bclstsize(*lst_a) / 2);
	// resolve_only_push(lst_a, lst_b);

	ps_print(*lst_a, *lst_b);
}

void	push_swap(int ac, char **av)
{
	t_bclst	*lst_a;
	t_bclst	*lst_b;

	ps_constructor(ac, av, &lst_a, &lst_b);
	ps_do(&lst_a, &lst_b);
	ps_destructor(&lst_a, &lst_b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}
