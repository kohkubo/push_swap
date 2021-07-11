#include "../includes/push_swap.h"

void	resolve_only_push(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int	max;
	int	i;

	i = 0;
	max = bclstsize(*lst_a);
	while (i < max)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index == i)
		{
			ft_pa(lst_a, lst_b);
			i++;
			continue ;
		}
		if ((*lst_a)->next->content == NULL)
			*lst_a = (*lst_a)->next->next;
		else
			*lst_a = (*lst_a)->next;
	}
	while ((*lst_b)->content != NULL)
	{
		ft_pb(lst_a, lst_b);
	}
}

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