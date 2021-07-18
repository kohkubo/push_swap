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
		resolve_two_asc(lst_a, lst_b);
	if (c_b->gcount == 2)
		resolve_two_desc(lst_a, lst_b);
	len = bclstsize(*lst_b);
	if (len == 1)
		resolve_three_asc(lst_a, lst_b);
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
	int bsize;
	int group;

	divide_a(lst_a, lst_b);
#ifdef DEBUG
	printf("divide_a end\n");
	ps_print(*lst_a, *lst_b);
#endif
	group = 1;
	bsize = bclstsize(*lst_b);
	while (bsize >= 4)
	{
		bsize = divide_b(lst_a, lst_b, bclstsize(*lst_b) / 2 - 1, ++group);
#ifdef DEBUG
	printf("divide_b end\n");
	ps_print(*lst_a, *lst_b);
#endif
	}
	while (((t_content *)(*lst_a)->content)->group != 0)
	{
		resolve_six_over_loop_after(lst_a, lst_b, ((t_content *)(*lst_a)->content)->gcount, ((t_content *)(*lst_b)->content)->gcount);
	#ifdef DEBUG
		printf("resolve_six_over_loop_after end\n");
		ps_print(*lst_a, *lst_b);
	#endif
		if (is_bclstsort(*lst_a))
			break;
		t_content	*ac = (t_content *)(*lst_a)->content;
		int	gmin = ((t_content *)(*lst_a)->back->back->content)->index + 1;
		int	pivot = gmin + ac->gcount / 2 - 1;
		divide_loop(lst_a, lst_b, pivot, ac->group, ac->gcount);
	#ifdef DEBUG
		printf("divide_loop\n");
		ps_print(*lst_a, *lst_b);
	#endif
	}
}
