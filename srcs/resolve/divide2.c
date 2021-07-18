#include "push_swap.h"

int	divide_b_push(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
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

void	divide_a_push(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
{
	t_content	*c;
	int			count;
	int			asize;
	int			bsize;

	count = ((t_content *)(*lst_a)->content)->gcount;
	asize = (count + 2 - 1) / 2;
	bsize = count / 2;
	while (1)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->group != group)
			break ;
		if (c->index <= pivot)
		{
			c->gcount = bsize;
			ft_pb(lst_a, lst_b);
			continue ;
		}
		c->group = group + 1;
		c->gcount = asize;
		ft_ra(lst_a, lst_b);
	}
	while (asize--)
		ft_rra(lst_a, lst_b);
}
