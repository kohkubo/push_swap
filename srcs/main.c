#include "../includes/push_swap.h"

t_bclst	*ps_lst(int ac, char **av)
{
	t_bclst		*lst;
	t_content	*p;
	int			i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		p = ft_xcalloc(sizeof(t_content));
		p->n = ft_atoi(av[i]);
		p->index = 0;
		bclstadd_last(&lst, bclstnew((void *)p));
		i++;
	}
	lst = lst->next;
	return (lst);
}

void	divide(t_bclst **lst_a, t_bclst **lst_b, int pivot)
{
	t_content	*c;
	t_bclst		*tmp;

	tmp = *lst_a;
	while (tmp->content != NULL)
	{
		c = (t_content *)(tmp->content);
		// ft_pa(&tmp, lst_b);
		if (c->index < pivot)
		{
			ft_pa(&tmp, lst_b);
			continue ;
		}
		tmp = tmp->next;
	}
}

void	ps_do(t_bclst **lst_a, t_bclst **lst_b)
{
	// divide(lst_a, lst_b, bclstsize(*lst_a) / 2);

	printf("=================\n");
	ps_print(*lst_a, *lst_b);
	// bclstiter(*lst_a, print_content2);
	// printf("=↑a===↓b================\n");
	// bclstiter(*lst_b, print_content2);

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
