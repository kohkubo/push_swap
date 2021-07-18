#include "push_swap.h"

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

int	divide_b(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
{
	t_content	*c;
	int			len;
	int			bsize;
	int			asize;

	len = bclstsize(*lst_b);
	bsize = (len + 2 - 1) / 2;
	asize = len / 2;
	while (len--)
	{
		c = (t_content *)((*lst_b)->content);
		if (c->index <= pivot)
		{
			c->gcount = asize;
			ft_rb(lst_a, lst_b);
			continue ;
		}
		c->group = group;
		c->gcount = bsize;
		ft_pa(lst_a, lst_b);
	}
	return (bclstsize(*lst_b));
}

int	divide_loop(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
{
	t_content	*bc;
	int			bsize;

	divide_a_push(lst_a, lst_b, pivot, group++);
	bc = (t_content *)(*lst_b)->content;
	bsize = bc->gcount;
	while (bsize >= 4)
	{
		bc = (t_content *)(*lst_b)->content;
		bsize = bc->gcount;
		pivot = (pivot - bc->gcount + 1) + bc->gcount / 2 - 1;
		bsize = divide_b(lst_a, lst_b, pivot, ++group);
	}
	return (bclstsize(*lst_b));
}
