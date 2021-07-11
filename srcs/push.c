#include "../includes/push_swap.h"

static void	*bclst_content_copy(void *content)
{
	t_content	*p;
	t_content	*tmp;

	tmp = (t_content *)content;
	p = ft_xcalloc(sizeof(t_content));
	p->n = tmp->n;
	p->index = tmp->index;
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
	// printf("content : %d\n", ((t_content *)(*lst_a)->content)->n);
	printf("pa\n");
	ft_lst_push(lst_a, lst_b);
}

void	ft_pb(t_bclst **lst_a, t_bclst **lst_b)
{
	printf("pb\n");
	ft_lst_push(lst_b, lst_a);
}
