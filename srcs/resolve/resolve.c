#include "push_swap.h"

void	refacting_resolve_three_refact(t_bclst **lst_a, t_bclst **lst_b)
{
	if (is_210(lst_a) && is_012(lst_b))
	{
		func_exec(lst_a, lst_b, ft_ss, ft_rrr);
		return ;
	}
	else if (is_201(lst_a) && is_021(lst_b))
	{
		ft_rr(lst_a, lst_b);
		return ;
	}
	else if ((is_120(lst_a) || is_021(lst_a)) && \
	(is_102(lst_b) || is_201(lst_b)))
		ft_rrr(lst_a, lst_b);
	else if ((is_102(lst_a) || is_210(lst_a)) && \
	(is_120(lst_b) || is_012(lst_b)))
		ft_ss(lst_a, lst_b);
	else if (is_021(lst_a) && is_201(lst_b))
	{
		ft_rrr(lst_a, lst_b);
		ft_ss(lst_a, lst_b);
		return ;
	}
	func_exec(lst_a, lst_b, resolve_three_desc, resolve_three_asc);
}

void	resolve_three_lst_a_no_rotate(t_bclst **lst_a, t_bclst **lst_b)
{
	if (is_021(lst_a))
	{
		func_exec(lst_a, lst_b, ft_ra, ft_sa);
		ft_rra(lst_a, lst_b);
	}
	else if (is_102(lst_a))
		ft_sa(lst_a, lst_b);
	else if (is_120(lst_a))
	{
		func_exec(lst_a, lst_b, ft_ra, ft_sa);
		func_exec(lst_a, lst_b, ft_rra, ft_sa);
	}
	else if (is_201(lst_a))
	{
		func_exec(lst_a, lst_b, ft_sa, ft_ra);
		func_exec(lst_a, lst_b, ft_sa, ft_rra);
	}
	else if (is_210(lst_a))
	{
		func_exec(lst_a, lst_b, ft_sa, ft_ra);
		func_exec(lst_a, lst_b, ft_sa, ft_rra);
		ft_sa(lst_a, lst_b);
	}
}

void	resolve_b(t_bclst **lst_a, t_bclst **lst_b)
{
	if (is_021(lst_a))
	{
		func_exec(lst_a, lst_b, ft_ra, ft_sa);
		ft_rra(lst_a, lst_b);
	}
	else if (is_102(lst_a))
		ft_sa(lst_a, lst_b);
	else if (is_120(lst_a))
	{
		func_exec(lst_a, lst_b, ft_ra, ft_sa);
		func_exec(lst_a, lst_b, ft_rra, ft_sa);
	}
	else if (is_201(lst_a))
	{
		func_exec(lst_a, lst_b, ft_sa, ft_ra);
		func_exec(lst_a, lst_b, ft_sa, ft_rra);
	}
	else if (is_210(lst_a))
	{
		func_exec(lst_a, lst_b, ft_sa, ft_ra);
		func_exec(lst_a, lst_b, ft_sa, ft_rra);
		ft_sa(lst_a, lst_b);
	}
	resolve_three_desc(lst_a, lst_b);
	pa_all_n_ra(lst_a, lst_b, 6);
}

void	resolve_6_item(t_bclst **lst_a, t_bclst **lst_b)
{
	int	len;

	divide_3_item(lst_a, lst_b);
	len = bclstsize(*lst_b);
	if (len == 1)
		resolve_three_asc(lst_a, lst_b);
	if (len == 2)
	{
		resolve_three_asc(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
	}
	else if (len == 3)
		refacting_resolve_three_refact(lst_a, lst_b);
	pa_all(lst_a, lst_b);
}

void	resolve_after(t_bclst **lst_a, t_bclst **lst_b, int asize, int bsize)
{
	if (asize == 2 && bsize == 3)
	{
		resolve_two_asc(lst_a, lst_b);
		resolve_three_desc(lst_a, lst_b);
		pa_all_n_ra(lst_a, lst_b, 5);
	}
	else if (asize == 3 && bsize == 2)
	{
		resolve_three_lst_a_no_rotate(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
		pa_all_n_ra(lst_a, lst_b, 5);
	}
	else if (asize == 2 && bsize == 2)
	{
		resolve_two_asc(lst_a, lst_b);
		resolve_two_desc(lst_a, lst_b);
		pa_all_n_ra(lst_a, lst_b, 4);
	}
	else if (asize == 3 && bsize == 3)
		resolve_b(lst_a, lst_b);
	else
	{
		resolve_three_desc(lst_a, lst_b);
		pa_all_n_ra(lst_a, lst_b, 3);
	}
}
