#include "push_swap.h"

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
			ft_pb(lst_a, lst_b);
			continue ;
		}
		*lst_a = (*lst_a)->next;
	}
	*lst_a = bclstfirst(*lst_a);

void	divide_a(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int			pivot;
	int			len;

	len = bclstsize(*lst_a);
	pivot = len / 2;
	while (len--)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index < pivot)
		{
			ft_pb(lst_a, lst_b);
			continue ;
		}
		ft_ra(lst_a, lst_b);
	}
}

void	divide_b(t_bclst **lst_a, t_bclst **lst_b, int pivot)
{
	t_content	*c;
	int			len;

	if (pivot <= 0)
		return ;
	len = pivot--;
	while (len)
	{
		c = (t_content *)((*lst_b)->content);
		if (c->index > pivot)
		{
			ft_pa(lst_a, lst_b);
			len--;
			continue ;
		}
		ft_rb(lst_a, lst_b);
	}
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	divide_b(lst_a, lst_b, ++pivot / 2);
}

void	divide_3_item(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int			len;
	int			index;

	len = bclstsize(*lst_a);
	index = len - 3;
	while (len > 3)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index < index)
		{
			ft_pb(lst_a, lst_b);
			len--;
			continue ;
		}
		ft_ra(lst_a, lst_b);
	}
	*lst_a = bclstfirst(*lst_a);
}
