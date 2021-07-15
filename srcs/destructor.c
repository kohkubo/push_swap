#include "push_swap.h"

bool	is_lstsort(t_bclst *lst, int *arr_sorted)
{
	t_content	*p;


	while (lst->content != NULL)
	{
		p = (t_content *)lst->content;
		if (p->n != *arr_sorted++)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	check_sort(t_bclst *lst, int *arr_sorted)
{
	if (!is_lstsort(lst, arr_sorted))
		ft_fatal(BOLDRED"this lst is not sorted!!"RESET);
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