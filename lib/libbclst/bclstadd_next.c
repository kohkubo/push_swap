#include "libbclst.h"

void	bclstadd_next(t_bclst **lst, t_bclst *newlst)
{
	t_bclst	*sentry;

	if (!lst || !newlst)
		return ;
	if (*lst)
	{
		sentry = bclstsentry(*lst);
		bclstinsert_next(sentry, newlst);
	}
	else
		*lst = bclstinit(newlst);

}
