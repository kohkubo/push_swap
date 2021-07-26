#include "push_swap.h"

static void	ft_lst_reverse_rotate(t_bclst **lst)
{
	void	*p;

	p = (*lst)->back->back->content;
	(*lst)->back->back->content = (*lst)->back->content;
	(*lst)->back->content = p;
	*lst = bclstfirst(*lst);
}

void	ft_rra(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "rra\n", 4);
	ft_lst_reverse_rotate(lst_a);
	(void)lst_b;
}

void	ft_rrb(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1,"rrb\n", 4);
	(void)lst_a;
	ft_lst_reverse_rotate(lst_b);
}

void	ft_rrr(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "rrr\n", 4);
	ft_lst_reverse_rotate(lst_a);
	ft_lst_reverse_rotate(lst_b);
}
