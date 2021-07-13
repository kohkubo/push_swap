#include "../includes/push_swap.h"

void	resolve_6_item(t_bclst **lst_a, t_bclst **lst_b)
{
	int	len;

	divide_3_item(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
#endif
	resolve_three_asc(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
	printf("-------------------\n");
#endif
	len = bclstsize(*lst_b);
	if (len == 2)
		resolve_two_desc(lst_a, lst_b);
	else if (len == 3)
		resolve_three_desc(lst_a, lst_b);
	pa_all(lst_a, lst_b);
#ifdef DEBUG
	ps_print(*lst_a, *lst_b);
#endif
}
