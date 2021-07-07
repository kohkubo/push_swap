#include "libbclst.h"

void	bclstiter(t_bclst *lst, void (*f)(void *))
{
	t_bclst *tmp;

	if (!lst || !f)
		return ;
	tmp = bclstsentry(lst);
	tmp = tmp->next;
	while (tmp->content != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
