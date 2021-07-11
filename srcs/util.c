#include "../includes/push_swap.h"

void	take_index(t_bclst *lst, int *arr, int len)
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
			if (arr[i] == p->n)
			{
				p->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ps_constructor(int ac, char **av, t_bclst **lst_a, t_bclst **lst_b)
{
	valid_args(ac, av);
	*lst_a = ps_lst(ac, av);
	*lst_b = bclstnull();
}

void	ps_destructor(t_bclst **lst_a, t_bclst **lst_b)
{
	bclstclear(lst_a, free);
	bclstclear(lst_b, free);
}
