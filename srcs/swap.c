#include "../includes/push_swap.h"

static void	ft_lst_swap(t_bclst *lst)
{
	void	*p;

	p = lst->content;
	lst->content = lst->next->content;
	lst->next->content = p;
}

void	ft_sa(t_bclst **lst_a, t_bclst **lst_b)
{
	ft_lst_swap(*lst_a);
	(void)lst_b;
}

void	ft_sb(t_bclst **lst_a, t_bclst **lst_b)
{
	(void)lst_a;
	ft_lst_swap(*lst_b);
}

void	ft_ss(t_bclst **lst_a, t_bclst **lst_b)
{
	ft_lst_swap(*lst_a);
	ft_lst_swap(*lst_b);
}
