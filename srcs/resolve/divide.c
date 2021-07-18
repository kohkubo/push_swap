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

	len = bclstsize(*lst_b);
	count = len;
	int bsize = (count + 2 - 1) / 2;
	int asize = count / 2;
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

void	divide_a_push(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group, int count)
{
	t_content	*c;
	int asize = (count + 2 - 1) / 2;
	int bsize = count / 2;

	while (1)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->group != group)
			break;
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
	{
		ft_rra(lst_a, lst_b);
	}
}
int	divide_loop(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group, int count)
{
	divide_a_push(lst_a, lst_b, pivot, group++, count);
#ifdef DEBUG
	printf("pivot : %d\n", pivot);
	printf("divide_a_push in divide_loop end\n");
	ps_print(*lst_a, *lst_b);
#endif
	t_content	*bc = (t_content *)(*lst_b)->content;
	int bsize = bc->gcount;
	while (bsize >= 4)
	{
		bc = (t_content *)(*lst_b)->content;
		bsize = bc->gcount;
		pivot = (pivot - bc->gcount + 1) + bc->gcount / 2 - 1;
		// printf("pivot : %d\n", pivot);
		bsize = divide_b(lst_a, lst_b, pivot, ++group);
#ifdef DEBUG
	printf("divide_b in divide_loop end\n");
	ps_print(*lst_a, *lst_b);
#endif
	}
	return (bclstsize(*lst_b));
}


int	divide_b_push(t_bclst **lst_a, t_bclst **lst_b, int pivot, int group)
{
	t_content	*c;
	int			len;
	int			count;

	len = bclstsize(*lst_b);
	count = len;
	int bsize = (count + 2 - 1) / 2;
	int asize = count / 2;
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