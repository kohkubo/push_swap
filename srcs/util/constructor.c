#include "push_swap.h"

static void	store_lst_index(t_bclst *lst, int *arr_sorted, int len)
{
	int			i;
	t_bclst		*tmp;
	t_content	*p;

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
		p->group = 0;
		bclstadd_last(&lst, bclstnew((void *)p));
		i++;
	}
	lst = lst->next;
	return (lst);
}

static bool	is_arr_duplicate(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (true);
		i++;
	}
	return (false);
}

static t_bclst	*index_lst(int ac, char **av, int *ans_arr)
{
	t_bclst	*lst;

	lst = ps_lst(ac, av);
	store_lst_index(lst, ans_arr, ac - 1);
	return (lst);
}

int	*ps_constructor(int ac, char **av, t_bclst **lst_a, t_bclst **lst_b)
{
	int	*ans_arr;

	valid_args(ac, av);
	ans_arr = ft_sort_arr(ac, av);
	if (is_arr_duplicate(ans_arr, ac - 2))
		ft_error_exit("Error\n");
	*lst_a = index_lst(ac, av, ans_arr);
	*lst_b = bclstnull();
	return (ans_arr);
}
