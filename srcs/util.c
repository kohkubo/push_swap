#include "../includes/push_swap.h"

static t_bclst	*ps_lst(int ac, char **av)
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

static void	store_lst_index(t_bclst *lst, int *arr_sorted, int len)
{
	int	i;
	t_bclst *tmp;
	t_content *p;

	tmp = bclstfirst(lst);
	while (tmp->content != NULL)
	{
		p = (t_content *)tmp->content;
		i = 0;
		while (i < len)
		{
			if (arr_sorted[i] == p->n)
			{
				p->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static t_bclst	*index_lst(int ac, char **av)
{
	int	*sorted_arr;
	t_bclst	*lst;

	lst = ps_lst(ac, av);
	sorted_arr = ft_sort_arr(ac, av);
	store_lst_index(lst, sorted_arr, ac - 1);
	return (lst);
}

void	ps_constructor(int ac, char **av, t_bclst **lst_a, t_bclst **lst_b)
{
	valid_args(ac, av);
	*lst_a = index_lst(ac, av);
	*lst_b = bclstnull();
}

void	ps_destructor(t_bclst **lst_a, t_bclst **lst_b)
{
	bclstclear(lst_a, free);
	bclstclear(lst_b, free);
}
