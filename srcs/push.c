#include "../includes/push_swap.h"

static t_content	*bclst_content_copy(void *content)
{
	t_content	*p;
	t_content	*tmp;

	tmp = (t_content *)content;
	p = ft_xcalloc(sizeof(t_content));
	p->n = tmp->n;
	p->index = tmp->index;
	return (p);
}

static void	ft_lst_push(t_bclst **out, t_bclst **in)
{
	void	*tmp;

	tmp = bclst_content_copy((*out)->content);
	bclstdelone(*out, free);
	bclstadd_first(in, bclstnew(tmp));
	*out = bclstfirst(*out);
	*in = bclstfirst(*in);
}

void	ft_pa(t_bclst **lst_a, t_bclst **lst_b)
{
	ft_lst_push(lst_a, lst_b);
}

void	ft_pb(t_bclst **lst_a, t_bclst **lst_b)
{
	ft_lst_push(lst_b, lst_a);
}
