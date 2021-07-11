#include "../includes/push_swap.h"

void	divide(t_bclst **lst_a, t_bclst **lst_b, int pivot)
{
	t_content	*c;

	printf("pivot : %d\n", pivot);
	while ((*lst_a)->content != NULL)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index < pivot)
		{
			ft_pa(lst_a, lst_b);
			continue ;
		}
		*lst_a = (*lst_a)->next;
	}
	*lst_a = bclstfirst(*lst_a);
}

void	ps_do(t_bclst **lst_a, t_bclst **lst_b)
{
	divide(lst_a, lst_b, bclstsize(*lst_a) / 2);

	printf("=================\n");
	ps_print(*lst_a, *lst_b);
	printf("=================\n");
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
