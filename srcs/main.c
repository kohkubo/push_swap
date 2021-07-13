#include "../includes/push_swap.h"

void	ps_do(t_bclst **lst_a, t_bclst **lst_b)
{
	int	len;

	len = bclstsize(*lst_a);
	if (len == 2)
		resolve_two_asc(lst_a, lst_b);
	else if (len == 3)
		resolve_three_asc(lst_a, lst_b);
	else if (len < 7)
		resolve_6_item(lst_a, lst_b);
	// ps_print(*lst_a, *lst_b);
}

void	push_swap(int ac, char **av)
{
	t_bclst	*lst_a;
	t_bclst	*lst_b;
	int		*ans_arr;

	display_array(&av[1]);
	ans_arr = ps_constructor(ac, av, &lst_a, &lst_b);
	ps_do(&lst_a, &lst_b);
	ps_destructor(&lst_a, &lst_b, ans_arr);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}
