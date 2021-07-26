#include "push_swap.h"

static void	ft_lst_rotate(t_bclst **lst)
{
	void	*p;

	p = (*lst)->content;
	(*lst)->content = (*lst)->back->content;
	(*lst)->back->content = p;
	*lst = bclstfirst(*lst);
}

void	ft_ra(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "ra\n", 3);
	ft_lst_rotate(lst_a);
	(void)lst_b;
}

void	ft_rb(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "rb\n", 3);
	(void)lst_a;
	ft_lst_rotate(lst_b);
}

void	ft_rr(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "rr\n", 3);
	ft_lst_rotate(lst_a);
	ft_lst_rotate(lst_b);
}
