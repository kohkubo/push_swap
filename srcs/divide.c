#include "../includes/push_swap.h"

void	divide(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int			pivot;

	pivot = bclstsize(*lst_a) / 2;
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

void	divide_3_item(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int			len;

	len = bclstsize(*lst_a);
	while (len > 3)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index < 3)
		{
			ft_pa(lst_a, lst_b);
			len--;
			continue ;
		}
		*lst_a = (*lst_a)->next;
	}
	*lst_a = bclstfirst(*lst_a);
}
