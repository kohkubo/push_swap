#include "push_swap.h"

static void	*bclst_content_copy(void *content)
{
	t_content	*p;
	t_content	*tmp;

	tmp = (t_content *)content;
	p = ft_xcalloc(sizeof(t_content));
	p->n = tmp->n;
	p->index = tmp->index;
	p->group = tmp->group;
	p->gcount = tmp->gcount;
	return ((void *)p);
}

static void	ft_lst_push(t_bclst **out, t_bclst **in)
{
	void	*con;
	t_bclst	*tmp;

	con = bclst_content_copy((*out)->content);
	tmp = (*out)->next;
	bclstdelone(*out, free);
	*out = bclstfirst(tmp);
	bclstadd_first(in, bclstnew(con));
	*in = bclstfirst(*in);
}

void	ft_pa(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "pa\n", 3);
	ft_lst_push(lst_b, lst_a);
}

void	ft_pb(t_bclst **lst_a, t_bclst **lst_b)
{
	write(1, "pb\n", 3);
	ft_lst_push(lst_a, lst_b);
}
