#include "push_swap.h"

void	resolve_over_six_2(t_bclst **lst_a, t_bclst **lst_b)
{
	int			len;
	t_content	*c_a;
	t_content	*c_b;

	c_a = (t_content *)(*lst_a)->content;
	c_b = (t_content *)(*lst_b)->content;
	if (c_a->gcount == 2)
		resolve_two_asc(lst_a, lst_b);
	if (c_b->gcount == 2)
		resolve_two_desc(lst_a, lst_b);
	len = bclstsize(*lst_b);
	if (len == 1)
		resolve_three_asc(lst_a, lst_b);
	else if (len == 2)
	{
		resolve_three_asc(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
	}
	else if (len == 3)
		refacting_resolve_three_refact(lst_a, lst_b);
	pa_all(lst_a, lst_b);
}

void	resolve_over_six(t_bclst **lst_a, t_bclst **lst_b)
{
	int			bsize;
	int			group;
	t_content	*ac;
	int			gmin;
	int			pivot;

	divide_a(lst_a, lst_b);
	group = 1;
	bsize = bclstsize(*lst_b);
	while (bsize >= 4)
		bsize = divide_b(lst_a, lst_b, bclstsize(*lst_b) / 2 - 1, ++group);
	while (((t_content *)(*lst_a)->content)->group != 0)
	{
		resolve_after(lst_a, lst_b, ((t_content *)(*lst_a)->content)->gcount, \
			((t_content *)(*lst_b)->content)->gcount);
		if (is_bclstsort(*lst_a))
			break ;
		ac = (t_content *)(*lst_a)->content;
		gmin = ((t_content *)(*lst_a)->back->back->content)->index + 1;
		pivot = gmin + ac->gcount / 2 - 1;
		divide_loop(lst_a, lst_b, pivot, ac->group);
	}
}
