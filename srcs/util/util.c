#include "push_swap.h"

void	pa_all(t_bclst **lst_a, t_bclst **lst_b)
{
	while ((*lst_b)->content != NULL)
		ft_pa(lst_a, lst_b);
}

bool	is_bclstsort(t_bclst *lst)
{
	int			i;
	t_content	*c;

	i = 0;
	while (lst->content != NULL)
	{
		c = (t_content *)lst->content;
		if (c->index != i)
			return (false);
		lst = lst->next;
		i++;
	}
	return (true);
}

void	valid_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnum_string(av[i]))
		{
			ft_error_exit("Error\n");
		}
		i++;
	}
}

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
		p->group = 0;
		bclstadd_last(&lst, bclstnew((void *)p));
		i++;
	}
	lst = lst->next;
	return (lst);
}
