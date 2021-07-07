#include "libbclst.h"

void	bclstdelone(t_bclst *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		lst->content = NULL;
		free(lst);
	}
}
