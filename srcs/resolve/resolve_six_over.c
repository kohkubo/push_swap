#include "push_swap.h"

void	resolve_over_six_2(t_bclst **lst_a, t_bclst **lst_b)
{
	int	len;
	t_content	*c_a, *c_b;

	c_a = (t_content *)(*lst_a)->content;
	c_b = (t_content *)(*lst_b)->content;
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	if (c_a->gcount == 2)
	{
		resolve_two_asc(lst_a, lst_b);
	}
	if (c_b->gcount == 2)
	{
		resolve_two_desc(lst_a, lst_b);
	}
	if (c_a->gcount == 3)
	{

	}
	len = bclstsize(*lst_b);
	if (len == 1)
	{
		resolve_three_asc(lst_a, lst_b);
	}
	if (len == 2)
	{
		resolve_three_asc(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
	}
	else if (len == 3)
		resolve_three(lst_a, lst_b);
	pa_all(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
#endif
}

void	resolve_over_six(t_bclst **lst_a, t_bclst **lst_b)
{
	// 半分に
	divide_a(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	// 再起でbを半分にしていく
	int bsize = bclstsize(*lst_b);
	int group = 1;
	while (bsize >= 4)
	{
		printf("bsize : %d\n", bsize);
		bsize = divide_b(lst_a, lst_b, bclstsize(*lst_b) / 2 - 1, ++group);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	}

	int asize = ((t_content *)(*lst_a)->content)->gcount;
	if (asize == 2 && bsize == 3)
	{
		resolve_two_asc(lst_a, lst_b);
		resolve_three_desc(lst_a, lst_b);
		pa_all(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
	}
	else if (asize == 2 && bsize == 2)
	{
		resolve_two_asc(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
		pa_all(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
	}
	else if (asize == 3 && bsize == 3)
	{
		resolve_b(lst_a, lst_b);
	}
	else
	{
		resolve_three_desc(lst_a, lst_b);
		pa_all(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
	}
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
}
