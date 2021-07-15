#include "push_swap.h"

void	resolve_two_asc(t_bclst **lst_a, t_bclst **lst_b)
{
	t_index	in;

	in.a0 = ((t_content *)((*lst_a)->content))->index;
	in.a1 = ((t_content *)((*lst_a)->next->content))->index;
	if (in.a0 > in.a1)
		ft_sa(lst_a, lst_b);
}

void	resolve_three_asc(t_bclst **lst_a, t_bclst **lst_b)
{
	t_index	in;

	in.a0 = ((t_content *)((*lst_a)->content))->index;
	in.a1 = ((t_content *)((*lst_a)->next->content))->index;
	in.a2 = ((t_content *)((*lst_a)->next->next->content))->index;
	if (in.a0 > in.a1 && in.a1 > in.a2)
	{
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
	}
	else if (in.a0 > in.a1 && in.a1 < in.a2 && in.a0 > in.a2)
		ft_ra(lst_a, lst_b);
	else if (in.a0 < in.a1 && in.a1 > in.a2 && in.a0 > in.a2)
		ft_rra(lst_a, lst_b);
	else if (in.a0 > in.a1)
		ft_sa(lst_a, lst_b);
	else if (in.a0 < in.a1 && in.a1 > in.a2)
	{
		ft_rra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
	}
}
