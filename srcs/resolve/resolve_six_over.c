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
	t_content	*c_a, *c_b;

	divide_a(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	divide_b(lst_a, lst_b, bclstsize(*lst_b) / 2, 2);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	c_a = (t_content *)(*lst_a)->content;
	c_b = (t_content *)(*lst_b)->content;
	if (c_a->gcount == 2 && c_b->gcount == 3)
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
	if (c_a->gcount == 3 && c_b->gcount == 3)
	{
		resolve_b(lst_a, lst_b);
	}
	c_a = (t_content *)(*lst_a)->content;
	if (c_a->group != 0)
	{

	}
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
}
