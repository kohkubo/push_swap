#include "push_swap.h"

void	pa_all(t_bclst **lst_a, t_bclst **lst_b)
{
	while ((*lst_b)->content != NULL)
		ft_pa(lst_a, lst_b);
}

void	lst_a_group_max_min(t_bclst *lst, int *max, int *min)
{
	int			group;
	t_content	*ac;

	group = ((t_content *)lst->content)->group;
	*min = INT_MAX;
	*max = INT_MIN;
	while (1)
	{
		ac = (t_content *)lst->content;
		if (ac->group != group)
			break ;
		if (*min > ac->index)
			*min = ac->index;
		if (*max < ac->index)
			*max = ac->index;
		lst = lst->next;
	}
}

bool	is_bclstsort(t_bclst *lst)
{
	int	i;
	t_content	*c;

	i = 0;
	while (lst->content != NULL)
	{
		c = (t_content *)lst->content;
		// printf("c->index : %d\n", c->index);
		if (c->index != i)
			return (false);
		lst = lst->next;
		i++;
	}
	return (true);
}