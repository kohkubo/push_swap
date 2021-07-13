#include "../includes/push_swap.h"

void	check_sort(t_bclst *lst, int *arr_sorted)
{
	t_bclst *tmp;
	t_content *p;

	tmp = bclstfirst(lst);
	while (tmp->content != NULL)
	{
		p = (t_content *)tmp->content;
		if (p->n != *arr_sorted++)
			ft_fatal(BOLDRED"this lst is not sorted!!"RESET);
		tmp = tmp->next;
	}
	printf(BOLDGREEN"OK! this lst is sorted!!\n"RESET);
}

void	ps_destructor(t_bclst **lst_a, t_bclst **lst_b, int *ans_arr)
{
#ifdef DEBUG
	check_sort(*lst_a, ans_arr);
#endif
	free(ans_arr);
	bclstclear(lst_a, free);
	bclstclear(lst_b, free);
}