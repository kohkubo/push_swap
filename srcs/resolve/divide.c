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
		ft_ra(lst_a, lst_b);
	}
}

void	divide_a(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int			pivot;
	int			len;
	int			count;

	len = bclstsize(*lst_a);
	pivot = len / 2;
	count = len;
	while (len--)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index < pivot)
		{
			c->gcount = count / 2;
			ft_pb(lst_a, lst_b);
			continue ;
		}
		c->group = 1;
		c->gcount = (count + 2 - 1) / 2;
		ft_ra(lst_a, lst_b);
	}
}

int	divide_b(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
{
	t_content	*c;
	int			len;
	int			count;

	if (pivot <= 0)
		return 0;
	len = bclstsize(*lst_b);
	count = len;
	while (len--)
	{
		c = (t_content *)((*lst_b)->content);
		if (c->index <= pivot)
		{
			c->gcount = (count + 2 - 1) / 2;
			ft_rb(lst_a, lst_b);
			continue ;
		}
		c->group = group;
		c->gcount = count / 2;
		ft_pa(lst_a, lst_b);
	}
	t_bclst *tmp;

	tmp = *lst_b;
	int bsize = bclstsize(*lst_b);
	printf("bsize : %d\n", bsize);
	while (tmp->content != NULL)
	{
		((t_content *)(tmp->content))->gcount = bsize;
		tmp = tmp->next;
	}
	return (bclstsize(*lst_b));
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
}
