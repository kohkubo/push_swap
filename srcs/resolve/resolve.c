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

void	resolve_6_item(t_bclst **lst_a, t_bclst **lst_b)
{
	int	len;

	divide_3_item(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
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


void	resolve_three(t_bclst **lst_a, t_bclst **lst_b)
{
	t_index	in;

	in.a0 = ((t_content *)((*lst_a)->content))->index;
	in.a1 = ((t_content *)((*lst_a)->next->content))->index;
	in.a2 = ((t_content *)((*lst_a)->next->next->content))->index;
	in.b0 = ((t_content *)((*lst_b)->content))->index;
	in.b1 = ((t_content *)((*lst_b)->next->content))->index;
	in.b2 = ((t_content *)((*lst_b)->next->next->content))->index;

	if (in.a0 > in.a1 && in.a1 > in.a2 && in.b0 < in.b1 && in.b1 < in.b2)
	{
		ft_ss(lst_a, lst_b);
		ft_rrr(lst_a, lst_b);
		return ;
	}
	else if ((in.a0 > in.a1 && in.a1 < in.a2 && in.a0 > in.a2) && (in.b0 < in.b1 && in.b1 > in.b2 && in.b0 < in.b2))
	{
		ft_rr(lst_a, lst_b);
		return ;
	}
	else if (((in.a0 < in.a1 && in.a1 > in.a2 && in.a0 > in.a2) && \
		((in.b0 > in.b1 && in.b1 < in.b2 && in.b0 < in.b2) || (in.b0 > in.b1 && in.b1 < in.b2))) \
		|| ((in.a0 < in.a1 && in.a1 > in.a2) && (in.b0 > in.b1 && in.b1 < in.b2 && in.b0 < in.b2)))
	{
		ft_rrr(lst_a, lst_b);
	}
	else if ((in.a0 > in.a1) && (in.a0 < in.a2) && ((in.b0 < in.b1 && in.b0 > in.b2)|| (in.b0 < in.b1 && in.b1 < in.b2)))
	{
		ft_ss(lst_a, lst_b);
	}
	else if ((in.a0 < in.a1 && in.a1 > in.a2) && (in.b0 > in.b1 && in.b1 < in.b2))
	{
		ft_rrr(lst_a, lst_b);
		ft_ss(lst_a, lst_b);
		return ;
	}
	resolve_three_desc(lst_a, lst_b);
	resolve_three_asc(lst_a, lst_b);
}



void	resolve_b(t_bclst **lst_a, t_bclst **lst_b)
{
	if (is_021(lst_a))
	{
		ft_ra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
	}
	else if (is_102(lst_a))
	{
		ft_sa(lst_a, lst_b);
	}
	else if (is_120(lst_a))
	{
		ft_ra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
	}
	else if (is_201(lst_a))
	{
		ft_sa(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
	}
	else if (is_210(lst_a))
	{
		ft_sa(lst_a, lst_b);
		ft_ra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
	}
	resolve_three_desc(lst_a, lst_b);
	pa_all(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
	ft_ra(lst_a, lst_b);
}